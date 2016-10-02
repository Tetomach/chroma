#include "chroma.h"
#include "bcamera.h"
#include "ui_chroma.h"
#include "bookprop.h"
#include "serialsettings.h"

int lamdaProto [17] = {340,375,400,425,450,500,550,600,650,700,750,800,850,900,950,1000,1050};

double focusMeasure = 0;

// ** GLOBAL SERIAL COMMAND STRINGS ** //

QByteArray center_wheel = "center_wheel";
QByteArray wheel_f = "wheel_f";
QByteArray focus_status = "focus_s";
QByteArray focus_in = "focus_in";
QByteArray focus_out = "focus_out";

int collection_counter = 0;

int inst_current_exposure;
double current_gain;
int current_focus;


double target_brightness_gain = 0.4;
double target_brightness_exp = 0.4;
///GLOBAL FUNCTIONS

///************* FOCUS CALCUATION ********************///
double f_canny(Mat & frame){
    unsigned long int sum = 0;
    Mat edges = frame.clone();
    cv::GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
    cv::Canny(edges, edges, 0, 30, 3);
    MatIterator_<uchar> it, end;
    for (it = edges.begin<uchar>(), end = edges.end<uchar>(); it != end; ++it)
    {
        sum += *it != 0;
    }
    return sum;
}

double f_lap (Mat & frame){
    Mat lapf = Mat(frame.rows,frame.cols,CV_64F);
    cv::Laplacian(frame, lapf, CV_64F);
    cv::Scalar mu, sigma;
    cv::meanStdDev(lapf, mu, sigma);
    double sigma_square = sigma.val[0] * sigma.val[0];
    cout << sigma_square << "  :Sigma^2" << endl;
    return sigma_square;
}

double f_sobel(Mat & frame){
        Mat Gx, Gy;
        cv::Sobel( frame, Gx, CV_32F, 1, 0 );
        cv::Sobel( frame, Gy, CV_32F, 0, 1 );
        double normGx = norm( Gx );
        double normGy = norm( Gy );
        double sumSq = normGx * normGx + normGy * normGy;
        double sobel = ( sumSq / frame.size().area());
        return sobel;
}

void f_dft(Mat & frame){
   Mat I = frame.clone();
   Mat padded;                            //expand input image to optimal size
   int m = getOptimalDFTSize( I.rows );
   int n = getOptimalDFTSize( I.cols ); // on the border add zero values
   copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

   Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
   Mat complexI;
   merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

   dft(complexI, complexI);            // this way the result may fit in the source matrix

   // compute the magnitude and switch to logarithmic scale
   // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
   split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
   magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
   Mat magI = planes[0];

   magI += Scalar::all(1);                    // switch to logarithmic scale
   log(magI, magI);

   // crop the spectrum, if it has an odd number of rows or columns
   magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));

   // rearrange the quadrants of Fourier image  so that the origin is at the image center
   int cx = magI.cols/2;
   int cy = magI.rows/2;

   Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
   Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
   Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
   Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right

   Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
   q0.copyTo(tmp);
   q3.copyTo(q0);
   tmp.copyTo(q3);

   q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
   q2.copyTo(q1);
   tmp.copyTo(q2);

   normalize(magI, magI, 0, 1, CV_MINMAX); // Transform the matrix with float values into a
                                           // viewable image form (float between values 0 and 1).
   cv::resize(magI,magI,Size(1280,1024),INTER_CUBIC);
   cvNamedWindow("spectrum magnitude",CV_WINDOW_NORMAL | CV_GUI_EXPANDED);
   imshow("spectrum magnitude", magI);
}

void delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void MyXMLClass::SaveXMLFile()
{

    QString filename = QFileDialog::getSaveFileName(this,("Save Xml"), ".",
                                       ("Xml files (*.xml)"));


    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("LAMPS");

    xmlWriter.writeStartElement("LIGHT1");
    xmlWriter.writeTextElement("State", "statevalue" );
    xmlWriter.writeTextElement("Room", "roomvalue");
    xmlWriter.writeTextElement("Potencial", "potencialvalue");

    xmlWriter.writeEndElement();

        file.close();
}

void MyXMLClass::ReadXMLFile()
{
        QXmlStreamReader Rxml;

        QString filename = QFileDialog::getOpenFileName(this,
                                   ("Open Xml"), ".",
                                   ("Xml files (*.xml)"));

    QFile file(filename);
        if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        std::cerr << "Error: Cannot read file " << qPrintable(filename)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;

    }

    Rxml.setDevice(&file);
    Rxml.readNext();

    while(!Rxml.atEnd())
    {
        if(Rxml.isStartElement())
        {
            if(Rxml.name() == "LAMPS")
            {
                Rxml.readNext();
            }
            else if(Rxml.name() == "LIGHT1")
            {
                while(!Rxml.atEnd())
                            {
                             if(Rxml.isEndElement())
                             {
                             Rxml.readNext();
                             break;
                             }
                             else if(Rxml.isCharacters())
                             {
                             Rxml.readNext();
                             }
                             else if(Rxml.isStartElement())
                             {
                             if(Rxml.name() == "State")
                             {
                              ReadStateElement();
                             }
                             else if(Rxml.name() == "Room")
                             {
                              ReadRoomElement();
                             }
                             else if(Rxml.name() == "Potencial")
                             {
                                  ReadPotencialElement();
                             }
                             Rxml.readNext();
                         }
                         else
                         {
                         Rxml.readNext();
                         }
                    }
            }
        }
    else
    {
        Rxml.readNext();
    }

    file.close();

        if (Rxml.hasError())
    {
       std::cerr << "Error: Failed to parse file "
                 << qPrintable(filename) << ": "
                 << qPrintable(Rxml.errorString()) << std::endl;
        }
    else if (file.error() != QFile::NoError)
    {
        std::cerr << "Error: Cannot read file " << qPrintable(filename)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
    }
}

}

//Example for Room Element

void MyXMLClass::ReadRoomElement()
{
    QXmlStreamReader Rxml;

    while(!Rxml.atEnd())
    {
        if(Rxml.isEndElement())
        {
            Rxml.readNext();
            break;
        }
        else if(Rxml.isStartElement())
        {
            QString roomelement = Rxml.readElementText();   //Get the xml value
            Rxml.readNext();
            break;
        }
        else if(Rxml.isCharacters())
        {
            Rxml.readNext();
        }
        else
        {
            Rxml.readNext();
        }
    }

}

void MyXMLClass::ReadStateElement()
{
    QXmlStreamReader Rxml;

    while(!Rxml.atEnd())
    {
        if(Rxml.isEndElement())
        {
            Rxml.readNext();
            break;
        }
        else if(Rxml.isStartElement())
        {
            QString stateElement = Rxml.readElementText();   //Get the xml value
            Rxml.readNext();
            break;
        }
        else if(Rxml.isCharacters())
        {
            Rxml.readNext();
        }
        else
        {
            Rxml.readNext();
        }
    }

}

void MyXMLClass::ReadPotencialElement()
{
    QXmlStreamReader Rxml;

    while(!Rxml.atEnd())
    {
        if(Rxml.isEndElement())
        {
            Rxml.readNext();
            break;
        }
        else if(Rxml.isStartElement())
        {
            QString potencialElement = Rxml.readElementText();   //Get the xml value
            Rxml.readNext();
            break;
        }
        else if(Rxml.isCharacters())
        {
            Rxml.readNext();
        }
        else
        {
            Rxml.readNext();
        }
    }

}

/// MAIN CLASS CHROMA ///
Chroma::Chroma(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Chroma)
{
    ui->setupUi(this);
    /// Serial Object Creation with pointer -- fixed error here
    serial = new QSerialPort(this);
    card = new BookProp;
    settings = new SettingsDialog;

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    QStringList headers;
    ui->filterData->setColumnCount(6);
    ui->filterData->setRowCount(18);
    headers << "Wave Length" << "Exposure" << "Gain" << "Focus" << "Response" << "Filter Name";
    ui->filterData->setHorizontalHeaderLabels(headers); // apply the column names listed in 'headers'
    ui->filterData->setSortingEnabled(false); //disable the sorting method for the table
    status = new QLabel;
    ui->statusBar->addWidget(status);
    initActionsConnections(); //System Dialog for Serial module

    ///Slot Connections
    connect(serial, static_cast < void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),this, &Chroma::handleError);
    connect(serial, &QSerialPort::readyRead, this, &Chroma::readData);
    connect(ui->single_capture,SIGNAL(clicked()),this, SLOT(f_capture()));

    connect(ui->new_card,SIGNAL(clicked()), this, SLOT (bookPropNew()));


    ///Button State
    ui->serial_disconnect->setEnabled(false);
    ui->init_camera->setEnabled(false);
    ui->select_card->setEnabled(false);
    ui->new_card->setEnabled(false);
    ui->single_capture->setEnabled(false);
    ui->start_Button->setEnabled(false);

}

Chroma::~Chroma()
{
    delete ui;
}

///GLOBAL CLASS VARIABLES
Camera_t* camera; // GLOBAL POINTER TO CAMERA OBJECT
CImageFormatConverter fc; // GLOBAL POINTER TO CONVERTER OBJECT
CPylonImage bimage;
CGrabResultPtr ptrGrabResult;
Mat temp;
Mat frame;
int a_frames = 2; //number of itterations to accumulate for noise reduction

///ACTION ITEMS
void Chroma::AutoGainOnce(Camera_t& camera)
{
    // Maximize the grabbed image area of interest (Image AOI).

    camera.OffsetX.SetValue(camera.OffsetX.GetMin());
    camera.OffsetY.SetValue(camera.OffsetY.GetMin());

    camera.Width.SetValue(camera.Width.GetMax());
    camera.Height.SetValue(camera.Height.GetMax());

    if(IsAvailable(camera.AutoFunctionROISelector))
    {
        // Set the Auto Function ROI for luminance statistics.
        // We want to use ROI1 for gathering the statistics
        camera.AutoFunctionROISelector.SetValue(AutoFunctionROISelector_ROI1);
        camera.AutoFunctionROIUseBrightness.SetValue(true);   // ROI 1 is used for brightness control
        camera.AutoFunctionROISelector.SetValue(AutoFunctionROISelector_ROI2);
        camera.AutoFunctionROIUseBrightness.SetValue(false);   // ROI 2 is not used for brightness control

        // Set the ROI (in this example the complete sensor is used)
        camera.AutoFunctionROISelector.SetValue(AutoFunctionROISelector_ROI1);  // configure ROI 1
        camera.AutoFunctionROIOffsetX.SetValue(0);
        camera.AutoFunctionROIOffsetY.SetValue(0);
        camera.AutoFunctionROIWidth.SetValue(camera.Width.GetMax());
        camera.AutoFunctionROIHeight.SetValue(camera.Height.GetMax());
    }


    // Set the target value for luminance control.
    camera.AutoTargetBrightness.SetValue(target_brightness_gain);

    // We are going to try GainAuto = Once.

    camera.Gain.GetValue();

    // Set the gain ranges for luminance control.
    camera.AutoGainLowerLimit.SetValue(camera.Gain.GetMin());
    camera.AutoGainUpperLimit.SetValue(camera.Gain.GetMax());

    camera.GainAuto.SetValue(GainAuto_Once);

    int n = 0;
    while (camera.GainAuto.GetValue() != GainAuto_Off)
    {
        CGrabResultPtr ptrGrabResult;
        camera.GrabOne( 5000, ptrGrabResult);

        ++n;
        //For demonstration purposes only. Wait until the image is shown.
        WaitObject::Sleep(100);

        //Make sure the loop is exited.
        if (n > 100)
        {
            ///throw RUNTIME_EXCEPTION( "The adjustment of auto gain did not finish.");
        }
    }

    cout << "GainAuto went back to 'Off' after " << n << " frames." << endl;
    cout << "Final Gain = " << camera.Gain.GetValue() << endl << endl;
}

void Chroma::AutoExposureOnce(Camera_t& camera)
{

    camera.OffsetX.SetValue(camera.OffsetX.GetMin());
    camera.OffsetY.SetValue(camera.OffsetY.GetMin());

    camera.Width.SetValue(camera.Width.GetMax());
    camera.Height.SetValue(camera.Height.GetMax());

    if(IsAvailable(camera.AutoFunctionROISelector))
    {
        // Set the Auto Function ROI for luminance statistics.
        // We want to use ROI1 for gathering the statistics.
        camera.AutoFunctionROISelector.SetValue(AutoFunctionROISelector_ROI1);
        camera.AutoFunctionROIUseBrightness.SetValue(true);   // ROI 1 is used for brightness control
        camera.AutoFunctionROISelector.SetValue(AutoFunctionROISelector_ROI2);
        camera.AutoFunctionROIUseBrightness.SetValue(false);   // ROI 2 is not used for brightness control

        // Set the ROI (in this example the complete sensor is used)
        camera.AutoFunctionROISelector.SetValue(AutoFunctionROISelector_ROI1);  // configure ROI 1
        camera.AutoFunctionROIOffsetX.SetValue(0);
        camera.AutoFunctionROIOffsetY.SetValue(0);
        camera.AutoFunctionROIWidth.SetValue(camera.Width.GetMax());
        camera.AutoFunctionROIHeight.SetValue(camera.Height.GetMax());
    }

    camera.AutoTargetBrightness.SetValue(target_brightness_exp);

    // Try ExposureAuto = Once.
    cout << "Trying 'ExposureAuto = Once'." << endl;
    cout << "Initial exposure time = ";
    cout << camera.ExposureTime.GetValue() << " us" << endl;

    // Set the exposure time ranges for luminance control.
    camera.AutoExposureTimeLowerLimit.SetValue(camera.AutoExposureTimeLowerLimit.GetMin());
    camera.AutoExposureTimeUpperLimit.SetValue(camera.AutoExposureTimeLowerLimit.GetMax());

    camera.ExposureAuto.SetValue(ExposureAuto_Once);

    int n = 0;
    while (camera.ExposureAuto.GetValue() != ExposureAuto_Off)
    {
        CGrabResultPtr ptrGrabResult;
        camera.GrabOne( 5000, ptrGrabResult);
        ++n;
        //Make sure the loop is exited.
        if (n > 100)
        {
            /// FAILURE TO GENERATE DESIRED NUMBER
            ///throw RUNTIME_EXCEPTION( "The adjustment of auto exposure did not finish.");
        }
    }
    cout << "ExposureAuto went back to 'Off' after " << n << " frames." << endl;
    cout << "Final exposure time = ";
    cout << camera.ExposureTime.GetValue() << " us" << endl << endl;
}


/// OPENCV FUNCTION ::>
/// fastNlMeansDenoising  //used to denoise with local content, single sample

// TODO** FIX SENDING STEP COMMANDS WITH focus_in/focus_out
double Chroma::AutoFocus(){

    vector<double> focusvalue;
    int duration = 2000;
    bool focusMax = false;

    QByteArray g_step = "2"; //itteration step scaling <--not used yet

    while(!focusMax){
        /// FRAME 1
        f_capture();
        focusvalue.push_back(focusMeasure);
        /// FRAME 2
        Chroma::writeData(focus_in);
        Chroma::writeData(g_step);
        delay(duration);
        f_capture();
        focusvalue.push_back(focusMeasure);
        /// FRAME 3
        for (int i=0; i < 2; ++i){
            Chroma::writeData(focus_out);
            Chroma::writeData(g_step);
            delay(duration);
        }
        f_capture();
        focusvalue.push_back(focusMeasure);
        /// SORTING METHOD

        cout << focusvalue[0] << "Focus Center" << endl;
        cout << focusvalue[1] << "Focus Forward" << endl;
        cout << focusvalue[2] << "Focus Back" << endl;
        cout << (focusvalue[1] > focusvalue[0]) << " : In focus condition" << endl;
        cout << (focusvalue[2] > focusvalue[0]) << " : Out focus condition" << endl;

        if ((focusvalue[1]) > (focusvalue[0]) && (focusvalue[1] > focusvalue[2])) {
            cout << "RUN IN FOCUS" << endl;
            int x =1;
            int y =0;
            for (int i=0; i < 2; ++i){
                Chroma::writeData(focus_in);
                Chroma::writeData(g_step);
                delay(duration);
            }
            while ((focusvalue[x]) > (focusvalue[y])){
                cout << "IN FOCUS WHILE CASE" << endl;
                cout << focusvalue[x] << " <- FVal x" << endl;
                cout << focusvalue[y] << " <- FVal y" << endl;
                Chroma::writeData(focus_in);
                Chroma::writeData(g_step);
                delay(duration);

                f_capture();
                focusvalue.push_back(focusMeasure);

                ++x;
                ++y;
                cout << "itteration count for focus_in : " << y << endl;
                cout << ( focusvalue[x] > focusvalue[y] ) << " :Current Condition" << endl;
            }
            cout << focusvalue[x] << " <- FVal New" << endl;
            cout << focusvalue[y] << " <- FVal Old" << endl;
            cout << ( focusvalue[x] > focusvalue[y] ) << " :Current Condition" << endl;

            Chroma::writeData(focus_out);
            Chroma::writeData(g_step);
            focusMax = true;

        }
        else if ((focusvalue[2] > focusvalue[0]))
        {
            cout << "RUN OUT FOCUS" << endl;
            int x =2;
            int y =0;

            while ((focusvalue[x]) > (focusvalue[y])){
                cout << "OUT FOCUS WHILE CASE" << endl;
                cout << focusvalue[x] << " <- FVal x" << endl;
                cout << focusvalue[y] << " <- FVal y" << endl;

                Chroma::writeData(focus_out);
                Chroma::writeData(g_step);
                delay(duration);

                f_capture();
                focusvalue.push_back(focusMeasure);

                ++x;
                ++y;
                cout << "itteration count for focus_out : " << y << endl;
                cout << ( focusvalue[x] > focusvalue[y] ) << " :Current Condition" << endl;

            }
            cout << focusvalue[x] << " <- FVal New" << endl;
            cout << focusvalue[y] << " <- FVal Old" << endl;
            cout << ( focusvalue[x] > focusvalue[y] ) << " :Current Condition" << endl;

            Chroma::writeData(focus_in);
            Chroma::writeData(g_step);
            focusMax = true;

        }
        else {
            focusMax = true;
            Chroma::writeData(focus_in);
            Chroma::writeData(g_step);
        }

    }


    /// ### PSUDO: ARDUINO.GET(FOCUS_WHEEL_POSITION);
    /// return FOCUS_WHEEL_POSITION; // -- int <-- need to change return type

    return focusMeasure;
    // ##Needs to Return ARDUINO FOCUS NUMBER!!
}

double Chroma::cannyFocus(){

    vector<double> focusvalue;
    int duration = 2000;
    bool focusMax = false;

    QByteArray g_step = "2"; //itteration step scaling <--not used yet

    while(!focusMax){
        /// FRAME 1
        f_capture();
        focusvalue.push_back(focusMeasure); //store
        /// FRAME 2
        Chroma::writeData(focus_in);
        Chroma::writeData(g_step);
        /// NEED ALT IMPIMENTATION FOR PARSE RETURN!
        delay(duration); //WAIT RETURN INSTEAD???****
        f_capture();
        focusvalue.push_back(focusMeasure);
        /// FRAME 3
        for (int i=0; i < 2; ++i){
            Chroma::writeData(focus_out);
            Chroma::writeData(g_step);
            delay(duration);
        }
        f_capture();
        focusvalue.push_back(focusMeasure);
        /// SORTING METHOD

        cout << focusvalue[0] << "Focus Center" << endl;
        cout << focusvalue[1] << "Focus Forward" << endl;
        cout << focusvalue[2] << "Focus Back" << endl;
        cout << (focusvalue[1] > focusvalue[0]) << " : In focus condition" << endl;
        cout << (focusvalue[2] > focusvalue[0]) << " : Out focus condition" << endl;

        if ((focusvalue[1]) > (focusvalue[0]) && (focusvalue[1] > focusvalue[2])) {
            cout << "RUN IN FOCUS" << endl;
            int x =1;
            int y =0;
            for (int i=0; i < 2; ++i){
                Chroma::writeData(focus_in);
                Chroma::writeData(g_step);
                delay(duration);
            }
            while ((focusvalue[x]) > (focusvalue[y])){
                cout << "IN FOCUS WHILE CASE" << endl;
                cout << focusvalue[x] << " <- FVal x" << endl;
                cout << focusvalue[y] << " <- FVal y" << endl;
                Chroma::writeData(focus_in);
                Chroma::writeData(g_step);
                delay(duration);

                f_capture();
                focusvalue.push_back(focusMeasure);

                ++x;
                ++y;
                cout << "itteration count for focus_in : " << y << endl;
                cout << ( focusvalue[x] > focusvalue[y] ) << " :Current Condition" << endl;
            }
            cout << focusvalue[x] << " <- FVal New" << endl;
            cout << focusvalue[y] << " <- FVal Old" << endl;
            cout << ( focusvalue[x] > focusvalue[y] ) << " :Current Condition" << endl;

            Chroma::writeData(focus_out);
            Chroma::writeData(g_step);
            focusMax = true;

        }
        else if ((focusvalue[2] > focusvalue[0]))
        {
            cout << "RUN OUT FOCUS" << endl;
            int x =2;
            int y =0;

            while ((focusvalue[x]) > (focusvalue[y])){
                cout << "OUT FOCUS WHILE CASE" << endl;
                cout << focusvalue[x] << " <- FVal x" << endl;
                cout << focusvalue[y] << " <- FVal y" << endl;

                Chroma::writeData(focus_out);
                Chroma::writeData(g_step);
                delay(duration);

                f_capture();
                focusvalue.push_back(focusMeasure);

                ++x;
                ++y;
                cout << "itteration count for focus_out : " << y << endl;
                cout << ( focusvalue[x] > focusvalue[y] ) << " :Current Condition" << endl;

            }
            cout << focusvalue[x] << " <- FVal New" << endl;
            cout << focusvalue[y] << " <- FVal Old" << endl;
            cout << ( focusvalue[x] > focusvalue[y] ) << " :Current Condition" << endl;

            Chroma::writeData(focus_in);
            Chroma::writeData(g_step);
            focusMax = true;

        }
        else {
            focusMax = true;
            Chroma::writeData(focus_in);
            Chroma::writeData(g_step);
        }

    }


    /// ### PSUDO: ARDUINO.GET(FOCUS_WHEEL_POSITION);
    /// return FOCUS_WHEEL_POSITION; // -- int <-- need to change return type

    return focusMeasure;
    // ##Needs to Return ARDUINO FOCUS NUMBER!!
}

void Chroma::on_init_camera_clicked()
{
    init_pylon();
    ui->init_camera->setEnabled(false);
    ui->select_card->setEnabled(true);
    ui->new_card->setEnabled(true);
}

void Chroma::init_pylon(){
    QByteArray center = "c";
    QByteArray home = "h";
    Chroma::writeData(home); //Center the Camera lens
    delay (1000);
    Chroma::writeData(center); //Center the Camera lens

    CDeviceInfo info;
    info.SetDeviceClass( Camera_t::DeviceClass());
    camera = new Camera_t (CTlFactory::GetInstance().CreateFirstDevice( info));
    cout << "GENERATE CAMERA" << endl;
    fc.OutputPixelFormat = PixelType_Mono8; //set fc conversion output for cv mat
    cout << "Open" << endl;
    camera->Open();
    camera->MaxNumBuffer = 10;
    camera->PixelFormat.SetValue(PixelFormat_Mono12);

    camera->AutoFunctionROIWidth.SetValue(camera->Width.GetMax());
    camera->AutoFunctionROIHeight.SetValue(camera->Height.GetMax());

    ui->select_card->setEnabled(true);
    ui->new_card->setEnabled(true);
    ui->start_Button->setEnabled(true);
    ui->single_capture->setEnabled(true);
    ui->init_camera->setEnabled(false);
}

void Chroma::newFrame(){

    camera->Open();
    camera->MaxNumBuffer = 10;
    camera->PixelFormat.SetValue(PixelFormat_Mono12);

    camera->AutoFunctionROIWidth.SetValue(camera->Width.GetMax());
    camera->AutoFunctionROIHeight.SetValue(camera->Height.GetMax());

    ///** TODO ## SHOW IN STATUS BAR
    cout << "Using device " << camera->GetDeviceInfo().GetModelName() << endl;


    AutoGainOnce(*camera);
    AutoExposureOnce(*camera);

    // Default Startup Settings ::>

    cout << "The Best Focus is : " <<  AutoFocus() << endl;

    // camera->Close(); //only necessay if camera not going to be used again
    cout << "close camera" << endl;

}

void Chroma::f_capture(){
    cout << "F-capture" << endl;


    Mat accumulator = Mat::zeros(camera->Height.GetMax(),camera->Width.GetMax() ,CV_64F); //STORAGE

    for(int i=0 ; i< a_frames ;++i){
        camera->GrabOne(10000,ptrGrabResult);
        /// ** UI LOCKOUT and CAPTURE PROGRESS BAR (widget panel ui)
        if (ptrGrabResult->GrabSucceeded())
        {
            fc.Convert(bimage, ptrGrabResult);
            temp = cv::Mat(ptrGrabResult->GetHeight(),ptrGrabResult->GetWidth(),CV_8U,(uint8_t*)bimage.GetBuffer(), Mat::AUTO_STEP);
            accumulate(temp,accumulator);
        }
    }
    accumulator = accumulator / a_frames;
    accumulator.convertTo(accumulator,CV_8U);

    // cv::fastNlMeansDenoising(accumulator,accumulator,2,7,21); //local means denoising [src,targe,agressiveness,templatesize,windowsize]

    focusMeasure = f_canny(accumulator);
    cv::resize(accumulator,frame,Size(1280,1024),INTER_CUBIC);
    cvNamedWindow("camera",CV_WINDOW_NORMAL | CV_GUI_NORMAL);
    cv::imshow("camera",frame);
    ui->focusNumber->display(focusMeasure);
    ui->gainSpin->setValue(camera->Gain.GetValue());
    ui->expSpin->setValue(camera->ExposureTime.GetValue());
}


/// **SERIAL CONTROL ///
void Chroma::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}

void Chroma::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}

void Chroma::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

void Chroma::writeData(const QByteArray &data)
{
    serial->write(data);
}

int Chroma::readData()
{
    bool ok;
    int parse_data;
    QByteArray data = serial->readAll();
    parse_data = data.toInt(&ok,10);
    if (ok){
    return (parse_data);
    }
    else{
        // GENERATE A STRING TIMEOUT ERROR ON THE SERAL
    QMessageBox::critical(this, tr("Serial Communcation Error"), (" Invaid Data Receved!"));
    return(0);
    }
}

void Chroma::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Serial Device Error : Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void Chroma::initActionsConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &Chroma::openSerialPort);
    connect(ui->actionDisconnect, &QAction::triggered, this, &Chroma::closeSerialPort);
    connect(ui->actionConfigure, &QAction::triggered, settings, &Chroma::show);

}

void Chroma::showStatusMessage(const QString &message)
{
    status->setText(message);
}


/// SERIAL CONTROL** ///

void Chroma::importCSVFile(){  // Loaded on connection with wheel device -- could read the device description and select from an array of configuration files (file should be edited externally)
    QString data;
    QFile importedCSV("base.csv");
    QStringList rowOfData;
    QStringList rowData;
    data.clear();
    rowOfData.clear();
    rowData.clear();
    if (importedCSV.open(QFile::ReadOnly))
    {
        data = importedCSV.readAll();
        rowOfData = data.split("\n");           //Value on each row
        importedCSV.close();
    }
    for (int x = 0; x < rowOfData.size(); x++)  //rowOfData.size() gives the number of row
    {
        rowData = rowOfData.at(x).split(",");   //Number of collumn
        // int r=rowData.size();
        for (int y = 0; y < rowData.size(); y++)
        {
            ui->filterData->setItem(x-1,y,new QTableWidgetItem(rowData[y]));;
        }
    }
    statusBar()->showMessage(tr("File successfully loaded."), 3000);
}

void Chroma::saveCSVFile(){ // function not fully operational, but not used in current implimentation
    QFile file = QFileDialog::getSaveFileName(this, ("Save File"), NULL, ("csv File(*.csv)"));
    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream data( &file );
        QStringList strList;
        for( int c = 0; c < ui->filterData->columnCount(); c++ )
        {
            strList << "\" " +
                       ui->filterData->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString()
                       + "\" ";
        }

        data << strList.join(",") << "\n";

        statusBar()->showMessage(tr("File saved successfully."), 3000);
        file.close();
    }
}

void Chroma::on_loadCalibration_button_clicked()
{
    Chroma::importCSVFile();
}

void Chroma::on_pushButton_clicked()
{
    Chroma::saveCSVFile();
}

QString Chroma::readCellContents(int x, int y)
{
        QString itabtext = ui->filterData->item(x,y)->text();
        return itabtext;
}

void Chroma::writeCellContents(int x,int y, QString value)
{
    QTableWidgetItem *setdes = new QTableWidgetItem;
    setdes->setText(value);
    ui->filterData->setItem(x,y,setdes);
}


/// CARD FUCTIONS ///

void Chroma::bookPropNew()
{
    card->show();
    QFile file ("out.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
              return;
//    QTextStream out(&file);
//    out   << "NAME: "  <<
//       BookProp::Card.name << "\n"
//          << "ID NUMBER: "  <<
//       BookProp::Card.indexNumber << "\n"
//          << "OWNER: "  <<
//       BookProp::Card.bookOwner << "\n"
//         << "NOTES: "  <<
//       BookProp::Card.bookNotes << "\n";

}

void Chroma::pagePropNew()
{
    leaf->show();
}

void Chroma::bookPropCard()
{
    QDir dir("path/to/dir");
    if (dir.exists()) {   //check if directory exists (bool)
         QMessageBox::critical(this, tr("File Name Error "), ("card directory already exists!"));
         // **TODO::* display an error if the no directory
    }
}


/// PROTOTYPE FOR READING CELL VALUES FROM TABLE
/// QString itabtext = filterData->item(0,0)->text();


void Chroma::displayLCD(){
    ui->focusNumber->display(focusMeasure);
}

void Chroma::on_start_Button_clicked()
{
    // TODO** POPUP DIALOGUE FOR COLLECTION PAGE NUMBER INFORMATION
    int n =0; //current filter number "device file row element"
    double desired_gain;
    int desired_exposure;
    for (int i=1;i<17;i++){
        bool check_g = false;
        bool check_e = false;
        QString local_gain = (Chroma::readCellContents(2,n));
        QString local_exposure = (Chroma::readCellContents(1,n));
        desired_gain = local_gain.toDouble(&check_g);
        desired_exposure = local_exposure.toInt(&check_e);
        camera->Gain.SetValue(desired_gain);
        camera->ExposureTime.SetValue(desired_exposure);
        // f_cap_save('pass_card_info'); // GIVE DIRECTORY NAME AND
    }

}


void Chroma::commit_calibration(int i){ //export current values stored in memory to the storage cell array
    QString l_exp = QString::number(inst_current_exposure);
    QString l_gain = QString::number(current_gain);
    QString l_focus = QString::number(current_focus);
    writeCellContents(i,1,l_exp);
    writeCellContents(i,2,l_gain);
    writeCellContents(i,3,l_focus);
}

void Chroma::call_calibration(int i){
    bool good_exp = false;
    bool good_gain= false;
    bool good_focus= false;
    QString c_exp = readCellContents(i,1);
    QString c_gain = readCellContents(i,2);
    QString c_focus = readCellContents(i,3);

    if (good_exp && good_gain && good_focus){
        inst_current_exposure = c_exp.toDouble(&good_exp);
        current_gain= c_gain.toDouble(&good_gain);
        current_focus= c_focus.toDouble(&good_focus);
    }
    else{
        QString bad_convert ="Conversion Error From Table, Values may be invalid";
        showStatusMessage(bad_convert);
        // POSSIBLE NEED TO EXIT ON FAILED CONVERSION -- DISPLAY ADDED AS DIAGNOSTIC
    }
}

void Chroma::on_grid_calibration_clicked()
{
    // TODO** POPUP DIALOGUE FOR CALIBRATION DATASET NAME?
    writeData(center_wheel);
    writeData(wheel_f);
    for(int i=1;i<17;i++){
     AutoExposureOnce(*camera);
     inst_current_exposure = (camera->ExposureTime.GetValue());
     AutoGainOnce(*camera);
     current_gain = (camera->Gain.GetValue());
     AutoFocus();
     writeData(focus_status);
     delay(5);
            //wait for arduino -- IS THERE AN ALTERNATIVE IMPLIMENTATION??
            //something like wait until "response receved"
     current_focus = readData();
     Chroma::commit_calibration(i); //
    }
}

void Chroma::on_select_card_clicked()
{
     QString fileName = QFileDialog::getOpenFileName(this, ("Open File"), NULL, ("csv File(*.csv)"));
}

void Chroma::on_serial_connect_clicked()
{
    ui->filterTab->setEnabled(true);
    importCSVFile();
    Chroma::openSerialPort();
    ui->serial_settings->setEnabled(false);
    ui->serial_connect->setEnabled(false);
    ui->serial_disconnect->setEnabled(true);
    ui->init_camera->setEnabled(true);
}

void Chroma::on_serial_settings_clicked()
{
    settings->show();
}
