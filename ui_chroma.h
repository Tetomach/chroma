/********************************************************************************
** Form generated from reading UI file 'chroma.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHROMA_H
#define UI_CHROMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chroma
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionAdvanced_Settings;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *mainTabs;
    QWidget *tabWidgetPage1;
    QVBoxLayout *verticalLayout_5;
    QPushButton *serial_settings;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *serial_connect;
    QPushButton *serial_disconnect;
    QFrame *line_3;
    QPushButton *init_camera;
    QFrame *line;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *select_card;
    QPushButton *new_card;
    QFrame *line_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *expSpin;
    QDoubleSpinBox *gainSpin;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QPushButton *focus_in_coarse;
    QPushButton *focus_out_coarse;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QPushButton *focus_in_fine;
    QPushButton *focus_out_fine;
    QVBoxLayout *verticalLayout_6;
    QLabel *lens_tag;
    QLCDNumber *focusPos;
    QLabel *label;
    QLCDNumber *focusNumber;
    QHBoxLayout *horizontalLayout;
    QLabel *focus_tag;
    QComboBox *comboBox;
    QPushButton *single_capture;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *last_calibration;
    QLabel *calibDir;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *grid_calibration;
    QPushButton *white_calibration;
    QPushButton *dark_calibration;
    QPushButton *start_Button;
    QProgressBar *progressBar;
    QWidget *filterTab;
    QGridLayout *gridLayout_3;
    QTableWidget *filterData;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuDevice;

    void setupUi(QMainWindow *Chroma)
    {
        if (Chroma->objectName().isEmpty())
            Chroma->setObjectName(QStringLiteral("Chroma"));
        Chroma->resize(338, 603);
        actionConnect = new QAction(Chroma);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(Chroma);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionConfigure = new QAction(Chroma);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        actionAdvanced_Settings = new QAction(Chroma);
        actionAdvanced_Settings->setObjectName(QStringLiteral("actionAdvanced_Settings"));
        centralWidget = new QWidget(Chroma);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mainTabs = new QTabWidget(centralWidget);
        mainTabs->setObjectName(QStringLiteral("mainTabs"));
        mainTabs->setEnabled(true);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        mainTabs->setFont(font);
        mainTabs->setTabShape(QTabWidget::Triangular);
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QStringLiteral("tabWidgetPage1"));
        verticalLayout_5 = new QVBoxLayout(tabWidgetPage1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        serial_settings = new QPushButton(tabWidgetPage1);
        serial_settings->setObjectName(QStringLiteral("serial_settings"));

        verticalLayout_5->addWidget(serial_settings);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        serial_connect = new QPushButton(tabWidgetPage1);
        serial_connect->setObjectName(QStringLiteral("serial_connect"));

        horizontalLayout_4->addWidget(serial_connect);

        serial_disconnect = new QPushButton(tabWidgetPage1);
        serial_disconnect->setObjectName(QStringLiteral("serial_disconnect"));
        serial_disconnect->setEnabled(false);

        horizontalLayout_4->addWidget(serial_disconnect);


        verticalLayout_5->addLayout(horizontalLayout_4);

        line_3 = new QFrame(tabWidgetPage1);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_3);

        init_camera = new QPushButton(tabWidgetPage1);
        init_camera->setObjectName(QStringLiteral("init_camera"));
        init_camera->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(init_camera->sizePolicy().hasHeightForWidth());
        init_camera->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        init_camera->setFont(font1);

        verticalLayout_5->addWidget(init_camera);

        line = new QFrame(tabWidgetPage1);
        line->setObjectName(QStringLiteral("line"));
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        select_card = new QPushButton(tabWidgetPage1);
        select_card->setObjectName(QStringLiteral("select_card"));
        select_card->setEnabled(false);

        horizontalLayout_8->addWidget(select_card);

        new_card = new QPushButton(tabWidgetPage1);
        new_card->setObjectName(QStringLiteral("new_card"));
        new_card->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(new_card->sizePolicy().hasHeightForWidth());
        new_card->setSizePolicy(sizePolicy1);
        new_card->setFont(font1);

        horizontalLayout_8->addWidget(new_card);


        verticalLayout_5->addLayout(horizontalLayout_8);

        line_2 = new QFrame(tabWidgetPage1);
        line_2->setObjectName(QStringLiteral("line_2"));
        sizePolicy.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        frame = new QFrame(tabWidgetPage1);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setMinimumSize(QSize(0, 0));
        frame->setFont(font1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(10);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setUnderline(true);
        label_2->setFont(font2);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        gridLayout->addWidget(label_3, 1, 2, 1, 2);

        expSpin = new QDoubleSpinBox(frame);
        expSpin->setObjectName(QStringLiteral("expSpin"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(expSpin->sizePolicy().hasHeightForWidth());
        expSpin->setSizePolicy(sizePolicy4);
        expSpin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(expSpin, 1, 4, 1, 1);

        gainSpin = new QDoubleSpinBox(frame);
        gainSpin->setObjectName(QStringLiteral("gainSpin"));
        sizePolicy4.setHeightForWidth(gainSpin->sizePolicy().hasHeightForWidth());
        gainSpin->setSizePolicy(sizePolicy4);
        gainSpin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        gainSpin->setMaximum(17);
        gainSpin->setSingleStep(0.1);

        gridLayout->addWidget(gainSpin, 0, 4, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setUnderline(true);
        font3.setWeight(50);
        label_10->setFont(font3);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        focus_in_coarse = new QPushButton(frame);
        focus_in_coarse->setObjectName(QStringLiteral("focus_in_coarse"));
        focus_in_coarse->setEnabled(false);
        sizePolicy1.setHeightForWidth(focus_in_coarse->sizePolicy().hasHeightForWidth());
        focus_in_coarse->setSizePolicy(sizePolicy1);
        focus_in_coarse->setBaseSize(QSize(20, 5));

        verticalLayout_3->addWidget(focus_in_coarse);

        focus_out_coarse = new QPushButton(frame);
        focus_out_coarse->setObjectName(QStringLiteral("focus_out_coarse"));
        focus_out_coarse->setEnabled(false);
        sizePolicy1.setHeightForWidth(focus_out_coarse->sizePolicy().hasHeightForWidth());
        focus_out_coarse->setSizePolicy(sizePolicy1);
        focus_out_coarse->setBaseSize(QSize(20, 5));

        verticalLayout_3->addWidget(focus_out_coarse);


        gridLayout->addLayout(verticalLayout_3, 3, 3, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy5.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy5);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_6);

        focus_in_fine = new QPushButton(frame);
        focus_in_fine->setObjectName(QStringLiteral("focus_in_fine"));
        focus_in_fine->setEnabled(false);
        sizePolicy1.setHeightForWidth(focus_in_fine->sizePolicy().hasHeightForWidth());
        focus_in_fine->setSizePolicy(sizePolicy1);
        focus_in_fine->setBaseSize(QSize(20, 5));

        verticalLayout_2->addWidget(focus_in_fine);

        focus_out_fine = new QPushButton(frame);
        focus_out_fine->setObjectName(QStringLiteral("focus_out_fine"));
        focus_out_fine->setEnabled(false);
        sizePolicy1.setHeightForWidth(focus_out_fine->sizePolicy().hasHeightForWidth());
        focus_out_fine->setSizePolicy(sizePolicy1);
        focus_out_fine->setBaseSize(QSize(20, 5));

        verticalLayout_2->addWidget(focus_out_fine);


        gridLayout->addLayout(verticalLayout_2, 3, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        lens_tag = new QLabel(frame);
        lens_tag->setObjectName(QStringLiteral("lens_tag"));
        sizePolicy5.setHeightForWidth(lens_tag->sizePolicy().hasHeightForWidth());
        lens_tag->setSizePolicy(sizePolicy5);
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        font4.setKerning(true);
        lens_tag->setFont(font4);
        lens_tag->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(lens_tag);

        focusPos = new QLCDNumber(frame);
        focusPos->setObjectName(QStringLiteral("focusPos"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(focusPos->sizePolicy().hasHeightForWidth());
        focusPos->setSizePolicy(sizePolicy6);
        focusPos->setFrameShape(QFrame::WinPanel);
        focusPos->setFrameShadow(QFrame::Plain);
        focusPos->setSmallDecimalPoint(false);
        focusPos->setDigitCount(4);
        focusPos->setSegmentStyle(QLCDNumber::Flat);
        focusPos->setProperty("value", QVariant(0));
        focusPos->setProperty("intValue", QVariant(0));

        verticalLayout_6->addWidget(focusPos);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);

        focusNumber = new QLCDNumber(frame);
        focusNumber->setObjectName(QStringLiteral("focusNumber"));
        focusNumber->setEnabled(false);
        sizePolicy6.setHeightForWidth(focusNumber->sizePolicy().hasHeightForWidth());
        focusNumber->setSizePolicy(sizePolicy6);
        focusNumber->setFrameShape(QFrame::WinPanel);
        focusNumber->setFrameShadow(QFrame::Plain);
        focusNumber->setSmallDecimalPoint(false);
        focusNumber->setDigitCount(5);
        focusNumber->setSegmentStyle(QLCDNumber::Flat);
        focusNumber->setProperty("intValue", QVariant(1001));

        verticalLayout_6->addWidget(focusNumber);


        gridLayout->addLayout(verticalLayout_6, 3, 1, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        focus_tag = new QLabel(frame);
        focus_tag->setObjectName(QStringLiteral("focus_tag"));
        sizePolicy5.setHeightForWidth(focus_tag->sizePolicy().hasHeightForWidth());
        focus_tag->setSizePolicy(sizePolicy5);

        horizontalLayout->addWidget(focus_tag);

        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(comboBox);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 5);

        single_capture = new QPushButton(frame);
        single_capture->setObjectName(QStringLiteral("single_capture"));
        single_capture->setEnabled(false);
        sizePolicy6.setHeightForWidth(single_capture->sizePolicy().hasHeightForWidth());
        single_capture->setSizePolicy(sizePolicy6);

        gridLayout->addWidget(single_capture, 1, 0, 1, 2);


        verticalLayout_5->addWidget(frame);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(tabWidgetPage1);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        line_4 = new QFrame(tabWidgetPage1);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_4);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        last_calibration = new QPushButton(tabWidgetPage1);
        last_calibration->setObjectName(QStringLiteral("last_calibration"));
        last_calibration->setEnabled(false);
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(last_calibration->sizePolicy().hasHeightForWidth());
        last_calibration->setSizePolicy(sizePolicy7);

        horizontalLayout_6->addWidget(last_calibration);

        calibDir = new QLabel(tabWidgetPage1);
        calibDir->setObjectName(QStringLiteral("calibDir"));
        calibDir->setFrameShadow(QFrame::Plain);

        horizontalLayout_6->addWidget(calibDir);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        grid_calibration = new QPushButton(tabWidgetPage1);
        grid_calibration->setObjectName(QStringLiteral("grid_calibration"));
        grid_calibration->setEnabled(false);

        horizontalLayout_5->addWidget(grid_calibration);

        white_calibration = new QPushButton(tabWidgetPage1);
        white_calibration->setObjectName(QStringLiteral("white_calibration"));
        white_calibration->setEnabled(false);

        horizontalLayout_5->addWidget(white_calibration);

        dark_calibration = new QPushButton(tabWidgetPage1);
        dark_calibration->setObjectName(QStringLiteral("dark_calibration"));
        dark_calibration->setEnabled(false);

        horizontalLayout_5->addWidget(dark_calibration);


        verticalLayout_5->addLayout(horizontalLayout_5);

        start_Button = new QPushButton(tabWidgetPage1);
        start_Button->setObjectName(QStringLiteral("start_Button"));
        start_Button->setEnabled(false);
        sizePolicy.setHeightForWidth(start_Button->sizePolicy().hasHeightForWidth());
        start_Button->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(start_Button);

        progressBar = new QProgressBar(tabWidgetPage1);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(false);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(true);

        verticalLayout_5->addWidget(progressBar);

        mainTabs->addTab(tabWidgetPage1, QString());
        serial_settings->raise();
        line_3->raise();
        init_camera->raise();
        line->raise();
        line_2->raise();
        start_Button->raise();
        progressBar->raise();
        frame->raise();
        filterTab = new QWidget();
        filterTab->setObjectName(QStringLiteral("filterTab"));
        filterTab->setEnabled(false);
        gridLayout_3 = new QGridLayout(filterTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        filterData = new QTableWidget(filterTab);
        filterData->setObjectName(QStringLiteral("filterData"));
        filterData->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_3->addWidget(filterData, 0, 0, 1, 2);

        mainTabs->addTab(filterTab, QString());

        horizontalLayout_2->addWidget(mainTabs);

        Chroma->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Chroma);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Chroma->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Chroma);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Chroma->setStatusBar(statusBar);
        menuBar = new QMenuBar(Chroma);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 338, 21));
        menuDevice = new QMenu(menuBar);
        menuDevice->setObjectName(QStringLiteral("menuDevice"));
        Chroma->setMenuBar(menuBar);

        menuBar->addAction(menuDevice->menuAction());
        menuDevice->addAction(actionConfigure);
        menuDevice->addAction(actionConnect);
        menuDevice->addAction(actionDisconnect);
        menuDevice->addAction(actionAdvanced_Settings);

        retranslateUi(Chroma);

        mainTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Chroma);
    } // setupUi

    void retranslateUi(QMainWindow *Chroma)
    {
        Chroma->setWindowTitle(QApplication::translate("Chroma", "Camera", 0));
        actionConnect->setText(QApplication::translate("Chroma", "C&onnect", 0));
        actionConnect->setShortcut(QApplication::translate("Chroma", "Ctrl+O", 0));
        actionDisconnect->setText(QApplication::translate("Chroma", "&Disconnect", 0));
        actionDisconnect->setShortcut(QApplication::translate("Chroma", "Ctrl+D", 0));
        actionConfigure->setText(QApplication::translate("Chroma", "&Configure", 0));
        actionAdvanced_Settings->setText(QApplication::translate("Chroma", "Advanced Settings", 0));
        serial_settings->setText(QApplication::translate("Chroma", "Controller Settings", 0));
        serial_connect->setText(QApplication::translate("Chroma", "Connect", 0));
        serial_disconnect->setText(QApplication::translate("Chroma", "Disconnect", 0));
        init_camera->setText(QApplication::translate("Chroma", "Initialize Camera", 0));
        select_card->setText(QApplication::translate("Chroma", "Select Card", 0));
        new_card->setText(QApplication::translate("Chroma", "Create Card", 0));
        label_2->setText(QApplication::translate("Chroma", "Gain", 0));
        label_3->setText(QApplication::translate("Chroma", "Exposure", 0));
        label_10->setText(QApplication::translate("Chroma", "Current Settings:", 0));
        label_4->setText(QApplication::translate("Chroma", "Coarse Focus", 0));
        focus_in_coarse->setText(QApplication::translate("Chroma", "+", 0));
        focus_out_coarse->setText(QApplication::translate("Chroma", "-", 0));
        label_6->setText(QApplication::translate("Chroma", "Fine Focus", 0));
        focus_in_fine->setText(QApplication::translate("Chroma", "+", 0));
        focus_out_fine->setText(QApplication::translate("Chroma", "-", 0));
        lens_tag->setText(QApplication::translate("Chroma", "Lens Position", 0));
        label->setText(QApplication::translate("Chroma", "Focus Value", 0));
        focus_tag->setText(QApplication::translate("Chroma", "Filter", 0));
        single_capture->setText(QApplication::translate("Chroma", "Update Image", 0));
        label_5->setText(QApplication::translate("Chroma", "Calibration:", 0));
        last_calibration->setText(QApplication::translate("Chroma", "Use Last Calibration", 0));
        calibDir->setText(QApplication::translate("Chroma", ".//dir/file", 0));
        grid_calibration->setText(QApplication::translate("Chroma", "Grid", 0));
        white_calibration->setText(QApplication::translate("Chroma", "White", 0));
        dark_calibration->setText(QApplication::translate("Chroma", "Dark", 0));
        start_Button->setText(QApplication::translate("Chroma", "Start Collection", 0));
        mainTabs->setTabText(mainTabs->indexOf(tabWidgetPage1), QApplication::translate("Chroma", "Capture Settings", 0));
        mainTabs->setTabText(mainTabs->indexOf(filterTab), QApplication::translate("Chroma", "Filter Settings", 0));
        menuDevice->setTitle(QApplication::translate("Chroma", "Device", 0));
    } // retranslateUi

};

namespace Ui {
    class Chroma: public Ui_Chroma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHROMA_H
