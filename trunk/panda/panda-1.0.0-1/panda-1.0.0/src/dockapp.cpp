////////////////////////////////////////
//  File      : dockapp.cpp           //
//  Written by: zv.zorro@gmail.com  //
//  Copyright : GPL                   //
////////////////////////////////////////

#include "dockapp.h"

////////////////////////////////////////

Dockapp::Dockapp(const QString &app_nm, const QString &app_exe, const QString &app_pix, QWidget *parent) : QLabel(parent)
{
    read_settings();
    app_name = app_nm;
    app_exec = app_exe;
    setToolTip(app_name);
    d_app_pix = app_pix;
    setPixmap(QPixmap(d_app_pix).scaled(dock_height-10, dock_height-10, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    show();
}

Dockapp::~Dockapp()
{
    delete appsettings;
}

void Dockapp::read_settings()
{
    // get style path
    appsettings = new QSettings(QCoreApplication::applicationDirPath() + "/panda.cfg", QSettings::IniFormat, this);
    appsettings->beginGroup("Style");
    QString stl_name = appsettings->value("name").toString();
    QString stl_path = appsettings->value("path").toString();
    appsettings->endGroup(); //Style
    // get style values
    QSettings *style = new QSettings(stl_path + stl_name, QSettings::IniFormat,this);
    style->beginGroup("Dockbar");
    dock_height = style->value("dock_height").toInt();
    style->endGroup(); //Dockbar
    style->beginGroup("Other");
    delete_link_pix = stl_path + style->value("delete_link_pix").toString();
    style->endGroup(); //Other
}

void Dockapp::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QProcess::startDetached(app_exec + app_name); //launch the application
    }
    
    if (event->button() == Qt::RightButton)
    {
        menu = new QMenu(this);
        QAction *del_app = menu->addAction(QIcon(delete_link_pix), tr("Delete link"));
        menu->popup(event->globalPos());
        connect(del_app, SIGNAL(triggered()), this, SLOT(del_app()));
    }
}

void Dockapp::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    setPixmap(QPixmap(d_app_pix).scaled(dock_height-5, dock_height-5, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    update();
}

void Dockapp::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    setPixmap(QPixmap(d_app_pix).scaled(dock_height-10, dock_height-10, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    update();
}

void Dockapp::del_app()
{
    emit destroy_dockapp(this);
    // remove the Dockapp from Dockbar and from Antico.conf
    appsettings->beginGroup("Dockbar");
    appsettings->beginGroup("App");
    appsettings->remove(app_name);
    appsettings->endGroup(); // App
    appsettings->endGroup(); // Dockbar
}

void Dockapp::update_style()
{
    read_settings();
    setPixmap(QPixmap(d_app_pix).scaled(dock_height-10, dock_height-10, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    update();
}

