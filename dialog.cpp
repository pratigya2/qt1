#include <string.h>
#include "dialog.h"
#include "ui_dialog.h"
#include "file.h"
#include "login.h"
#include <QPixmap>
#include "help.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    //Dialog::showMaximized();
    ui->setupUi(this);
    setWindowTitle("start");
    QPixmap pix("C:/Users/user/Downloads/image (1).jpg");
    int w = ui->welcome->width();
       int h =ui->welcome->height();
      ui->welcome->setPixmap(pix.scaled(w,h));
    //ui->welcome->setPixmap(pix);
}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_signup_clicked()
    {
        file f;
        f.setModal(true);
        hide();
        f.exec();
    }
void Dialog::on_signin_clicked()
{
        login l;
        l.setModal(true);
        hide();
        l.exec();
}
//void Dialog::on_pushButton_3_clicked()
//{
//    help h;
//    h.setModal(true);
//    hide();
//    h.exec();

//}

