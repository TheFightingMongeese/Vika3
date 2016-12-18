#include "numberwidgetitem.h"

bool NumberWidgetItem::operator <(const QTableWidgetItem &other) const
{
    return text().toInt() < other.text().toInt();
}
