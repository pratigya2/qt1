#include "admin_adding.h"
#include "ui_admin_adding.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>

admin_adding::admin_adding(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_adding)
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
}

admin_adding::~admin_adding()
{
    delete ui;
}

void admin_adding::on_pushButton_clicked()
{
    QString movie_name,summary,date,cast_members,ratings;
     movie_name=ui->name->text();
      summary=ui->summary->text();
       date=ui->date->text();
        cast_members=ui->cast_members->text();
         ratings=ui->ratings->text();
         int r=ratings.toInt();
    QSqlQuery qry;
    qry.prepare("insert into movie values('"+movie_name+"','"+summary+"','"+date+"','"+cast_members+"',?)");
    qry.addBindValue(r);
    if(!qry.exec())
    {
        qDebug()<<"Not inserted !!";

    }
}
