#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include <QList>
#include <QDateTime>
#include <QAbstractItemModel>
#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <tuple>
#include <functional>

//typedef std::tuple<int, int, int, int, QString, QDateTime> ModelCol;

//class CustomModel : public QAbstractItemModel
//class CustomModel : public QAbstractListModel
class CustomModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit CustomModel(QAbstractTableModel *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);

signals:

public slots:

private:
// 列: code, no1, no2, no3, name, datetime
    QVector<QString> m_names{"code", "no1", "no2", "no3", "name", "datetime"};
    QList<QVector<QVariant> > m_stocks;
};

#endif // CUSTOMMODEL_H
