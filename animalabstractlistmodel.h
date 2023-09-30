#ifndef ABSTRACTLISTMODEL_H
#define ABSTRACTLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include "animalmodel.h"

class AnimalAbstractListModel : public QAbstractListModel {
Q_OBJECT

public:
    enum AnimalRoles {
        NameRole = Qt::UserRole + 1,
        TypeRole
    };

    explicit AnimalAbstractListModel(QObject *parent = nullptr);

    void addAnimal(const AnimalModel animalModel);

    Q_INVOKABLE QVariantList getAnimalsForQML() const;

    Q_INVOKABLE void remove(int index, int count = 1);

    Q_INVOKABLE void push(const QString &name, const QString &type);

    Q_INVOKABLE void print();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<AnimalModel> m_animals;
};

#endif // ABSTRACTLISTMODEL_H
