#ifndef CALCMAINWINDOW_H
#define CALCMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include "ui_calculatorUI.h"
#include <iostream>
#include <cmath>

class CalcMainWindow : public QMainWindow
{
    Q_OBJECT

    double first_num = 0;
    QString operation = "";
    double second_num = 0;

public:
    QLineEdit* lineEdit = nullptr;
    CalcMainWindow(QWidget *parent = nullptr) : QMainWindow(parent){}

public slots:
    void add0(){ lineEdit->setText(lineEdit->text() + "0"); }
    void add1(){ lineEdit->setText(lineEdit->text() + "1"); }
    void add2(){ lineEdit->setText(lineEdit->text() + "2"); }
    void add3(){ lineEdit->setText(lineEdit->text() + "3"); }
    void add4(){ lineEdit->setText(lineEdit->text() + "4"); }
    void add5(){ lineEdit->setText(lineEdit->text() + "5"); }
    void add6(){ lineEdit->setText(lineEdit->text() + "6"); }
    void add7(){ lineEdit->setText(lineEdit->text() + "7"); }
    void add8(){ lineEdit->setText(lineEdit->text() + "8"); }
    void add9(){ lineEdit->setText(lineEdit->text() + "9"); }

    void delete_all(){lineEdit->setText("0");}
    void root(){ lineEdit->setText(lineEdit->text() + "√"); }
    void multiply(){lineEdit->setText(lineEdit->text() + "x");}
    void division(){lineEdit->setText(lineEdit->text() + "/");}
    void subtraction(){lineEdit->setText(lineEdit->text() + "-");}
    void addition(){lineEdit->setText(lineEdit->text() + "+");}
    void procent(){lineEdit->setText(lineEdit->text() + "%");}
    void square(){
        lineEdit->setText(lineEdit->text() + "²");
    }
    void dot(){lineEdit->setText(lineEdit->text() + ",");}

    void equality(){
        QString full = lineEdit->text();
        double res = 0.f;

        QString op = "";
        if (full.contains("+")) op = "+";
        else if (full.contains("-")) op = "-";
        else if (full.contains("x")) op = "x";
        else if (full.contains("/")) op = "/";
        else if(full.contains("²")) op = "²";
        else if(full.contains("%")) op = "%";
        else if(full.contains("√")) op = "√";

        QStringList parts = full.split(op);

        double first = 0.0f, second = 0.0f;

        if(parts.size() < 2){
            first = parts[0].replace(",", ".").toDouble();
            second = 0;
        }
        else{
            first = parts[0].replace(",", ".").toDouble();
            second = parts[1].replace(",", ".").toDouble();
        }

        if(op == "+")
            res = first + second;
        else if(op == "-")
            res = first - second;
        else if(op == "/")
            res = first / second;
        else if(op == "x")
            res = first * second;
        else if(op == "%")
            res = (int)first % (int)second;
        else if(op == "√"){
            if(first < 0){
                lineEdit->setText("ERROR: Neg root\n");
                return;
            }
            res = std::sqrt(first);
        }
        else if(op == "²"){
            if(second > 0){
                std::cerr << "ERROR\n";
                return;}
            res = pow(first, 2);
        }
        else{
            std::cerr << "ERROR\n";
            return;
        }
        lineEdit->setText(QString::number(res));
    }
};
#endif
