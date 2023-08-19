#include "videoimport.h"
#include "ui_videoimport.h"

videoImport::videoImport(QStringList videoType, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::videoImport)
{
    ui->setupUi(this);
    this->setWindowTitle("视频导入");


    // 设置comboBox
    ui->videoType->addItems(videoType);

    connect(ui->upload, &QPushButton::clicked, this, [=]() {
        // 选择文件
        QString fileName = QFileDialog::getOpenFileName(
            this, "Select a File", "e:\\temp",
            "Videos (*.avi *.mp4)");

        // 设置名称
        QString name = ui->videoType->currentText() + "004"; // TODO : 让数字根据当前类别的个数增加
        ui->videoName->setText(name);
    });
    connect(ui->submit, &QPushButton::clicked, this, [=]() {
        // TODO: 发送http请求
        qDebug() << "TODO";
        emit upload();
    });
    connect(ui->close, &QPushButton::clicked, this, &QDialog::close);
}

videoImport::~videoImport()
{
    delete ui;
}
