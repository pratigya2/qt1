#ifndef GENRE_H
#define GENRE_H

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

private slots:


    void on_comedy_clicked();

    void on_action_clicked();

    void on_drama_clicked();

    void on_horror_clicked();

    void on_scifiction_clicked();

private:
    Ui::genre *ui;
};

#endif // GENRE_H
