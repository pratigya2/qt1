#include "movie.h"
#include "ui_movie.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include <QMessageBox>

movie::movie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::movie)
{
    ui->setupUi(this);
    QSqlDatabase myfile;
    myfile=QSqlDatabase::addDatabase("QSQLITE");
    myfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/new.db");
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
//    QSqlDatabase mfile;
//    mfile=QSqlDatabase::addDatabase("QSQLITE");
//    mfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/new.db");
//    if(mfile.isOpen())

//    {
//        qDebug()<<"opened";
//    }
//    else{
//        qDebug()<<"not connected";
//    }
//}

movie::~movie()
{
    delete ui;
}

void movie::on_pushButton_clicked()
{
    QString movie_name;
     movie_name=ui->lineEdit->text();
//    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM movie where name ='"+movie_name+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            QString name= qry.value(0).toString();
            QString summary= qry.value(1).toString();
            QString date= qry.value(2).toString();
            QString cast= qry.value(3).toString();
            QString rating= qry.value(4).toString();
            ui->label_2->setText(name);
            ui->label_3->setText("Released date");
            ui->label_4->setText(date);
            ui->label_5->setText("summary");
            ui->textBrowser_2->setText(summary);
            ui->label_6->setText(cast);
            ui->label_7->setText(rating);
        }
    }
}
void movie::on_pushButton_2_clicked(QString line2)
{
    qDebug()<<line2;
    ui->username->setText(line2);
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
    QSqlQuery qry;
    qry.prepare("select * from users_info where username='"+line2+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            QString firstname= qry.value(0).toString();
            QString lastname= qry.value(1).toString();
            QString username= qry.value(2).toString();
            QString age= qry.value(3).toString();
            ui->firstname->setText(firstname);
            ui->lastname->setText(lastname);
            ui->age->setText(age);
            QMessageBox::information(this,"USER INFO",firstname);
        }
    }
}


