#include "TableDataReader.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "TableDataModel.h"

TableDataReader::TableDataReader()
    : m_model(new TableDataModel())
{
    QHash<int, QByteArray> rolehash;
    rolehash[Qt::DisplayRole] = "display";
}

void TableDataReader::readTableDataFromFile(const QString &filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString data = stream.readAll();

        if (!data.isEmpty())
        {
            QStringList lines = data.split("\n", QString::SkipEmptyParts);

            foreach (QString line, lines)
            {
                QStringList words = line.split(";", QString::SkipEmptyParts);
                QList<QStandardItem *> rowData;
                foreach (QString word, words)
                {
                    QStandardItem * item = new QStandardItem(word);
                    rowData << item;
                }

                m_model->appendRow(rowData);
            }
        }
    }
    else
    {
        qDebug() << "File opening error!";
    }
}

TableDataModel *TableDataReader::getModel() const
{
    return m_model;
}
