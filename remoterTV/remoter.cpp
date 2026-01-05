#include "remoter.h"
#include "ui_remoter.h"
#include <QMessageBox>
#include <algorithm>
#include <QString>

Remoter::Remoter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Remoter)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer->setSingleShot(true);

    connect(timer, &QTimer::timeout, this, &Remoter::applyChannel);

    refreshUI();
}

Remoter::~Remoter()
{
    delete ui;
}

void Remoter::on_onOff_clicked()
{
    if(isTurnedOn){
        QMessageBox::information(this, "TV", "The TV was turned off");
        isTurnedOn = false;
    }
    else{
        QMessageBox::information(this, "TV", "The TV was turned on");
        isTurnedOn = true;
    }
    refreshUI();
}

void Remoter::refreshUI(){
    QString displayChannel = channelBuffer.isEmpty() ? QString::number(currentChan) : channelBuffer;
    QString displayVollume = QString::number(currentVol);

    ui->channelLabel->setText(displayChannel);
    ui->vollumeLabel->setText(displayVollume);
}

void Remoter::on_pushButton_0_clicked() { if(isTurnedOn) { channelBuffer += "0"; timer->start(2000); } }
void Remoter::on_pushButton_1_clicked() { if(isTurnedOn) { channelBuffer += "1"; timer->start(2000); } }
void Remoter::on_pushButton_2_clicked() { if(isTurnedOn) { channelBuffer += "2"; timer->start(2000); } }
void Remoter::on_pushButton_3_clicked() { if(isTurnedOn) { channelBuffer += "3"; timer->start(2000); } }
void Remoter::on_pushButton_4_clicked() { if(isTurnedOn) { channelBuffer += "4"; timer->start(2000); } }
void Remoter::on_pushButton_5_clicked() { if(isTurnedOn) { channelBuffer += "5"; timer->start(2000); } }
void Remoter::on_pushButton_6_clicked() { if(isTurnedOn) { channelBuffer += "6"; timer->start(2000); } }
void Remoter::on_pushButton_7_clicked() { if(isTurnedOn) { channelBuffer += "7"; timer->start(2000); } }
void Remoter::on_pushButton_8_clicked() { if(isTurnedOn) { channelBuffer += "8"; timer->start(2000); } }
void Remoter::on_pushButton_9_clicked() { if(isTurnedOn) { channelBuffer += "9"; timer->start(2000); } }


void Remoter::applyChannel()
{
    if (!channelBuffer.isEmpty()) {
        currentChan = channelBuffer.toInt();
        QMessageBox::information(this, "TV", "Channel was change to: " + QString::number(currentChan));
        channelBuffer.clear();
    }
    refreshUI();
}

void Remoter::on_nextChan_clicked()
{
    if(isTurnedOn){
        timer->stop();
        channelBuffer.clear();
        if(currentChan >= 150){
            currentChan = 1;
        }
        else{
            currentChan++;
        }
        QMessageBox::information(this, "TV", "Channel was change to: " + QString::number(currentChan));
        refreshUI();
    }
}

void Remoter::on_prevChan_clicked()
{
    if(isTurnedOn){
        timer->stop();
        channelBuffer.clear();

        if(currentChan <= 1){
            currentChan = 150;
        }
        else{
            currentChan--;
        }

        QMessageBox::information(this, "TV", "Channel was change to: " + QString::number(currentChan));
        refreshUI();
    }
}


void Remoter::on_plusVol_clicked()
{
    if(isTurnedOn){
        if(currentVol < 100){
            currentVol += (currentVol * 0.1);
        }
        else{
            QMessageBox::information(this, "TV", "Reached the maximum of vollume");
            currentVol = 100;
        }
    refreshUI();
    }
}

void Remoter::on_minVol_clicked()
{
    if(isTurnedOn){
        if(currentVol > 0){
            currentVol -= (currentVol * 0.1);
        }
        else{
            QMessageBox::information(this, "TV", "Reached the minimum of vollume");
            currentVol = 0;
        }
    }
    refreshUI();
}
