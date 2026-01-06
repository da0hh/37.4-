#ifndef CALCMAINWINDOW_H
#define CALCMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include "ui_calculatorUI.h"
#include <iostream>
#include <cmath>
#include <algorithm>

class CalcMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QLineEdit* lineEdit = nullptr;
    CalcMainWindow(QWidget *parent = nullptr) : QMainWindow(parent){}

public slots:
    void clickedDigit(){
            QPushButton *btn = qobject_cast<QPushButton*>(sender());
            if(btn){
                QString name = btn->text();
                if(lineEdit->text() == "0" && name != ",") lineEdit->clear();
                lineEdit->setText(lineEdit->text() + name);
            }
    }

    void clickedOperator(){
        if (QPushButton *btn = qobject_cast<QPushButton*>(sender())) {
            QString current = lineEdit->text();
            if (!current.isEmpty() && !current.back().isDigit() && current.back() != u'²' && current.back() != u',') {
                return;
            }
            lineEdit->setText(current + btn->text());
        }
    }

    void delete_all(){lineEdit->setText("0");}

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

        if(op == "")
            return;

        QStringList parts = full.split(op);

        for (const QString& part : parts) {
            for (QChar c : part) {
                if (c.isLetter()) {
                    lineEdit->setText("ERROR");
                    return;
                }
            }
        }

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
        else if(op == "%"){
            res = (int)first % (int)second;
        }
        else if(op == "√"){
            if(first < 0){
                lineEdit->setText("ERROR");
                return;
            }
            res = std::sqrt(first);
        }
        else if(op == "²"){
            if(second > 0){
                std::cerr << "ERROR";
                return;}
            res = pow(first, 2);
        }
        else{
            std::cerr << "ERROR";
            return;
        }

        lineEdit->setText(QString::number(res, 'g', 10));
    }
};
#endif
