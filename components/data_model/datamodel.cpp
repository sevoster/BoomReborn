#include <datamodel.h>
#include <stdlib.h>
#include <time.h>

GameFieldTable generate_random_field(int rows, int cols)
{
    srand (time(NULL));

    GameFieldTable table;
    for (int i = 0; i < rows * cols; i++)
    {
        int random = rand() % 2;
        GameFieldCell newCell {QColor(rand() % 2 == 0 ? "red" : "white"), true, true};
        table.append(newCell);
    }
    return table;
}

DataModel::DataModel(QObject *parent) : QAbstractTableModel(parent), m_cols(0), m_rows(0)
{
    // TODO: temporary for test
    m_rows = 10;
    m_cols = 20;
    m_gameFieldTable = generate_random_field(m_rows, m_cols);
}

DataModel::DataModel(GameFieldTable gameFieldTable, int rows, int cols, QObject *parent) : 
    QAbstractTableModel(parent), m_rows(rows), m_cols(cols), m_gameFieldTable(gameFieldTable)
{
}

int DataModel::rowCount(const QModelIndex& parent) const
{
    return m_rows;
}

int DataModel::columnCount(const QModelIndex& parent) const
{
    return m_cols;
}

QVariant DataModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int col = index.column();

    if (row >= rowCount() || col >= columnCount())
    {
        return QVariant();
    }

    int idx = row * columnCount() + col;
    if (idx >= m_gameFieldTable.size())
    {
        return QVariant();
    }

    GameFieldCell cell = m_gameFieldTable[idx];

    switch (role)
    {
        case (int)DataModelRoles::Color:
        {
            return cell.color;
        }
        case (int)DataModelRoles::IsDesructible:
        {
            return cell.is_destructible;
        }
        case (int)DataModelRoles::IsWalkable:
        {
            return cell.is_walkable;
        }
    }

    return QVariant();
}

Q_INVOKABLE QColor DataModel::getColor(int row, int column) const
{
    return m_gameFieldTable[row * m_cols + column].color;
}

QHash<int, QByteArray> DataModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)DataModelRoles::Color] = "color";
    roles[(int)DataModelRoles::IsDesructible] = "is_destructible";
    roles[(int)DataModelRoles::IsWalkable] = "is_walkable";
    return roles;
}