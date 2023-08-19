#ifndef INITCONFIG_H
#define INITCONFIG_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class initConfig;
}

class initConfig : public QDialog
{
    Q_OBJECT

public:
    explicit initConfig(QWidget *parent = nullptr);
    ~initConfig();

signals:
    void testConnect();

private:
    Ui::initConfig *ui;
};

#endif // INITCONFIG_H
