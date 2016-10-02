/********************************************************************************
** Form generated from reading UI file 'bookprop.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKPROP_H
#define UI_BOOKPROP_H

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

class Ui_BookProp
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
    QLineEdit *book_name;
    QLineEdit *book_owner;
    QLineEdit *book_id;
    QLabel *label_4;
    QFrame *disc_frame;
    QGridLayout *gridLayout_6;
    QPlainTextEdit *book_notes;
    QLabel *label_7;

    void setupUi(QDialog *BookProp)
    {
        if (BookProp->objectName().isEmpty())
            BookProp->setObjectName(QStringLiteral("BookProp"));
        BookProp->resize(440, 207);
        gridLayout_3 = new QGridLayout(BookProp);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(BookProp);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout->addWidget(applyButton);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 2);

        frame = new QFrame(BookProp);
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

        book_name = new QLineEdit(identification_frame);
        book_name->setObjectName(QStringLiteral("book_name"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(book_name->sizePolicy().hasHeightForWidth());
        book_name->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(book_name, 0, 2, 1, 1);

        book_owner = new QLineEdit(identification_frame);
        book_owner->setObjectName(QStringLiteral("book_owner"));
        sizePolicy.setHeightForWidth(book_owner->sizePolicy().hasHeightForWidth());
        book_owner->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(book_owner, 1, 2, 1, 1);

        book_id = new QLineEdit(identification_frame);
        book_id->setObjectName(QStringLiteral("book_id"));
        sizePolicy.setHeightForWidth(book_id->sizePolicy().hasHeightForWidth());
        book_id->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(book_id, 2, 2, 1, 1);

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
        book_notes = new QPlainTextEdit(disc_frame);
        book_notes->setObjectName(QStringLiteral("book_notes"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(128);
        sizePolicy1.setVerticalStretch(128);
        sizePolicy1.setHeightForWidth(book_notes->sizePolicy().hasHeightForWidth());
        book_notes->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(book_notes, 1, 0, 1, 1);

        label_7 = new QLabel(disc_frame);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);


        gridLayout->addWidget(disc_frame, 0, 1, 1, 1);


        gridLayout_3->addWidget(frame, 0, 0, 1, 2);


        retranslateUi(BookProp);

        QMetaObject::connectSlotsByName(BookProp);
    } // setupUi

    void retranslateUi(QDialog *BookProp)
    {
        BookProp->setWindowTitle(QApplication::translate("BookProp", "Book Properties", 0));
        applyButton->setText(QApplication::translate("BookProp", "Create", 0));
        label_7->setText(QApplication::translate("BookProp", "Notes", 0));
    } // retranslateUi

};

namespace Ui {
    class BookProp: public Ui_BookProp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKPROP_H
