#include "userinfo.h"
#include "ui_userinfo.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>

userinfo::userinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userinfo)
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

userinfo::~userinfo()
{
    delete ui;
}

void userinfo::receive_user_info(QString username)
{
    qDebug()<<username;
    ui->label->setText(username);

//    ui->textBrowser->setText(line2);
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel;
    qry.prepare("select * from users_info where username='cwane11'");
    if(qry.exec())
    {
        while(qry.next())
        {
            modal->setQuery(qry);
            ui->tableView->setModel(modal);

        }
    }
}


//void userinfo::on_pushButton_clicked(QString line2)
void userinfo::on_pushButton_clicked()
{

}


