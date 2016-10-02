/********************************************************************************
** Form generated from reading UI file 'prop.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEPROP_H
#define UI_PAGEPROP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PageProp
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *identification_frame;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *page_name;
    QLineEdit *page_owner;
    QLineEdit *page_id;
    QLabel *label_4;
    QFrame *disc_frame;
    QGridLayout *gridLayout_6;
    QPlainTextEdit *page_notes;
    QLabel *label_7;

    void setupUi(QDialog *PageProp)
    {
        if (PageProp->objectName().isEmpty())
            PageProp->setObjectName(QStringLiteral("PageProp"));
        PageProp->resize(440, 207);
        gridLayout_3 = new QGridLayout(PageProp);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(PageProp);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout->addWidget(applyButton);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 2);

        frame = new QFrame(PageProp);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        identification_frame = new QFrame(frame);
        identification_frame->setObjectName(QStringLiteral("identification_frame"));
        identification_frame->setFrameShape(QFrame::StyledPanel);
        identification_frame->setFrameShadow(QFrame::Sunken);
        identification_frame->setLineWidth(10);
        gridLayout_2 = new QGridLayout(identification_frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(identification_frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setText(QStringLiteral("ID Number"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_2->addWidget(label_6, 2, 1, 1, 1);

        label_5 = new QLabel(identification_frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setText(QStringLiteral("Name"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        page_name = new QLineEdit(identification_frame);
        page_name->setObjectName(QStringLiteral("page_name"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(page_name->sizePolicy().hasHeightForWidth());
        page_name->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(page_name, 0, 2, 1, 1);

        page_owner = new QLineEdit(identification_frame);
        page_owner->setObjectName(QStringLiteral("page_owner"));
        sizePolicy.setHeightForWidth(page_owner->sizePolicy().hasHeightForWidth());
        page_owner->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(page_owner, 1, 2, 1, 1);

        page_id = new QLineEdit(identification_frame);
        page_id->setObjectName(QStringLiteral("page_id"));
        sizePolicy.setHeightForWidth(page_id->sizePolicy().hasHeightForWidth());
        page_id->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(page_id, 2, 2, 1, 1);

        label_4 = new QLabel(identification_frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setText(QStringLiteral("Owner"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_2->addWidget(label_4, 1, 1, 1, 1);


        gridLayout->addWidget(identification_frame, 0, 0, 1, 1);

        disc_frame = new QFrame(frame);
        disc_frame->setObjectName(QStringLiteral("disc_frame"));
        disc_frame->setFrameShape(QFrame::StyledPanel);
        disc_frame->setFrameShadow(QFrame::Sunken);
        disc_frame->setLineWidth(10);
        gridLayout_6 = new QGridLayout(disc_frame);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        page_notes = new QPlainTextEdit(disc_frame);
        page_notes->setObjectName(QStringLiteral("page_notes"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(128);
        sizePolicy1.setVerticalStretch(128);
        sizePolicy1.setHeightForWidth(page_notes->sizePolicy().hasHeightForWidth());
        page_notes->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(page_notes, 1, 0, 1, 1);

        label_7 = new QLabel(disc_frame);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);


        gridLayout->addWidget(disc_frame, 0, 1, 1, 1);


        gridLayout_3->addWidget(frame, 0, 0, 1, 2);


        retranslateUi(PageProp);

        QMetaObject::connectSlotsByName(PageProp);
    } // setupUi

    void retranslateUi(QDialog *PageProp)
    {
        PageProp->setWindowTitle(QApplication::translate("PageProp", "Page Properties", 0));
        applyButton->setText(QApplication::translate("PageProp", "Create", 0));
        label_7->setText(QApplication::translate("PageProp", "Notes", 0));
    } // retranslateUi

};

namespace Ui {
    class PageProp: public Ui_PageProp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEPROP_H
