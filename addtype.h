#ifndef ADDTYPE_H
#define ADDTYPE_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class addType;
}

class addType : public QDialog
{
    Q_OBJECT

public:
    explicit addType(QWidget *parent = nullptr);
    ~addType();

private:
    Ui::addType *ui;
};

#endif // ADDTYPE_H
