#include "addtype.h"
#include "ui_addtype.h"

addType::addType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addType)
{
    ui->setupUi(this);
    this->setWindowTitle("新增类别");
}

addType::~addType()
{
    delete ui;
}
