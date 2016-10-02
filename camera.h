#define CAMERA_H
#include <pylon/PylonIncludes.h>
#include <pylon/PylonGUI.h>
#include <pylon/usb/BaslerUsbInstantCamera.h>
#include <iostream>

#include <C:/opencv3/vsbuild/install/include/opencv2/opencv.hpp>
#include <bcamera.h>

/// HEADERS DUPLICATED IN DISPLAY.h

using namespace cv;

using namespace std;
typedef Pylon::CBaslerUsbInstantCamera Camera_t;
using namespace Basler_UsbCameraParams;
using namespace Pylon;

void pylon_setup(Camera_t& bcamera);
void capsave(Camera_t& bcamera);
void capcv(Camera_t& bcamera);
double lapf(Camera_t& bcamera);

int64_t Adjust(int64_t val, int64_t minimum, int64_t maximum, int64_t inc);
