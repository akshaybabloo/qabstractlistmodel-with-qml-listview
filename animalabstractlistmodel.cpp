#include "animalabstractlistmodel.h"

AnimalAbstractListModel::AnimalAbstractListModel(QObject *parent)
        : QAbstractListModel(parent) {}

/**
 * Return the number of rows of animals.
 * 
 * @param parent 
 * @return int 
 */
int AnimalAbstractListModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_animals.count();
}

/**
 * Return the data for the given role and section.
 * 
 * @param index 
 * @param role 
 * @return QVariant 
 */
QVariant AnimalAbstractListModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_animals.count())
        return {};

    const AnimalModel &animalModel = m_animals[index.row()];
    switch (role) {
        case NameRole:
            return animalModel.getName();
        case TypeRole:
            return animalModel.getType();
        default:
            return {};
    }
}

/**
 * Add an animal to the list.
 * 
 * @param animalModel 
 */
void AnimalAbstractListModel::addAnimal(AnimalModel animalModel) {  // Argument taken by value
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_animals << std::move(animalModel);  // Move the object into the list
    endInsertRows();
}

QHash<int, QByteArray> AnimalAbstractListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[TypeRole] = "type";
    return roles;
}

/**
 * Remove an animal from the list. It is invoked from QML.
 * 
 * @param index 
 * @param count 
 */
void AnimalAbstractListModel::remove(int index, int count) {
    beginRemoveRows(QModelIndex(), index, index + count - 1);
    for (int row = 0; row < count; ++row) {
        m_animals.removeAt(index);
    }
    endRemoveRows();
}

/**
 * Add an animal to the list, similar to @see addAnimal but this is invoked from QML.
 * 
 * @param name 
 * @param type 
 */
void AnimalAbstractListModel::push(const QString &name, const QString &type) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_animals << AnimalModel(name, type);
    endInsertRows();
}

/**
 * Print the list of animals.
 */
void AnimalAbstractListModel::print() {
    qDebug() << "\nPrinting from AnimalAbstractListModel::print()";
    for (const AnimalModel &animalModel: m_animals) {
        qDebug() << animalModel.getName() << animalModel.getType();
    }
}

/**
 * Return the list of animals as a QVariantList.
 * 
 * This is invoked from QML.
 * 
 * @return QVariantList 
 */
QVariantList AnimalAbstractListModel::getAnimalsForQML() const {
    QVariantList animalsList;
    for (const AnimalModel &animal : m_animals) {
        QVariantMap animalMap;
        animalMap["name"] = animal.getName();
        animalMap["type"] = animal.getType();
        animalsList.append(animalMap);
    }
    return animalsList;
}
