#include "star.h"
#include "ui_star.h"
#include <QPainter>
#include <QDebug>
#include <QIcon>

star::star(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::star)
{
    ui->setupUi(this);
}

star::~star()
{
    delete ui;
}
int counter;
void star::on_pushButton_clicked()
{
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Pictures/Screenshots/Screenshot (245).png"));
    ui->pushButton->setIcon(*ico);
    ui->pushButton->setCheckable(true);

   //btn->setIcon(QIcon("C:/Users/user/Downloads/OIP.jpeg"));
//    counter ++;
//    qInfo()<<counter;

}
//void star::paintEvent(QPaintEvent *e){
//    QPainter painter(this);
//    //painter.drawTiledPixmap("C:/Users/user/Downloads/OIP.jpeg");
//    QPolygon poly;
//    poly<<QPoint(100,0);
//   poly<<QPoint(72,68);
//    poly<<QPoint(5,68);
//    poly<<QPoint(63,105);
//    poly<<QPoint(22,160);
//    poly<<QPoint(100,125);
//    poly<<QPoint(178,160);
//    poly<<QPoint(137,105);
//   poly<<QPoint(194,65);
//   poly<<QPoint(123,65);

//    QPen linepen(Qt::black);
//    linepen.setWidth(5);
//    linepen.setColor(Qt::red);
//    painter.drawPolygon(poly);
//   poly.resize(2);
//    //painter.drawConvexPolygon()

//}
