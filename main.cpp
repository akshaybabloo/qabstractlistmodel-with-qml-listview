#include "animalabstractlistmodel.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();

    AnimalAbstractListModel model(&app);
    model.addAnimal(AnimalModel("Monkey", "Mammal"));
    model.addAnimal(AnimalModel("Eagle", "Bird"));

    context->setContextProperty("animalModel", QVariant::fromValue(&model));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);
    engine.loadFromModule("qabstractlistmodel-with-qml-listview", "Main");

    return app.exec();
}
