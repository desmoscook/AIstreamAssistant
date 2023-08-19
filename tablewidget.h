#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QVector>
#include <QStringList>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QScrollBar>
#include <QtMath>
#include <QHeaderView>

#include <QDebug>


class TableWidget : public QWidget
{
    Q_OBJECT

public:
    TableWidget(QTableWidget* tablewidget, QWidget *parent = nullptr);

public slots:
    void updateTable();
    void previousPage();
    void nextPage();

private:
    void setupUi();
    QStringList generateData(int itemCount);

    QTableWidget *tableWidget;
    QStringList data;
    int currentPage = 0;
    int itemHeight;
};

#endif // TABLEWIDGET_H
