#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <QAbstractSlider>
#include <chrono>
#include <ctime>
#include <time.h>   // para: time()
#include <unistd.h>
#include <stdlib.h>

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
    //Conecta click do botao amarelo a funcao que emite sinal para lcd number
    connect(ui->pushButtonDez,
            SIGNAL(clicked(bool)),
            this,
            SLOT(contador_dez(bool)));
    //Conecta click do botao azul a funcao que emite sinal para lcd number
    connect(ui->pushButtonVinte,
            SIGNAL(clicked(bool)),
            this,
            SLOT(contador_vinte(bool)));
    //Conecta click do botao verde a funcao que emite sinal para lcd number
    connect(ui->pushButtonTrinta,
            SIGNAL(clicked(bool)),
            this,
            SLOT(contador_trinta(bool)));
    //Conecta funcao que emite sinal numerico ao lcd number atual
    connect(this,
            SIGNAL(UpdateValFunc(int)),
            ui->lcdNumber_atual,
            SLOT(display(int)));
    //Conecta sinal da funcao ao visor
    connect(this,
            SIGNAL(ValueDisplay(int)),
            ui->lcdNumber_visor,
            SLOT(display(int)));
    //Conecta botao start a funcao
    connect(ui->pushButtonStart,
            SIGNAL(clicked(bool)),
            this,
            SLOT(lcdDisplay_Start(bool)));
    connect(this,
            SIGNAL(ValueDisplayReacao(int)),
            ui->lcdNumber_maior,
            SLOT(display(int)));
    //startTimer(3500);
}
//QObject::connect(horizontalSlider, &QSlider::valueChanged, lcdNumber, QOverload<int>::of(&QLCDNumber::display));

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    value = arc4random()%3;
    value = value * 10;
    if(value > 30){
        value = 10;
    }
    else if(value == 0){
        value = 30;
    }
    lcdDisplay(true);
}


void MainWindow::quit()
{
    exit(0);
}


void MainWindow::copy()
{
    ui->textBrowser->setText(ui->textEdit->toPlainText());
}

void MainWindow::contador_dez(bool _checked)
{
    tempo2 = time( (time_t *) 0);
    if(value==10){
        dez++;
        emit UpdateValFunc(dez+vinte+trinta);
        killTimer(timerId);
        value = arc4random()%3;
        value = value * 10;
        if(value==0)
            value=20;
        lcdDisplay_Start(true);
    }
    else{
        dez = 0;
        vinte = 0;
        trinta = 0;
        emit UpdateValFunc(dez+vinte+trinta);
    }
}

void MainWindow::contador_vinte(bool _checked)
{
    tempo2 = time( (time_t *) 0);
    if(value==20){
        ++vinte;
        emit UpdateValFunc(dez+vinte+trinta);
        killTimer(timerId);
        value = arc4random()%3;
        value = value * 10;
        if(value==0)
            value=30;
        lcdDisplay_Start(true);
    }
    else{
        dez = 0;
        vinte = 0;
        trinta = 0;
        emit UpdateValFunc(dez+vinte+trinta);
    }
}

void MainWindow::contador_trinta(bool _checked)
{
    tempo2 = time( (time_t *) 0);
    sequencia_maior();
    if(value==30){
        ++trinta;
        emit UpdateValFunc(dez+vinte+trinta);
        killTimer(timerId);
        value = arc4random()%2;
        value = value * 10;
        if(value==0)
            value=20;
        lcdDisplay_Start(true);
    }
    else{
        dez = 0;
        vinte = 0;
        trinta = 0;
        emit UpdateValFunc(dez+vinte+trinta);
    }
}

void MainWindow::lcdDisplay(bool _checked)
{
    emit ValueDisplay(value);
    tempo1 = time( (time_t *) 0);
}

void MainWindow::lcdDisplay_Start(bool _checked)
{
    emit ValueDisplay(value);
    timerId = startTimer(3000);
}


void MainWindow::sequencia_maior()
{
    int reacao = (int) tempo2 - tempo1;
    emit ValueDisplayReacao(reacao);
}

void MainWindow::sequencia_atual()
{
    //setText(a);
}

void MainWindow::on_button1_clicked(bool _checked)
{
    //emit UpdateValFunc(++dez);
}
