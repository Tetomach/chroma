#include "camera.h"

#include <QMessageBox>
#include <QPalette>
#include <QtWidgets>
#include <chroma.h>

#define saveImages 1  //SAVE IMAGE TOGGLE

//Camera Parameter Space ** NEED UI LINK//
int desired_gain = 15;
int desired_exposure = 10000;

// AIO PARAMETERS ** NEED UI LINK
int width_scale = 1;
int height_scale = 1;

bool aoi = false; //*** LINK TO #AIO Box

static const uint32_t c_countOfImagesToGrab = 1; //Captures Per Call of GRAB

void pylon_setup(Camera_t& bcamera)
{
      // PYLON SPACE AND INSTANT CAMERA

      bcamera.Open(); // Open the camera.
      bcamera.MaxNumBuffer = 10;
      bcamera.PixelFormat.SetValue(PixelFormat_Mono12);

      //***CHANGE THIS IT SHOW CAMERA DEVICE IDENTIFIER IN UI
      cout << "Using device " << bcamera.GetDeviceInfo().GetModelName() << endl;

      //***CHAGE aio bool to radio box and menu values for
      if (aoi == true){
      // Capture AOI Settings -- check if the AOI is Writable and recover the value of the minimum offset
          if (IsWritable(bcamera.OffsetX))
          {
              bcamera.OffsetX.SetValue(bcamera.OffsetX.GetMin());
          }
          if (IsWritable(bcamera.OffsetY))
          {
              bcamera.OffsetY.SetValue(bcamera.OffsetY.GetMin());
          }

          // Some properties have restrictions. Use GetInc/GetMin/GetMax to make sure you set a valid value.
          int64_t newWidth = width_scale;
          newWidth = Adjust(newWidth, bcamera.Width.GetMin(), bcamera.Width.GetMax(), bcamera.Width.GetInc());

          int64_t newHeight = height_scale;
          newHeight = Adjust(newHeight, bcamera.Height.GetMin(), bcamera.Height.GetMax(), bcamera.Height.GetInc());

          bcamera.Width.SetValue(newWidth);
          bcamera.Height.SetValue(newHeight);
       }
      else{
          bcamera.Width.SetValue(bcamera.Width.GetMax());
          bcamera.Height.SetValue(bcamera.Height.GetMax());
      }

     bcamera.GainAuto.SetValue(GainAuto_Once);
//---  SET GAIN VALUE bcamera.Gain.SetValue(desired_gain);
     bcamera.ExposureAuto.SetValue(ExposureAuto_Once);
     // bcamera.ExposureTime.SetValue(desired_exposure);
     }

void capsave(Camera_t& bcamera){

    try {
      bcamera.StartGrabbing(c_countOfImagesToGrab);
      CGrabResultPtr ptrGrabResult;

      while (bcamera.IsGrabbing())
      {
         /// bcamera.GrabOne(500,prtGrabResult,null);
         /// ^^^ Alternate Grab?
          // Wait for an image and then retrieve it. A timeout of 5000 ms is used.
          bcamera.RetrieveResult( 5000, ptrGrabResult, TimeoutHandling_ThrowException);
              // Display the grabbed image.
              Pylon::DisplayImage(1, ptrGrabResult);
              CPylonImage image;
              image.AttachGrabResultBuffer( ptrGrabResult);
              CImagePersistence::Save( ImageFileFormat_Tiff, "MandelbrotFractal.tiff", image);
          }
         if(ptrGrabResult->GrabSucceeded())
         {

         }
          else
          {
          //****NEEDS ERROR SPACE IN UI
              cout << "Error: " << ptrGrabResult->GetErrorCode() << " " << ptrGrabResult->GetErrorDescription() << endl;
          }
      }
      catch (const GenericException &e)
         {
         // NEW ERROR IMPLIMENTATION FOR USE WITH QMessageBox sturucture

        //  QMessageBox::critical(this, ("Camera Device Error : Critical Error"),  e.GetDescription());
        /// ^^^ Compile error for "non-static member function"
    }

      bcamera.Close();

}

double lapf (Camera_t& bcamera){
    double focusMeasure;
    try
    {
        // bcamera.Open();
        /// int grabbedImages = 0; ***
        GenApi::CIntegerPtr width(bcamera.GetNodeMap().GetNode("Width"));
        GenApi::CIntegerPtr height(bcamera.GetNodeMap().GetNode("Height"));
        bcamera.StartGrabbing();
        CGrabResultPtr ptrGrabResult;
        CPylonImage bimage;
        CImageFormatConverter fc;
        fc.OutputPixelFormat = PixelType_Mono16; //convert the prtGrabResult to the acquisition mode
        Mat lapf(width->GetValue(), height->GetValue(), CV_64F);
        Mat image(width->GetValue(), height->GetValue(), CV_16U);
        while(bcamera.IsGrabbing())
        {
            bcamera.RetrieveResult( 5000, ptrGrabResult, TimeoutHandling_ThrowException);
            if (ptrGrabResult->GrabSucceeded()){
                    fc.Convert(bimage, ptrGrabResult);
                    image = cv::Mat(ptrGrabResult->GetHeight(), ptrGrabResult->GetWidth(), CV_16U,(uint16_t*)bimage.GetBuffer());

                    cv::Laplacian(image, lapf, CV_64F);
                    cv::Scalar mu, sigma;
                    cv::meanStdDev(lapf, mu, sigma);
                    focusMeasure = sigma.val[0] * sigma.val[0];
//                    cv::resizeWindow("Laplace Transform", 500, 350); //ALTERNATE METHOD TO RESIZE VIEW
//                    imshow("Display frame",lapf);
//                    cv::resizeWindow("Display frame", 500, 350); //ALTERNATE METHOD TO RESIZE VIEW
//                    imshow("Display frame",lapf);
//                    cv::waitKey(10);

                    }

        }
        bcamera.StopGrabbing();
    }

    catch (GenICam::GenericException &e)
    {
        // Error handling.
        cerr << "An exception occurred." << endl
        << e.GetDescription() << endl;
    }

    // bcamera.Close();
    return focusMeasure;
}

int64_t Adjust(int64_t val, int64_t minimum, int64_t maximum, int64_t inc)
{
    // Check the input parameters.
    if (inc <= 0)
    {
        // Negative increments are invalid.
        throw LOGICAL_ERROR_EXCEPTION("Unexpected increment %d", inc);
    }
    if (minimum > maximum)
    {
        // Minimum must not be bigger than or equal to the maximum.
        throw LOGICAL_ERROR_EXCEPTION("minimum bigger than maximum.");
    }

    // Check the lower bound.
    if (val < minimum)
    {
        return minimum;
    }

    // Check the upper bound.
    if (val > maximum)
    {
        return maximum;
    }

    // Check the increment.
    if (inc == 1)
    {
        // Special case: all values are valid.
        return val;
    }
    else
    {
        // The value must be min + (n * inc).
        // Due to the integer division, the value will be rounded down.
        return minimum + ( ((val - minimum) / inc) * inc );
    }
}
