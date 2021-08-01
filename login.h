#ifndef LOGIN_H
#define LOGIN_H

#include "movie.h"
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    //void on_pushButton_3_clicked();

private:
    Ui::login *ui;
    movie *mov;

};

#endif // LOGIN_H
