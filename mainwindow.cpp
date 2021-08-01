#include "dialog.h"
#include "mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include<QDebug>
#include "help.h"
#include "file.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
//    ui->setupUi(this);
    MainWindow::showMaximized();
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/output-onlinejpgtools (1).jpg");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));

    //ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_2_clicked()
{
        dialog = new Dialog(this);
        hide();
        dialog->show();
    }
void MainWindow::on_pushButton_4_clicked()
{
  close();
}
void MainWindow::on_pushButton_3_clicked()
{
    h = new help(this);
    hide();
    h->show();
}

void MainWindow::on_pushButton_clicked()
{
    f = new file(this);
    hide();
    f->show();
}
