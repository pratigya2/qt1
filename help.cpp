#include "help.h"
#include "ui_help.h"


help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
   // ui->setupUi(this);
    //help::showMaximized();
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/image (6).png");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));
    //*/ui->label->setPixmap(pix);
//      QPixmap p("C:/Users/user/Downloads/circle-cropped.png");
//      int x = ui->label_2->width();
//         int y =ui->label_2->height();
//        ui->label_2->setPixmap(p.scaled(x,y));*/

}
help::~help()
{
    delete ui;
}

