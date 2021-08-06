#include "file.h"
#include "ui_file.h"
#include "login.h"
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include <QHash>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlRecord>
#include<QSqlQueryModel>
file::file(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::file)
{
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));
    QSqlDatabase myfile;
    myfile=QSqlDatabase::addDatabase("QSQLITE");
    myfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/users_info.db");
    if(!myfile.open())
    {
        qDebug()<<("Failed to open the database");
    }
    else
    {
        qDebug()<<("Connected");

    }
    qDebug()<<"Hello pratigey";
}
file::~file()
{
    delete ui;
}
void file::on_pushButton_8_clicked()
{
   User u;
   QString firstname = ui->lineEdit->text();
   QString lastname = ui->lineEdit_2->text();
   QString age= ui->lineEdit_3->text();
   QString username = ui->lineEdit_4->text();
   QString pw = ui->lineEdit_5->text();
   QString cpw = ui->lineEdit_6->text();
   if(pw.compare(cpw,Qt::CaseSensitive)==0){
   int umer=age.toInt();
   QSqlQuery qry;
   qry.prepare("insert into users_info values('"+firstname+"','"+lastname+"',?,'"+username+"')");
   qry.addBindValue(umer);
   if(!qry.exec())
   {
       qDebug()<<"not done";
   }



   if(firstname.isEmpty()&&lastname.isEmpty()&&age.isEmpty()&&pw.isEmpty()){
       QMessageBox::warning(this,"EMPTY","PLEASE FILL THIS BOX");
   }
   u.write_data(firstname,lastname,age,username,cpw);

   if(!firstname.isEmpty()&&!lastname.isEmpty()&&!age.isEmpty()&&!pw.isEmpty()){
       login l;
       l.setModal(true);
       hide();
       l.exec();
   }
}
else{
QMessageBox::warning(this,"ERROR","PASSWORD AND CONFIRM PASSWORD DOESNOT MATCH");
}
}




