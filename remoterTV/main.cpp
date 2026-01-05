#include "mainwindow.h"
#include <QApplication>
#include "ui_remoter.h"
#include "remoter.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Remoter r;
    r.show();

    return a.exec();
}
