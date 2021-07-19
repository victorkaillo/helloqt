#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chrono>
#include <ctime>
#include <unistd.h>
using namespace std;
using namespace chrono;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    int dez = 0, value = 0;
    int vinte = 0, trinta = 0;
    bool checked = true;
    int timerId;
    time_t tempo1, tempo2;
public:
    void timerEvent(QTimerEvent *event);
signals:
    void UpdateValFunc(int);
    void ValueDisplay(int);
    void ValueDisplayReacao(int);
public slots:
    void quit();
    void copy();
    void contador_dez(bool _checked);
    void contador_vinte(bool _checked);
    void contador_trinta(bool _checked);
    void lcdDisplay(bool _checked);
    void lcdDisplay_Start(bool _checked);
    void sequencia_maior();
    void sequencia_atual();
    void on_button1_clicked(bool _checked);
    //void display();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

//[errado]QObject::connect(horizontalSlider, &QSlider::valueChanged, lcdNumber, &QLCDNumber::display);
/* -- https://stackoverflow.com/questions/65983928/issue-while-trying-to-onnect-a-horizontal-slider-to-a-lcd-number-and-a-progress -- */
/* -- https://doc.qt.io/qt-5/qtglobal.html#qOverload -- */
/* -- https://forum.qt.io/topic/127558/qt6-signals-and-slots-connect-issue -- */
/*CORRECAO DE ERRO NAO COMPREENDIDA*/
//[correto]QObject::connect(horizontalSlider, &QSlider::valueChanged, lcdNumber, QOverload<int>::of(&QLCDNumber::display));
