#ifndef TABLEDATAMODEL_H
#define TABLEDATAMODEL_H

#include <QHash>
#include <QStandardItemModel>

class TableDataModel : public QStandardItemModel
{
public:
    TableDataModel();

    QHash<int, QByteArray> roleNames() const override;
};

#endif // TABLEDATAMODEL_H
