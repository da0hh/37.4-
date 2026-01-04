#include "mainwindow.h"
#include <QApplication>
#include "ui_calculatorUI.h"
#include "calcMainWindow.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    CalcMainWindow window(nullptr);
    window.resize(400, 500);
    window.move(400, 300);

    Ui::MainWindow calc;
    calc.setupUi(&window);

    window.lineEdit = calc.lineEdit;

    window.show();
    return a.exec();
}
