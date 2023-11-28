#include "TestDemo.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestDemo w;
    w.show();

    return a.exec();
}
