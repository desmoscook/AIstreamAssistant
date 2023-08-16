#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->videoManagerBtn, &QPushButton::clicked, ui->stackedWidget, [=](){
        ui->stackedWidget->setCurrentWidget(ui->videoManager);
    });
    connect(ui->typeManagerBtn, &QPushButton::clicked, ui->stackedWidget, [=](){
        ui->stackedWidget->setCurrentWidget(ui->typeManager);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

