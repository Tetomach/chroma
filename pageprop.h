#ifndef PageProp_H
#define PageProp_H

#include <QDialog>

#include <QMessageBox>
#include <QLabel>
#include <QAction>
#include <QPlainTextEdit>

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
class PageProp;
}

class QIntValidator;

QT_END_NAMESPACE

class PageProp : public QDialog
{
    Q_OBJECT

public:
    struct Leaf {
        QString pageNumber;
        QString pageNotes;
        bool subpage;
    };

    explicit PageProp(QWidget *parent = 0);
    ~PageProp();

    Leaf leaf() const;

private slots:
    void apply();

private:
    Ui::PageProp *ui;
    Leaf pageLeaf;
    QIntValidator *intValidator;
};

#endif // PageProp_H
