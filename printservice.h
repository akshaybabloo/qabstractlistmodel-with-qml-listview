#ifndef PRINTSERVICE_H
#define PRINTSERVICE_H

#include <QObject>
#include <QQmlEngine>

class PrintService : public QObject {
    Q_OBJECT
    QML_ELEMENT
public:
    explicit PrintService(QObject *parent = nullptr) {}

    /**
     * @brief PrintService::print
     * @param QVariantList
     * @details
     * This function is used to print the data from the model.
     * The model is passed as a QVariantList object.
     * The QVariantList object is then iterated over and the data is printed.
     */
    Q_INVOKABLE static void print(const QVariantList &animalsList) {
        qDebug() << "\nPrinting from PrintService::print()";
        for (const QVariant &var: animalsList) {
            QVariantMap animalMap = var.toMap();
            qDebug() << animalMap["name"].toString() << " " << animalMap["type"].toString();
        }
    }

};

#endif // PRINTSERVICE_H
