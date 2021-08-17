#ifndef STAR_H
#define STAR_H


#include <QDialog>

namespace Ui {
class star;
}

class star : public QDialog
{
    Q_OBJECT

public:
    explicit star(QWidget *parent = nullptr);
    ~star();

private slots:
    void on_pushButton_clicked();
//protected :
//    void paintEvent(QPaintEvent *e);

private:
    Ui::star *ui;
};

#endif // STAR_H
