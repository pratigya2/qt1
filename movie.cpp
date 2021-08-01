#include "movie.h"
#include "ui_movie.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>

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
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM movie where name ='"+movie_name+"'");
    if(qry.exec())
    {
        while(qry.next())

        {
            qDebug()<<"read";
            modal->setQuery(qry);
            ui->tableView->setModel(modal);
        }
    }
}
