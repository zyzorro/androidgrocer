////////////////////////////////////////
//  File      : StarterDialog.cpp            //
//  Written by: zv.zorro@gmail.com  //
//  Copyright : GPL                   //
////////////////////////////////////////

#include "starterdialog.h"

////////////////////////////////////////

StarterDialog::StarterDialog(QWidget *parent) : QDialog(parent)
{
    setSizeGripEnabled(true);
    setWindowModality(Qt::WindowModal);
    read_settings();
    init();
    show();
}

StarterDialog::~StarterDialog()
{
}

void StarterDialog::read_settings()
{
    QSettings *appsettings = new QSettings(QCoreApplication::applicationDirPath() + "/panda.cfg", QSettings::IniFormat, this);
    appsettings->beginGroup("Style");
    QString stl_name = appsettings->value("name").toString();
    QString stl_path = appsettings->value("path").toString();
    appsettings->endGroup(); //Style
    // get style values
    QSettings *style = new QSettings(stl_path + stl_name, QSettings::IniFormat, this);
    style->beginGroup("Message");
    ok_button_pix_path = stl_path + style->value("ok_button_pix").toString();
    close_button_pix_path = stl_path + style->value("close_button_pix").toString();
    style->endGroup(); // Message
}

void StarterDialog::init()
{
    load_cmd_history();

    QGridLayout *layout = new QGridLayout();
    setLayout(layout);
    QLabel *name = new QLabel(tr("Login"), this);
    name->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    name->setMaximumHeight(20);
    QLabel *text = new QLabel(tr("Remote IP:"), this);
    command_line = new QComboBox(this);
    command_line->setEditable(true);
    command_line->addItem(""); // add an empty entry as first
    command_line->addItems(history_list);
    command_line->setCurrentIndex(0);

    QLabel *text1 = new QLabel(tr("Select type:"), this);
    proto_types =  new QComboBox(this);
    proto_types->setEditable(false);
    proto_types->addItem("RDP");
    proto_types->addItem("VNC");
    proto_types->setCurrentIndex(0);

    QPushButton *run_but = new QPushButton(QIcon(ok_button_pix_path), tr("Login"), this);
    QPushButton *close_but = new QPushButton(QIcon(close_button_pix_path), tr("Close"), this);
    layout->addWidget(name, 0, 0, 1, 0);
    layout->addWidget(text, 1, 0, 1, 0);
    layout->addWidget(command_line, 2, 0, 1, 0);
    layout->addWidget(text1, 3, 0, 1, 0);
    layout->addWidget(proto_types, 4, 0, 1, 0);
    layout->addWidget(run_but, 5, 0);
    layout->addWidget(close_but, 5, 1);

    connect(run_but, SIGNAL(pressed()), this, SLOT(run_pressed()));
    connect(close_but, SIGNAL(pressed()), this, SLOT(close_pressed()));
}

void StarterDialog::load_cmd_history()
{
    // load the command history
    run_history = new QFile(QDir::tempPath() + "/StarterDialog.log");
    // create it if doesn't exists
    if(!run_history->exists())
    QProcess::startDetached(QString("/bin/touch").append(" ").append(QDir::tempPath() + "/appsettings-StarterDialog.log"));

    if (!run_history->open(QIODevice::ReadOnly))
    {
        qCritical() << "Error on opening <appsettings-StarterDialog.log> file";
        return;
    }
    QTextStream read_stream(run_history);

    while (!read_stream.atEnd())
    {
         QString cmd_entry = read_stream.readLine();
         history_list << cmd_entry;
    }
    run_history->close();
}

void StarterDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::darkGray, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawRect(0, 0, width(), height());
}

void StarterDialog::mousePressEvent(QMouseEvent *event)
{
    mousepos = event->pos();
    grabMouse(QCursor(Qt::SizeAllCursor));
    raise();
}

void StarterDialog::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p = event->globalPos()-mousepos;
    move(p.x(), p.y());
}

void StarterDialog::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    releaseMouse();
}

void StarterDialog::run_pressed()
{
    QString ip = command_line->currentText();
    QString prototypes = proto_types->currentText();

    if ((ip != ""))
    {
        if( prototypes == QString("VNC")) {
             // TOBE complete
            Msgbox msg;
            msg.set_header(tr("To be complete"));
            msg.set_info(tr("Under hacking"));
            msg.set_icon("Critical");
            msg.exec();
            close();
        } else if( prototypes == QString("RDP")) {

            QStringList args;
            args << ip;
            if (QProcess::startDetached("/usr/bin/rdesktop", args))
            {
                if (!run_history->open(QIODevice::WriteOnly | QIODevice::Append))
                {
                    qCritical() << "Error on opening <appsettings-StarterDialog.log> file";
                    return;
                }
                QTextStream write_stream(run_history);
                write_stream << ip << endl; // append current command at the end of file
                run_history->close();
                close();
            } else {

                Msgbox msg;
                msg.set_header(tr("Cann't find  /usr/bin/rdesktop"));
                msg.set_info(tr("Check the command .\n"
                                "If the app is not in your $PATH, type the absolute app path."));
                msg.set_icon("Critical");
                msg.exec();
            }
        }
    }
}

void StarterDialog::close_pressed()
{
    close();
}
