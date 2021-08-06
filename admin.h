#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include"admin_adding.h"

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_add_movies_Button_clicked();

private:
    Ui::admin *ui;
    admin_adding *add;
};

#endif // ADMIN_H
