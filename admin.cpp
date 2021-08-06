#include "admin.h"
#include "ui_admin.h"
#include"admin_adding.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_add_movies_Button_clicked()
{
    admin_adding a;
    hide();
    a.exec();

}
