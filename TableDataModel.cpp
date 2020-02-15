#include "TableDataModel.h"

TableDataModel::TableDataModel()
{
}

QHash<int, QByteArray> TableDataModel::roleNames() const
{
    return { {Qt::DisplayRole, "display"} };
}
