#ifndef INTEGRATEDDISPLAY_H
#define INTEGRATEDDISPLAY_H
#include <camera.h>
#include <bcamera.h>
#include <bookprop.h>
#include <pageprop.h>

#include <QMainWindow>
#include <QtCore/QtGlobal>
#include <serialsettings.h>
#include <QFileDialog>
#include <QApplication>
#include <QStandardItem>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QObject>
#include <QTimer>
#include <QWidget>
#include <QLCDNumber>
#include <QEvent>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QApplication>
#include <QTime>

#include <pylon/PylonIncludes.h>
#include <pylon/PylonGUI.h>
#include <pylon/usb/BaslerUsbInstantCamera.h>
#include <iostream>

#include <opencv2/highgui/highgui.hpp>  //Needed for imshow
#include <opencv2/imgproc/imgproc.hpp>  //Needed for FFT/Lap/Canny/Gaussian
#include <opencv2/core/core.hpp>
#include <opencv2/photo/photo.hpp> //Needed for fastNIMeansDenoising

using namespace cv;
using namespace std;
typedef Pylon::CBaslerUsbInstantCamera Camera_t;
using namespace Basler_UsbCameraParams;
using namespace Pylon;

class QLabel;

QT_BEGIN_NAMESPACE

namespace Ui {
    class Chroma;
}

QT_END_NAMESPACE


double f_sobel(Mat & frame);
double f_canny(Mat & frame);
double f_lap (Mat & frame);
void f_dft(Mat & frame);

class SettingsDialog;

class MyXMLClass : public QWidget {

    Q_OBJECT

public:
    void SaveXMLFile();
    void ReadXMLFile();
    void ReadRoomElement();
    void ReadStateElement();
    void ReadPotencialElement();

};


class Chroma : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chroma(QWidget *parent = 0);
    ~Chroma();
    void displayLCD();

    void AutoGainOnce(Camera_t& camera);
    void AutoExposureOnce(Camera_t& camera);
    void newFrame();
    double AutoFocus();
    double cannyFocus();
    void readExposureSlider();
    void init_pylon();
    void commit_calibration(int i);
    void call_calibration(int i);
signals:
    void doubleValueChanged(double value);

public slots:

private slots:
    void f_capture();
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    int readData();
    void handleError(QSerialPort::SerialPortError error);
    void importCSVFile();
    void saveCSVFile();
    QString readCellContents(int x,int y);
    void writeCellContents(int x, int y, QString value);
    void on_loadCalibration_button_clicked();
    void on_pushButton_clicked();


    void on_start_Button_clicked();
    void on_init_camera_clicked();
    void bookPropCard();
    void bookPropNew();
    void pagePropNew();

    void on_grid_calibration_clicked();

    void on_select_card_clicked();

    void on_serial_connect_clicked();

    void on_serial_settings_clicked();

private:
    Ui::Chroma *ui;
    void initActionsConnections();
    QLabel *status;
    SettingsDialog *settings;
    BookProp *card;
    PageProp *leaf;
    QSerialPort *serial;
    void showStatusMessage(const QString &message);

private:
    bool setup; 
};

#endif // IntegratedDisplay_H
