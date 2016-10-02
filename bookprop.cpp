#include "bookprop.h"
#include "ui_bookprop.h"

#include <QIntValidator>
#include <QLineEdit>

QT_USE_NAMESPACE

static const char blankString[] = QT_TRANSLATE_NOOP("BookProp", "N/A");

BookProp::BookProp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookProp)
{
    ui->setupUi(this);

    intValidator = new QIntValidator(0, 999999999, this);

    connect(ui->applyButton, &QPushButton::clicked,
            this, &BookProp::apply);
}

BookProp::~BookProp()
{
    delete ui;
}

BookProp::Card BookProp::card() const
{
    return documentCard;
}

void BookProp::apply()
{
    
    hide();
}
