#include "users.h"
#include "ui_users.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include <QMessageBox>

users::users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::users)
{
    ui->setupUi(this);
    QSqlDatabase myfile;
    myfile=QSqlDatabase::addDatabase("QSQLITE");
    myfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/movie.db");
    if(!myfile.open())
    {
        qDebug()<<("Failed to open the database");
    }
    else
    {
        qDebug()<<("Connected");

    }
}

users::~users()
{
    delete ui;
}

void users::on_pushButton_clicked()
{
    QSqlQuery qry ;
    QSqlQueryModel *modal=new QSqlQueryModel;
    qry.prepare("select username from users_info");
     if (qry.exec())
    {
        modal->setQuery(qry);
        ui->listView->setModel(modal);

    }
}
void users::on_pushButton_2_clicked()
{
    QString name;
    name=ui->lineEdit->text();
    QSqlQuery qry ;
    QSqlQueryModel *modal=new QSqlQueryModel;
    qry.prepare("select * from users_info where username='"+name+"'");
     if (qry.exec())
    {
        modal->setQuery(qry);
        ui->tableView->setModel(modal);
    }
}
