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

private slots:
    void on_pushButton_clicked();

private:
    Ui::movie *ui;
};

#endif // MOVIE_H
