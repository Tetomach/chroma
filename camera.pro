FORMS += \
    serialsettings.ui \
    chroma.ui \
    bookprop.ui \
    pageprop.ui

TEMPLATE = app

QT += core \
      opengl \
      widgets \
      serialport \
      gui \

HEADERS = \
    camera.h \
    serialsettings.h \
    bcamera.h \
    chroma.h \
    bookprop.h \
    pageprop.h

SOURCES = \
    main.cpp \
    camera.cpp \
    serialsettings.cpp \
    bcamera.cpp \
    chroma.cpp \
    bookprop.cpp \
    pageprop.cpp

TARGET += camera

INCLUDEPATH += C:\opencv3\vsbuild\install\include\

LIBS += -LC:\opencv3\vsbuild\install\x64\vc14\lib\
    -lopencv_core310 \
    -lopencv_imgproc310 \
    -lopencv_highgui310 \
    -lopencv_ml310 \
    -lopencv_video310 \
    -lopencv_videoio310 \
    -lopencv_features2d310 \
    -lopencv_calib3d310 \
    -lopencv_objdetect310 \
    -lopencv_flann310 \
    -lopencv_photo310 \

INCLUDEPATH += "C:\Program Files\Basler\pylon 5\Development\include" \

LIBS += "-LC:\Program Files\Basler\pylon 5\Development\lib\x64" \
    -lGenApi_MD_VC120_v3_0_Basler_pylon_v5_0 \
    -lGCBase_MD_VC120_v3_0_Basler_pylon_v5_0 \
    -lPylonBase_MD_VC120_v5_0 \

DEFINES += _ITERATOR_DEBUG_LEVEL=0
