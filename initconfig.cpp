#include "initconfig.h"
#include "ui_initconfig.h"

initConfig::initConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::initConfig)
{
    ui->setupUi(this);
    this->setWindowTitle("初始化配置");

    connect(ui->testConnect, &QPushButton::clicked, this, [=]() {
        // TODO 测试链接
        qDebug() << "TODO 正在尝试链接";
        // 判断ip地址格式是否正确
        QString ip = ui->ipEdit->text().trimmed();
        QStringList nums = ip.split(QLatin1Char('.'));
        if (nums.size() != 4) return;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i].toInt();
            if (num < 0 || num > 255) {
                QMessageBox::critical(this, "error", "ip地址格式错误");
                return;
            }
        }
        // 格式则测试链接
        emit testConnect();
    });
    // TODO 这个配置是什么
    connect(ui->submit, &QPushButton::clicked, this, [=]() {
        qDebug() << "TODO 正在更改配置";
    });
    connect(ui->close, &QPushButton::clicked, this, &QDialog::close);
}

initConfig::~initConfig()
{
    delete ui;
}
