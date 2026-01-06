#include "mainwindow.h"
#include <QApplication>
#include "ui_calculatorUI.h"
#include "calcMainWindow.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    CalcMainWindow calc;
    calc.resize(200, 300);
    calc.move(300, 300);

    Ui::MainWindow ui;
    ui.setupUi(&calc);

    calc.lineEdit = ui.lineEdit;

    QList<QPushButton*> digitButtons = {
        ui.pushButton_0, ui.pushButton_1, ui.pushButton_2, ui.pushButton_3,
        ui.pushButton_4, ui.pushButton_5, ui.pushButton_6, ui.pushButton_7,
        ui.pushButton_8, ui.pushButton_9
    };

    for(QPushButton *btn : digitButtons) {
            QObject::connect(btn, &QPushButton::clicked, &calc, &CalcMainWindow::clickedDigit);
        }

        QList<QPushButton*> opButtons = {
            ui.pushButton_plus, ui.pushButton_minus, ui.pushButton_mul,
            ui.pushButton_div, ui.pushButton_sqr, ui.pushButton_root, ui.pushButton_procent, ui.pushButton_dot
        };

        for(QPushButton *btn : opButtons) {
            QObject::connect(btn, &QPushButton::clicked, &calc, &CalcMainWindow::clickedOperator);
        }

        QObject::connect(ui.pushButton_equal, &QPushButton::clicked, &calc, &CalcMainWindow::equality);
        QObject::connect(ui.pushButton_clear, &QPushButton::clicked, &calc, &CalcMainWindow::delete_all);


    calc.show();
    return a.exec();
}
