#include "genre.h"
#include "ui_genre.h"

genre::genre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::genre)
{
    ui->setupUi(this);
}

genre::~genre()
{
    delete ui;
}


void genre::on_comedy_clicked()
{

}

void genre::on_action_clicked()
{

}

void genre::on_drama_clicked()
{

}

void genre::on_horror_clicked()
{

}

void genre::on_scifiction_clicked()
{

}
