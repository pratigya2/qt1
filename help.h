#ifndef HELP_H
#define HELP_H
#include <QDialog>

namespace Ui {
class MainWindow;
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();

private slots:


private:
    Ui::help *ui;
};
#endif // HELP_H
