#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <QDialog>
#include<QPainter>
#include<QStyledItemDelegate>
#include<QByteArray>

namespace Ui {
class Movielist;
}

class Movielist : public QDialog
{
    Q_OBJECT

public:
    explicit Movielist(QWidget *parent = nullptr);
    ~Movielist();

private slots:
    void on_tableView_activated(const QModelIndex &index);

public slots:
    void receive(int);


private:
    Ui::Movielist *ui;
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

#endif // MOVIELIST_H
