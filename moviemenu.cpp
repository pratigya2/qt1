#include "moviemenu.h"
#include "ui_moviemenu.h"
#include "userinfo.h"
#include "genre.h"
#include<QObject>
#include "language.h"
#include<QDebug>
moviemenu::moviemenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moviemenu)
{
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));
}
moviemenu::~moviemenu()
{
    delete ui;
}
void moviemenu::on_pushButton_clicked()
{
    userinfo useri;
    useri.setModal(true);
    hide();
    useri.exec();
//    usi = new userinfo(this);
//    hide();
//    usi->show();
}
//void moviemenu::on_pushButton_3_clicked()
//{
//  genre g;
//g.setModal(true);
//hide();
//g.exec();
//}
void moviemenu::on_pushButton_2_clicked()
{
   Movielist movie_list;
   int choice = 0;

   movie_list.setModal(true);
   hide();
    movie_list.exec();
    connect(this, SIGNAL(send_data(int)), &movie_list, SLOT(receive(int)));
    emit send_data(choice);
}

void moviemenu::receive_user_info(QString username)
{
    qDebug()<<"abcd";
    ui->label_2->setText(username);
}



void moviemenu::on_pushButton_3_clicked()
{
      genre g;
    g.setModal(true);
    hide();
    g.exec();
}

void moviemenu::on_pushButton_5_clicked()
{
    language l;
    l.setModal(true);
    hide();
    l.exec();
}
