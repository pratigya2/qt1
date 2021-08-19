#include "admin.h"
#include "ui_admin.h"
#include"admin_adding.h"
#include "movie.h"
#include"users.h"
#include "pdeletep.h"
#include"admin_series_adding.h"
#include"series.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_2_clicked()
{
    admin_adding a;
    hide();
    a.exec();

}

void admin::on_pushButton_4_clicked()
{
    mov =new movie(this);
    hide();
    mov->show();
}

void admin::on_pushButton_5_clicked()
{
    users u;
    hide();
    u.exec();
}

void admin::on_pushButton_3_clicked()
{
    pdeletep pdp;
    hide();
    pdp.exec();

}

void admin::on_pushButton_6_clicked()
{
    admin_series_adding ads;
    hide();
    ads.exec();
}

void admin::on_pushButton_7_clicked()
{
    pdeletep pdp;
    hide();
    pdp.exec();

}

void admin::on_pushButton_8_clicked()
{
    series s;
    hide();
    s.exec();
}
