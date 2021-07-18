#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    int azul = 1;
    int verde, amarelo;
    bool checked;
public:
    //void mousePressEvent(QMouseEvent *event);
signals:
    void UpdateValFunc(int);
public slots:
    void quit();
    void copy();
    void contador_azul(int _azul);
    void contador_verde(int _verde);
    void contador_amarelo(int _amarelo);
    int lcd_display();
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
