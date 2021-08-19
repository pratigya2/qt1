#ifndef GENRE_H
#define GENRE_H
#include "movielist.h"

#include <QDialog>
#include<QPainter>
#include<QStyledItemDelegate>
#include<QByteArray>

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
class ImageDelegate: public QStyledItemDelegate{
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
        const QByteArray & bytes = index.data().toByteArray();
        QPixmap pixmap;
        if(!bytes.isNull() && pixmap.loadFromData(bytes)){
            // for BASE64 change to
//             pixmap.loadFromData(QByteArray::fromBase64(bytes));
            painter->drawPixmap(option.rect, pixmap.scaled(option.rect.size(),
                                                           Qt::KeepAspectRatio,
                                                         Qt::SmoothTransformation));
            return;
        }
        return QStyledItemDelegate::paint(painter, option, index);
    }
};

#endif // GENRE_H
