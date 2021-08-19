#include "movie.h"
#include "ui_movie.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>
movie::movie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::movie)
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
    qDebug()<<"Hello pratigey";
}

movie::~movie()
{
    delete ui;
}
QString uppercase(QString str){
    int x;
    int y;
    for(int i=0;str[i]!='\0';i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
             x = str[i].toLatin1();
              y = x - 32;
              str[i]=QChar(y);
    }
    return str;
}
int a;
void movie::on_pushButton_5_clicked()
{
    a++;
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png"));
    ui->pushButton_5->setIcon(*ico);
    ui->pushButton_5->setCheckable(true);
}
void movie::on_pushButton_6_clicked()
{
    a++;
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png"));
    ui->pushButton_6->setIcon(*ico);
    ui->pushButton_6->setCheckable(true);
}

void movie::on_pushButton_7_clicked()
{
    a++;
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png"));
    ui->pushButton_7->setIcon(*ico);
    ui->pushButton_7->setCheckable(true);
}

void movie::on_pushButton_8_clicked()
{
    a++;
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png"));
    ui->pushButton_8->setIcon(*ico);
    ui->pushButton_8->setCheckable(true);
}
void movie::on_pushButton_9_clicked()
{
    a++;
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png"));
    ui->pushButton_9->setIcon(*ico);
    ui->pushButton_9->setCheckable(true);
    qInfo()<<a;
}
void movie::on_pushButton_clicked()
{
    QPixmap pix("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png");
    int width  = ui->label_9->width();
       int height =ui->label_9->height();
      ui->label_9->setPixmap(pix.scaled(width,height));
     QString movie_name;
     QString upper;
     movie_name=ui->lineEdit->text();
     upper = movie_name.toUpper();

//QString lower;
//     lower = movie_name.toLower();
//     qInfo()<<lower;

         QSqlQuery qry;
    qry.prepare("SELECT * FROM movie where name ='"+upper+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            QString name= qry.value(0).toString();
            QString summary= qry.value(1).toString();
            QString date= qry.value(2).toString();
            QString director= qry.value(3).toString();
            QString cast= qry.value(4).toString();
            QString rating= qry.value(5).toString();
            QString trailer= qry.value(9).toString();
            QByteArray outByteArray = qry.value(6).toByteArray();
            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData( outByteArray );
            ui->label_2->setText(name);
            ui->label_3->setText("RELEASED DATE");
            ui->label_4->setText(date);
            ui->label_5->setText("SUMMARY");
            ui->textBrowser->setText(summary);
            ui->label_6->setText(cast);
            ui->label_10->setText(director);
            ui->label_11->setText("CAST MEMBERS");
            ui->label_12->setText("DIRECTOR NAME");
            ui->pushButton_10->setText("TRAILER LINK");
            ui->rate->setText(rating);
            int x = ui->image->width();
               int y =ui->image->height();
            outPixmap = outPixmap.scaledToWidth(ui->image->width(), Qt::SmoothTransformation);
           ui->image->setPixmap( outPixmap.scaled(x,y) );
        }
    }
    if(!qry.exec())
    {
        QMessageBox::warning(this,"ERROR","Movie not found");
    }
    QSqlQueryModel *modal2=new QSqlQueryModel;
    QSqlQuery qry2;    
     qry2.prepare("select username,rating,review from review_table where movie_name = ?");
     qry2.addBindValue(upper);
     if(qry2.exec())
     {
        while(qry2.next())
          {
            modal2->setQuery(qry2);
            ui->tableView->setModel(modal2);
            ui->tableView->resizeColumnsToContents();

           }
     }
      // ratingupdate

//     QSqlQuery query;
//     query.prepare("insert into movie values(?) where name='"+upper+"'");
//     query.addBindValue(a);
//     qDebug()<<a;
    }





//void movie::on_pushButton_2_clicked(QString line2)
//{
//    qDebug()<<line2;
//    ui->username->setText(line2);
//    QSqlDatabase myfile;
//    myfile=QSqlDatabase::addDatabase("QSQLITE");
//    myfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/users_info.db");
//    if(!myfile.open())
//    {
//        qDebug()<<("Failed to open the database");
//    }
//    else
//    {
//        qDebug()<<("Connected");

//    }
//    QSqlQuery qry;
//    qry.prepare("select * from users_info where username='"+line2+"'");
//    if(qry.exec())
//    {
//        while(qry.next())
//        {
//            QString firstname= qry.value(0).toString();
//            QString lastname= qry.value(1).toString();
//            QString username= qry.value(2).toString();
//            QString age= qry.value(3).toString();
//            ui->firstname->setText(firstname);
//            ui->lastname->setText(lastname);
//            ui->age->setText(age);
////            QMessageBox::information(this,"USER INFO",firstname);
//        }
//    }
//}



void movie::on_pushButton_13_clicked()
{

    QString movie_name,username,review,rating;
    QString upper;
    movie_name=ui->lineEdit->text();
    upper = movie_name.toUpper();
    //a  = rating.toInt();
    qInfo()<<"rating"<<a;
    username=ui->username_for_review->text();
    review=ui->add_review->text();
    QSqlQuery qry;
    qry.prepare("insert into review_table values('"+username+"','"+upper+"','"+review+"',?)");
    qry.addBindValue(a);
    if(qry.exec())
    {
        QMessageBox::information(this,"INSERTED","Review and rating inserted");
    }


    //rating updaate
//    QSqlQuery qry2;
//     qry2.prepare("select * from movie where name='"+upper+"' ");
//     if(qry2.exec())
//     {
//         while(qry2.next())
//         {
//             int demo5 =qry2.value(4).toInt();

//                     int av=0.5*(demo5+r);

//                     qDebug()<<demo5;
//                     qDebug()<<r;
//                     qDebug()<<av;

//                     connect(this,SIGNAL(send_d(int)),this,SLOT(on_pushButton_clicked(int)));

//                     emit send_d(av);
//         }
//     }
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-N6h4pB3vkwR9zPY.png"));
    ui->pushButton_5->setIcon(*ico);
    ui->pushButton_5->setCheckable(true);
    ui->pushButton_6->setIcon(*ico);
    ui->pushButton_6->setCheckable(true);
    ui->pushButton_7->setIcon(*ico);
    ui->pushButton_7->setCheckable(true);
    ui->pushButton_8->setIcon(*ico);
    ui->pushButton_8->setCheckable(true);
    ui->pushButton_9->setIcon(*ico);
    ui->pushButton_9->setCheckable(true);

}

void movie::on_pushButton_10_clicked()
{
    QString upper,movie_name;
    movie_name=ui->lineEdit->text();
    upper = movie_name.toUpper();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM movie where name ='"+upper+"'");
    if(qry.exec())
    {
   while(qry.next())
   {
     QString trailer= qry.value(9).toString();
     QDesktopServices::openUrl(QUrl(trailer));
    }
    }
}
