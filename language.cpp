#include "language.h"
#include "ui_language.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include<QMessageBox>
#include<QBuffer>
#include<QFileDialog>

language::language(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::language)
{
    ui->setupUi(this);
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

language::~language()
{
    delete ui;
}


void language::on_nepali_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
     QSqlQuery qry;
     qry.prepare("select Name,Date,Director,Genre,Ratings from movie where Language='Nepali' order by Ratings DESC");
     if (qry.exec())
     {
        modal->setQuery(qry);
        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
      }

}

void language::on_english_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Name,Date,Director,Genre,Ratings from movie where Language='English' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
     }

}

void language::on_chinese_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Name,Date,Director,Genre,Ratings from movie where Language='Chinese' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
     }

}

void language::on_thai_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Name,Date,Director,Genre,Ratings from movie where Language='Thai'order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
     }

}

void language::on_korean_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Name,Date,Director,Genre,Ratings from movie where Language='Korean' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
     }

}

void language::on_hindi_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Name,Date,Director,Genre,Ratings from movie where Language='Hindi' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
     }

}

void language::on_turkish_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Name,Date,Director,Genre,Ratings from movie where Language='Turkish' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
     }

}

void language::on_japanese_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Name,Date,Director,Genre,Ratings from movie where Language='Japanese' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
     }

}
