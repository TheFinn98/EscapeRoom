#include "startscreen.h"

StartScreen::StartScreen(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant StartScreen::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex StartScreen::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex StartScreen::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int StartScreen::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int StartScreen::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant StartScreen::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
