#ifndef MOVIE_H
#define MOVIE_H

#include <QDialog>

namespace Ui {
class movie;
}

class movie : public QDialog
{
    Q_OBJECT

public:
    explicit movie(QWidget *parent = nullptr);
    ~movie();
//signals:
//    void send_d(int);

private slots:
//    void on_pushButton_clicked(int);
    void on_pushButton_clicked();

//    void on_pushButton_2_clicked(QString);
//     void on_pushButton_2_clicked();

  //  void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_13_clicked();
     void on_pushButton_10_clicked();


private:
    Ui::movie *ui;
};

#endif // MOVIE_H
