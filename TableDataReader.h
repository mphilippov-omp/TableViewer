#ifndef TABLEDATAREADER_H
#define TABLEDATAREADER_H

#include <QString>

class TableDataModel;

class TableDataReader
{
public:
    TableDataReader();

    void readTableDataFromFile(const QString &filename);
    TableDataModel *getModel() const;

private:
    TableDataModel *m_model;

};

#endif // TABLEDATAREADER_H
