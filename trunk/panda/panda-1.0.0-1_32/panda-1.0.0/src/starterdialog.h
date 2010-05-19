////////////////////////////////////////
//  File      : runner.h              //
//  Written by: zv.zorro@gmail.com  //
//  Copyright : GPL                   //
////////////////////////////////////////

// start an application from command line

////////////////////////////////////////

#ifndef STARTERDIALOG_H
#define STARTERDIALOG_H

#include "defs.h"
#include "msgbox.h"

////////////////////////////////////////

class StarterDialog : public QDialog
{
    Q_OBJECT

public:
    StarterDialog(QWidget *parent=0);
    ~StarterDialog();
    void read_settings();
    void init();
    void load_cmd_history();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);




signals:

public slots:
    void run_pressed();
    void close_pressed();

private:
    QPoint mousepos;
    QString ok_button_pix_path;
    QString close_button_pix_path;
    QComboBox *command_line;
    QComboBox *proto_types;
    QFile *run_history;
    QStringList history_list;
};


#endif
