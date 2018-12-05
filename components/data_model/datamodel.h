#ifndef _DATA_MODEL_H_
#define _DATA_MODEL_H_

#include <QColor>
#include <QList>
#include <QAbstractTableModel>

// TODO: Make it with classes and inhereting
struct GameFieldCell
{
    QColor color;
    bool is_destructible;
    bool is_walkable;
};

typedef QList<GameFieldCell> GameFieldTable;

enum class DataModelRoles
{
    Color = Qt::UserRole + 1,
    IsDesructible,
    IsWalkable
};

class DataModel : public QAbstractTableModel
{
    Q_OBJECT

  public:
    DataModel(QObject *parent = 0);
    DataModel(GameFieldTable gameFieldTable, int rows, int cols, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    
    // TODO: get rid of it. bad hack
    Q_INVOKABLE QColor getColor(int row, int column) const;
    // TODO: Implement
    // QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    // Qt::ItemFlags flags(const QModelIndex &index) const;
    // bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    // bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    // bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

  private:
    GameFieldTable m_gameFieldTable;
    int m_rows;
    int m_cols;
};

#endif // _DATA_MODEL_H_