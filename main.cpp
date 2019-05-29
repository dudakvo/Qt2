#include <QApplication>
#include "qtwidget.h"

int main(int lArgc, char *lArgv[])
{
    QApplication lApplication(lArgc, lArgv);
    QtWidget mainWidget;

    mainWidget.show();
    return lApplication.exec();
}
