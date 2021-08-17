#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QDialog>

namespace Ui {
class language;
}

class language : public QDialog
{
    Q_OBJECT

public:
    explicit language(QWidget *parent = nullptr);
    ~language();

private slots:

    void on_nepali_clicked();

    void on_english_clicked();

    void on_chinese_clicked();

    void on_thai_clicked();

    void on_korean_clicked();

    void on_hindi_clicked();

    void on_turkish_clicked();

    void on_japanese_clicked();

private:
    Ui::language *ui;
};

#endif // LANGUAGE_H
