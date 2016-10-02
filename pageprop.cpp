#include "pageprop.h"
#include "ui_pageprop.h"

#include <QIntValidator>
#include <QLineEdit>

QT_USE_NAMESPACE

static const char blankString[] = QT_TRANSLATE_NOOP("PageProp", "N/A");

PageProp::PageProp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PageProp)
{
    ui->setupUi(this);

    intValidator = new QIntValidator(0, 999999999, this);

    connect(ui->applyButton, &QPushButton::clicked,
            this, &PageProp::apply);
}

PageProp::~PageProp()
{
    delete ui;
}

PageProp::Leaf PageProp::leaf() const
{
    return pageLeaf;
}

void PageProp::apply()
{
    
    hide();
}
