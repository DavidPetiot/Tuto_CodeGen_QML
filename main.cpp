#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>
#include "codegenerator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    CodeGenerator codeGenerator(&engine);

    //qmlRegisterType<CodeGenerator>("MyCodeGen", 0, 1, "CodeGen");
    engine.rootContext()->setContextProperty("m_codeGen", &codeGenerator);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
