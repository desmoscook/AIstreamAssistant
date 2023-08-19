#include "mainwindow.h"
#include "tablewidget.h"
#include "ui_mainwindow.h"

#include "videoimport.h"
#include "initconfig.h"
#include "addtype.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    videoType << "视频类型" << "视频上传";

    QTableWidget* Table = dynamic_cast<QTableWidget*>(ui->stackedWidget->widget(0));
    TableWidget* typeTable = new TableWidget(Table, this);

    // 侧边栏按钮

    connect(ui->videoManagerBtn, &QPushButton::clicked, ui->stackedWidget, [=](){
        ui->stackedWidget->setCurrentWidget(ui->videoManager);
    });
    connect(ui->typeManagerBtn, &QPushButton::clicked, ui->stackedWidget, [=](){
        ui->stackedWidget->setCurrentWidget(ui->typeManager);
    });

    // 视频类别管理页面
    connect(ui->typePrevBtn, &QPushButton::clicked, typeTable, &TableWidget::previousPage);
    connect(ui->typeNextBtn, &QPushButton::clicked, typeTable, &TableWidget::nextPage);
    connect(ui->addType,     &QPushButton::clicked, this, [=]() {
        addType v(this);
        v.exec();
    });

    // 视频管理页面
    connect(ui->initConfigBtn, &QPushButton::clicked, this, [=]() {
        initConfig v(this);
        v.exec();
    });
    connect(ui->videoImport, &QPushButton::clicked, this, [=]() {
        videoImport v(videoType, this);
        v.exec();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
