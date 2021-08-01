#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:


    void on_signup_clicked();

    void on_signin_clicked();

   // void on_pushButton_4_clicked();

    //void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
