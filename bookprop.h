#ifndef BookProp_H
#define BookProp_H

#include <QDialog>

#include <QMessageBox>
#include <QLabel>
#include <QAction>
#include <QPlainTextEdit>

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
class BookProp;
}

class QIntValidator;

QT_END_NAMESPACE

class BookProp : public QDialog
{
    Q_OBJECT

public:
    struct Card {
        QString name;
        QString indexNumber;
        QString bookNotes;
        QString bookOwner;
        QString user;
    };

    explicit BookProp(QWidget *parent = 0);
    ~BookProp();

    Card card() const;

private slots:
    void apply();

private:
    Ui::BookProp *ui;
    Card documentCard;
    QIntValidator *intValidator;
};

#endif // BookProp_H
