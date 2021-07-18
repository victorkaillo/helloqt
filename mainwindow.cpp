#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <QAbstractSlider>
#include <chrono>
#include <ctime>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
using namespace chrono;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->pushButton_quit,
            SIGNAL(clicked(bool)),
            this,
            SLOT(quit()));

    connect(ui->pushButtonAzul,
            SIGNAL(clicked(bool)),
            this,
            SLOT(lcd_display()));
    connect(ui->pushButtonVerde,
            SIGNAL(clicked(bool)),
            this,
            SLOT(contador_verde()));
    connect(ui->pushButtonAmarelo,
            SIGNAL(clicked(bool)),
            ui->lcdNumber_maior,
            SLOT(display(int)));
    connect(ui->pushButtonAmarelo,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_button1_clicked(bool)));
    connect(this,
            SIGNAL(UpdateValFunc(int)),
            ui->lcdNumber_atual,
            SLOT(display(int)));
            //
            //SLOT(display(double)));
    /*connect(ui->pushButtonAmarelo,
            SIGNAL(clicked(bool)),
            this,
            SLOT(setChecked(bool)));*/
}
//QObject::connect(horizontalSlider, &QSlider::valueChanged, lcdNumber, QOverload<int>::of(&QLCDNumber::display));

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::quit()
{
    exit(0);
}


void MainWindow::copy()
{
    ui->textBrowser->setText(ui->textEdit->toPlainText());
}

void MainWindow::contador_azul(int _azul)
{
    lcd_display();
}

void MainWindow::contador_verde(int _verde)
{
    repaint();
}

void MainWindow::contador_amarelo(int _amarelo)
{

}

int MainWindow::lcd_display()
{
    //void lcdNumber_maior::display(double 1)
            return 1;
}




void MainWindow::sequencia_maior()
{
    //a->setText(a);
}

void MainWindow::sequencia_atual()
{
    //setText(a);
}

void MainWindow::on_button1_clicked(bool _checked)
{
    emit UpdateValFunc(5); /*checked = _checked;
    if(checked)
        {
           //some work here.....
            emit UpdateValFunc(5);// ui->lcdNumber_maior->setText(int());
            //repaint();
            //ui->pushButtonAmarelo->setText(tr("on "));
           //.......
        }
        else
        {
           //some work here.......
            emit UpdateValFunc(5);//ui->pushButtonAmarelo->setText(tr("off "));
           //......
        }*/
}


/*void MainWindow::display()
{
    ui->labelAzul->setStyleSheet();
            //setStyleSheet(background-color: rgba(0,0,254,50));

}
*/