#include "watermark.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WaterMarkWidget w;
    w.show();
    return a.exec();
}
