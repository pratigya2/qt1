#include "movielist.h"
#include "ui_movielist.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include "movie.h"
#include<QPixmap>
Movielist::Movielist(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::Movielist)
{
    QString qry_string, ui_label;
    ui->setupUi(this);
    QSqlDatabase myfile;
    myfile = QSqlDatabase::addDatabase("QSQLITE");
    myfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/movie.db");
    if (!myfile.open())
    {
        qDebug() << ("Failed to open the database");
    }
    else
    {
        qDebug() << ("Connected");
    }
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery qry;

    switch (temp)
    {
    case 0:
    {
        qry_string = "select Name, Date, Ratings, Genre from movie order by Ratings DESC";
       qDebug()<<"Case 0 ko query";
       ui_label = "Top Rated Movies";

        break;
    }
    case 1:
    {
        qry_string = "select Name, Date, Ratings, Genre from movie where Genre = 'Romantic' order by Ratings DESC ";
        ui_label= "Top Romantic Movies";
        qDebug()<<"Romantic movies ko list";

        break;
    }
    }
    qry.prepare(qry_string);
    if (qry.exec())
    {
        model->setQuery(qry);
        ui->label_2->setText(ui_label);
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        qDebug()<<"case 0 query executed";
    }
}

    //    switch (a){
    //    }
    //    }

//        qry.prepare("select Name, Date, Ratings, Genre,Image from movie order by Ratings DESC");
//        if (qry.exec())
//        {
//           model->setQuery(qry);

//           ui->tableView->setModel(model);
//                            ui->tableView->setItemDelegateForColumn(6, new ImageDelegate);

//            ui->tableView->resizeColumnsToContents();
//            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
//           ui->tableView->horizontalHeader()->setStretchLastSection(true);


//         }
//}

Movielist::~Movielist()
{
    delete ui;
}

void Movielist::on_tableView_activated(const QModelIndex &index)
{
    movie m;
    int c = index.column();
    QString temp = ui->tableView->model()->data(index).toString();
    qDebug() << temp;
    m.setModal(true);
    hide();
    m.exec();
}

void Movielist::receive(int a)
{
    temp = a;
    qDebug()<<"opening movielist";
}
