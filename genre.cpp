#include "genre.h"
#include "ui_genre.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include<QMessageBox>
#include<QBuffer>
#include<QFileDialog>
#include<QPixmap>

genre::genre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::genre)
{
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));

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

genre::~genre()
{
    delete ui;
}


void genre::on_comedy_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Comedy'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
     }
}

void genre::on_action_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Action'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(6,new ImageDelegate);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->verticalHeader()->setStretchLastSection(true);






     }
}

void genre::on_drama_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Drama'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();

     }

}

void genre::on_horror_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Horror'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();

     }

}

void genre::on_scifiction_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Sci-fiction'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();

     }

}

void genre::on_romantic_clicked()
{
    int genre_choice = 1;
    Movielist movie_list;
    movie_list.setModal(true);
    hide();
    movie_list.exec();
    connect(this,SIGNAL(send_data(int)), &movie_list, SLOT(receive(int)));
    emit send_data(genre_choice);
//    QSqlQueryModel *modal=new QSqlQueryModel;
//    QSqlQuery qry;
//    qry.prepare("select * from movie where Genre='Romantic'");
//    if (qry.exec())
//    {
//       modal->setQuery(qry);
//       ui->tableView->setModel(modal);
//       ui->tableView->resizeColumnsToContents();
//     }
}
