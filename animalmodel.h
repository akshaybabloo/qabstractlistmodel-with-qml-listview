#ifndef ANIMALMODEL_H
#define ANIMALMODEL_H

#include <QObject>
#include <utility>

class AnimalModel {
public:
    AnimalModel(QString name, QString type) {
        m_name = std::move(name);
        m_type = std::move(type);
    }

    const QString &getName() const {
        return m_name;
    }

    const QString &getType() const {
        return m_type;
    }

private:
    QString m_name;
    QString m_type;
};

#endif // ANIMALMODEL_H
