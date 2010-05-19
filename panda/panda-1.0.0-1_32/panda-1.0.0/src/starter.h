////////////////////////////////////////
//  File      : trash.h               //
//  Written by: zv.zorro@gmail.com  //
//  Copyright : GPL                   //
////////////////////////////////////////

// Trash pixmap (freedesktop.org implementation)

////////////////////////////////////////

#ifndef STARTER_H
#define STARTER_H

#include "defs.h"
#include "utils.h"
#include "msgbox.h"
#include "starterdialog.h"
#include "panda.h"
#include "desk.h"

////////////////////////////////////////

class Panda;
class Desk;

class Starter : public QWidget
{
    Q_OBJECT

public:
    Starter(QWidget *parent=0);
    ~Starter();

    void update_style();
    void init();
    void read_settings();
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void paintEvent(QPaintEvent *);

signals:

public slots:

private:
    QString starter_pix;
    QColor starter_col;
    QPixmap pix;
    bool zoom;
    QPoint mousepos;
    QString stl_path;
    QString stl_name;
    QSettings *appsettings;
    StarterDialog *starter_dlg;
};

class Ender : public QWidget
{
public:
    Ender(QWidget *parent=0);
    ~Ender();
    void init();
    void read_settings();
    void update_style();
protected:

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void paintEvent(QPaintEvent *);
private:
    Panda *myApp;
    QString ender_pix;
    QColor ender_col;
    QPixmap pix;
    bool zoom;
    QPoint mousepos;
    QString stl_path;
    QString stl_name;
    QSettings *appsettings;


};


#endif
