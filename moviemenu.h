#ifndef MOVIEMENU_H
#define MOVIEMENU_H
#include "userinfo.h"
#include"movielist.h"

#include <QDialog>

namespace Ui {
class moviemenu;
}

class moviemenu : public QDialog
{
    Q_OBJECT

public:
    explicit moviemenu(QWidget *parent = nullptr);
    ~moviemenu();

signals:
    void send_data(int);
public slots:
void receive_user_info(QString);

    void on_pushButton_clicked();
//    void on_pushButton_3_clicked();


    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::moviemenu *ui;
    userinfo *usi;
    Movielist *movie_list;
};

#endif // MOVIEMENU_H
