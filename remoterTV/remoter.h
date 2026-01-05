#ifndef REMOTER_H
#define REMOTER_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>

namespace Ui {
class Remoter;
}

class Remoter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Remoter(QWidget *parent = nullptr);
    ~Remoter();

private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_onOff_clicked();

    void applyChannel();

    void on_nextChan_clicked();

    void on_prevChan_clicked();

    void on_plusVol_clicked();

    void on_minVol_clicked();

private:
    Ui::Remoter *ui;
    QTimer *timer;
    QString channelBuffer;
    bool isTurnedOn = false;
    int currentChan = 1;
    int currentVol = 100;
    void refreshUI();
};

#endif // REMOTER_H
