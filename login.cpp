#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "movies.h"
#include "admin.h"
#include "mainwindow.h"
#include "moviemenu.h"
#include "userinfo.h"

login::login(QWidget *parent) : QDialog(parent),
                                ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w, h));
}
login::~login()
{
    delete ui;
}
void login::on_pushButton_3_clicked()
{
    int a;
    QString line = ui->lineEdit->text();
    QString pw = ui->lineEdit_2->text();
    if (line == "pratigya007" && pw == "pr@tigy@1")
    {
        admin a;
        a.setModal(true);
        hide();
        a.exec();
    }
    else
    {
        User u;
        a = u.login(line, pw);
        if (a == 0)
        {
            QMessageBox::warning(this, "SIGNUP", "You are not logged in before");
        }
        if (a == 1)
        {
            QMessageBox::information(this, "Welcome", "Yes you are logged in");

            //    movie mov2;
            //    mov2.setModal(true);
            //    hide();
            //    mov2.exec();
            qDebug()<<line;
            moviemenu mm;
            mm.setModal(true);
            hide();
            mm.exec();
            connect(this, SIGNAL(send_d(QString)), Moviemenu, SLOT(receive_user_info(QString)));
            emit send_d(line);
            qDebug()<<"Test1";
            //    connect(this,SIGNAL(send(QString)),mov,SLOT(on_pushButton_2_clicked(QString)));
            //    emit send(line);

        }

    }
    //    connect(this,SIGNAL(send(QString)),mov,SLOT(on_pushButton_2_clicked(QString)));
    //    emit send(line);
    //    connect(this,SIGNAL(send_d(QString)),usin,SLOT(on_pushButton_clicked(QString)));
    //     emit send_d(line);

}
