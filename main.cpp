#include <QApplication>
#include <QPushButton>
#include <QtCore>
#include <stdlib.h>
#include "bcamera.h"
#include "chroma.h"
#include "camera.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{

    int res=-1;
    PylonInitialize();

    QApplication app(argc, argv);

    Chroma w;
    w.show();
    res = app.exec();
    PylonTerminate();
    return res;
}




