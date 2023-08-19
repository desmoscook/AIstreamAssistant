#include "tablewidget.h"

TableWidget::TableWidget(QTableWidget *tablewidget, QWidget *parent)
    : QWidget(parent), tableWidget(tablewidget)
{
//    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // 设置不允许更改表格数据
//    tableWidget->setSelectionBehavior(QAbstractItemView::NoSelection); //设置不能选中

//    connect(tableWidget->verticalScrollBar(), &QScrollBar::valueChanged, this, &TableWidget::updateTable);

//    data = generateData(500);
//    tableWidget->setColumnCount(data.at(0).size());
//    tableWidget->setColumnCount(5);
//    tableWidget->verticalHeader()->setVisible(false);

//    itemHeight = tableWidget->fontMetrics().height();
//    updateTable();
}

void TableWidget::updateTable() {
    int itemsPerPage = tableWidget->height() / itemHeight;
    int startIndex = currentPage * itemsPerPage;
    int endIndex = qMin(startIndex + itemsPerPage, data.size());

    tableWidget->setRowCount(endIndex - startIndex);

    for (int i = startIndex; i < endIndex; ++i) {
        QStringList values = data.at(i).split(","); // Split the string into QStringList
        for (int j = 0; j < values.size(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(values.at(j));
            tableWidget->setItem(i - startIndex, j, item); // Set the item in the correct column
        }
    }
}

void TableWidget::previousPage() {
//    if (currentPage > 0) {
//        currentPage--;
//        updateTable();
//    }
    qDebug() << "prev";
}

void TableWidget::nextPage() {
//    int itemsPerPage = tableWidget->height() / itemHeight;
//    int totalPages = qCeil(static_cast<qreal>(data.size()) / itemsPerPage);
//    if (currentPage < totalPages - 1) {
//        currentPage++;
//        updateTable();
//    }
    qDebug() << "next";
}

void TableWidget::setupUi() {

}

QStringList TableWidget::generateData(int itemCount) {
    QStringList items;
    for (int i = 1; i <= itemCount; ++i) {
        QStringList values;
        values.append(QString("Item %1").arg(i));
        values.append(QString("Value 1"));
        values.append(QString("Value 2"));

        items.append(values);
    }
    return items;
}
