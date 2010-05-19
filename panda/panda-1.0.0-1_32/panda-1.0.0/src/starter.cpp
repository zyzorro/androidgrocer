////////////////////////////////////////
//  File      : starter.cpp             //
//  Written by: zv.zorro@gmail.com  //
//  Copyright : GPL                   //
////////////////////////////////////////

#include "starter.h"

////////////////////////////////////////

Starter::Starter(QWidget *parent) : QWidget(parent)
{
    read_settings();
    init();
    show();
}

Starter::~Starter()
{
    delete appsettings;
}

void Starter::init()
{
    setFixedSize(100, 50);
    pix = QPixmap(starter_pix); // set default pixmap
    zoom = false;
    starter_dlg = new StarterDialog(this); // create the Trashdialog
}

void Starter::read_settings()
{
    // get style path
    appsettings = new QSettings(QCoreApplication::applicationDirPath() + "/panda.cfg", QSettings::IniFormat, this);
    appsettings->beginGroup("Style");
    stl_name = appsettings->value("name").toString();
    stl_path = appsettings->value("path").toString();
    appsettings->endGroup(); //Style
    // get style values
    QSettings *style = new QSettings(stl_path + stl_name, QSettings::IniFormat, this);
    style->beginGroup("Starter");
    starter_pix = stl_path + style->value("starter_pix").toString();
    starter_col = style->value("name_color").value<QColor>();
    style->endGroup();
}

void Starter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setWindow(-50, -50, 100, 50);
    painter.setOpacity(0.5);
    painter.setPen(Qt::black);
    painter.drawText(-49, -14, 100, 20, Qt::AlignHCenter, tr("Starter")); // shadow Starter name
    painter.setOpacity(1);
    painter.setPen(starter_col);
    painter.drawText(-50, -15, 100, 20, Qt::AlignHCenter, tr("Starter")); // Starter name
    
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    
    if (zoom)
    {
        painter.drawPixmap(QRect(-18, -50, 36, 36), pix, QRect(0, 0, pix.width(), pix.height()));// Starter pix
    }
    else
    {
        painter.drawPixmap(QRect(-16, -50, 32, 32), pix, QRect(0, 0, pix.width(), pix.height()));// Starter pix
    }
}

void Starter::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        mousepos = event->pos();
        grabMouse(QCursor(Qt::SizeAllCursor));
    }
}

void Starter::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p = event->globalPos()-mousepos;
    move(p.x(), p.y());
}

void Starter::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    releaseMouse();
    // save new Trash position on desk writing on panda.cfg
    appsettings->beginGroup("Starter");
    appsettings->setValue("pos", pos());
    appsettings->endGroup(); // Starter
}

void Starter::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        starter_dlg->update();
        starter_dlg->exec();
    }
}

void Starter::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    zoom = true;
    update();
    
    setToolTip(tr("Start a new session"));
}

void Starter::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    zoom = false;
    update();
}

void Starter::update_style()
{
    read_settings();
    init();
    update();
}


Ender::Ender(QWidget *parent) : QWidget(parent)
{
    Desk * pdesk =  static_cast<Desk *>(parent);
    myApp = pdesk-> getapp();

    read_settings();
    init();
    show();
}

Ender::~Ender()
{
    delete appsettings;
}

void Ender::init()
{
    setFixedSize(100, 50);
    pix = QPixmap(ender_pix); // set default pixmap
    zoom = false;

}

void Ender::read_settings()
{
    // get style path
    appsettings = new QSettings(QCoreApplication::applicationDirPath() + "/panda.cfg", QSettings::IniFormat, this);
    appsettings->beginGroup("Style");
    stl_name = appsettings->value("name").toString();
    stl_path = appsettings->value("path").toString();
    appsettings->endGroup(); //Style
    // get style values
    QSettings *style = new QSettings(stl_path + stl_name, QSettings::IniFormat, this);
    style->beginGroup("Ender");
    ender_pix = stl_path + style->value("ender_pix").toString();
    ender_col = style->value("name_color").value<QColor>();
    style->endGroup();
}

void Ender::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setWindow(-50, -50, 100, 50);
    painter.setOpacity(0.5);
    painter.setPen(Qt::black);
    painter.drawText(-49, -14, 100, 20, Qt::AlignHCenter, tr("Reboot")); //
    painter.setOpacity(1);
    painter.setPen(ender_col);
    painter.drawText(-50, -15, 100, 20, Qt::AlignHCenter, tr("Reboot")); //

    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    if (zoom)
    {
        painter.drawPixmap(QRect(-18, -50, 36, 36), pix, QRect(0, 0, pix.width(), pix.height()));//
    }
    else
    {
        painter.drawPixmap(QRect(-16, -50, 32, 32), pix, QRect(0, 0, pix.width(), pix.height()));//
    }
}

void Ender::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        mousepos = event->pos();
        grabMouse(QCursor(Qt::SizeAllCursor));
    }
}

void Ender::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p = event->globalPos()-mousepos;
    move(p.x(), p.y());
}

void Ender::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    releaseMouse();
    // save new Trash position on desk writing on panda.cfg
    appsettings->beginGroup("Ender");
    appsettings->setValue("pos", pos());
    appsettings->endGroup(); // Ender
}

void Ender::mouseDoubleClickEvent(QMouseEvent *event)
{
   myApp->wm_shutdown();
}

void Ender::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    zoom = true;
    update();

    setToolTip(tr("Shutdown Session"));
}

void Ender::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    zoom = false;
    update();
}

void Ender::update_style()
{
    read_settings();
    init();
    update();
}

