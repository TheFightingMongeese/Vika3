#ifndef NUMBERWIDGETITEM_H
#define NUMBERWIDGETITEM_H

#include <QTableWidgetItem>

class NumberWidgetItem : public QTableWidgetItem
{
    public:
        NumberWidgetItem(QString& str) : QTableWidgetItem(str) {}
        bool operator <(const QTableWidgetItem &other) const;
};

#endif // NUMBERWIDGETITEM_H
