#ifndef VIDEOIMPORT_H
#define VIDEOIMPORT_H

#include <QWidget>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

#include <QDebug>

namespace Ui {
class videoImport;
}

class videoImport : public QDialog
{
    Q_OBJECT

public:
    explicit videoImport(QStringList videoType, QWidget *parent = nullptr);
    ~videoImport();

signals:
    void upload();

private:
    Ui::videoImport *ui;
};

#endif // VIDEOIMPORT_H
