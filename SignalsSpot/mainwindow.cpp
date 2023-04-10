//@author Саранчин К.А.

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /// Подключаем к кнопкам слоты
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(slotButton1()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(slotButton2()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(slotButton3()));

    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(slotButton2()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(slotButton3()));


    /*Подключение передачи номера к слоту вывода сообщения*/
    connect(this,&MainWindow::signalFromButton,this,&MainWindow::slotMessage);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotButton1()
{
    emit signalFromButton(1);
}

void MainWindow::slotButton2()
{
    emit signalFromButton(2);
}

void MainWindow::slotButton3()
{
    emit signalFromButton(3);
}

void MainWindow::slotMessage(int buttonId)
{
    ui->textEdit->append("Меня нажали " + QString::number(buttonId));
}
