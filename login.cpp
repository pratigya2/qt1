#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "movies.h"
#include "mainwindow.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_2_clicked()
{
    int a;
    QString line = ui->lineEdit->text();
    QString pw = ui->lineEdit_2->text();

    User u;
   a = u.login(line,pw);
if(a==0){
    QMessageBox::warning(this,"SIGNUP","You are not logged in before");
}
if(a==1){
    QMessageBox::information(this,"Welcome","Yes you are logged in");
}
//QString message;
//message =
}
void login::on_pushButton_clicked()
{
    movie mov;
    mov.setModal(true);
    hide();
    mov.exec();
}


//void login::on_pushButton_3_clicked()
//{


//}

