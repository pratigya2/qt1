#ifndef GENRE_H
#define GENRE_H
#include "movielist.h"

#include <QDialog>

namespace Ui {
class genre;
}

class genre : public QDialog
{
    Q_OBJECT

public:
    explicit genre(QWidget *parent = nullptr);
    ~genre();
signals:
    void send_data(int);
private slots:
    void on_comedy_clicked();
    void on_action_clicked();
    void on_drama_clicked();
    void on_horror_clicked();
    void on_scifiction_clicked();
    void on_romantic_clicked();
private:
    Ui::genre *ui;
    Movielist *movie_list;
};

#endif // GENRE_H
