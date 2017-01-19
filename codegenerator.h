#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <QObject>
#include <QDate>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

class CodeGenerator : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString motherClass WRITE setMotherClass NOTIFY motherClassChanged)
    Q_PROPERTY(bool headerProtectionChecked WRITE setHeaderProtectionChecked NOTIFY headerProtectionCheckedChanged)
    Q_PROPERTY(QString headerProtection READ headerProtection WRITE setHeaderProtection NOTIFY headerProtectionChanged)
    Q_PROPERTY(bool constructor WRITE setConstructor NOTIFY constructorChanged)
    Q_PROPERTY(bool destructor WRITE setDestructor NOTIFY destructorChanged)
    Q_PROPERTY(bool comments WRITE setComments NOTIFY commentsChanged)
    Q_PROPERTY(QString author WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(QString classRole WRITE setClassRole NOTIFY classRoleChanged)
    Q_PROPERTY(QDate creationDate WRITE setCreationDate NOTIFY creationDateChanged)

    Q_PROPERTY(QString hppCode READ hppCode NOTIFY hppCodeChanged)
    Q_PROPERTY(QString cppCode READ cppCode NOTIFY cppCodeChanged)

    Q_PROPERTY(bool outputDialogVisibility READ outputDialogVisibility NOTIFY outputDialogVisibilityChanged)
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorChanged)
    Q_PROPERTY(QString errorTitle READ errorTitle NOTIFY errorChanged)

public:
    explicit CodeGenerator(QQmlApplicationEngine *engine, QObject *parent = 0);

    void setName(const QString &);
    void setMotherClass(const QString &);
    void setHeaderProtectionChecked(const bool &);
    void setHeaderProtection(const QString &);
    void setConstructor(const bool &);
    void setDestructor(const bool &);
    void setComments(const bool &);
    void setAuthor(const QString &);
    void setClassRole(const QString &);
    void setCreationDate(const QDate &);

    QString headerProtection() const { return m_headerProtection; }

    QString hppCode() const { return m_generatedHpp; }
    QString cppCode() const { return m_generatedCpp; }

    bool outputDialogVisibility() const { return m_outputVisibility; }
    QString errorMessage() const { return m_errorMessage; }
    QString errorTitle() const { return m_errorTitle; }

signals:
    void nameChanged();
    void motherClassChanged();
    void headerProtectionCheckedChanged();
    void headerProtectionChanged();
    void constructorChanged();
    void destructorChanged();
    void commentsChanged();
    void authorChanged();
    void classRoleChanged();
    void creationDateChanged();

    void hppCodeChanged();
    void cppCodeChanged();

    void outputDialogVisibilityChanged();
    void errorChanged();

public slots:
    void generateCode();
    void saveCode();
    void updateHeader();

private:
    QString generateHpp();
    QString generateCpp();

private:
    QString m_name;
    QString m_motherClass;
    bool m_headerProtectionChecked;
    QString m_headerProtection;
    bool m_constructor;
    bool m_destructor;
    bool m_comments;
    QString m_author;
    QString m_classRole;
    QDate m_creationDate;

    QString m_generatedHpp;
    QString m_generatedCpp;

    bool m_outputVisibility;

    QString m_errorMessage;
    QString m_errorTitle;

    QQmlApplicationEngine* m_engine;
};

#endif // CODEGENERATOR_H
