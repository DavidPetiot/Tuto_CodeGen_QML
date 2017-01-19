#include "codegenerator.h"
#include <QMessageBox>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlProperty>

CodeGenerator::CodeGenerator(QQmlApplicationEngine *engine, QObject *parent)
    : QObject(parent)
    , m_engine(engine)
    , m_outputVisibility(false)
{
}

void CodeGenerator::setName(const QString &p){
    if(m_name != p){
        m_name = p;
        emit nameChanged();

        updateHeader();
    }
}

void CodeGenerator::setMotherClass(const QString &p){
    if(m_motherClass != p){
        m_motherClass = p;
        emit motherClassChanged();
    }
}

void CodeGenerator::setHeaderProtectionChecked(const bool &p){
    if(m_headerProtectionChecked != p){
        m_headerProtectionChecked = p;
        emit headerProtectionCheckedChanged();

        updateHeader();
    }
}

void CodeGenerator::setHeaderProtection(const QString &p){
    if(m_headerProtection != p){
        m_headerProtection = p.toUpper();
        emit headerProtectionChanged();

        updateHeader();
    }
}

void CodeGenerator::setConstructor(const bool &p){
    if(m_constructor != p){
        m_constructor = p;
        emit constructorChanged();
    }
}

void CodeGenerator::setDestructor(const bool &p){
    if(m_destructor != p){
        m_destructor = p;
        emit destructorChanged();
    }
}

void CodeGenerator::setComments(const bool &p){
    if(m_comments != p){
        m_comments = p;
        emit commentsChanged();
    }
}

void CodeGenerator::setAuthor(const QString &p){
    if(m_author != p){
        m_author = p;
        emit authorChanged();
    }
}

void CodeGenerator::setClassRole(const QString &p){
    if(m_classRole != p){
        m_classRole = p;
        emit classRoleChanged();
    }
}

void CodeGenerator::setCreationDate(const QDate &p){
    if(m_creationDate != p){
        m_creationDate = p;
        emit creationDateChanged();
    }
}

void CodeGenerator::generateCode()
{
    if(m_name.isEmpty())
    {
        m_errorTitle = "Error";
        m_errorMessage = "missing class name";

        emit errorChanged();
    }
    //test upper case ?
    else
    {
        m_generatedHpp = generateHpp();
        m_generatedCpp = generateCpp();
        emit hppCodeChanged();
        emit cppCodeChanged();

        m_outputVisibility = true;
        emit outputDialogVisibilityChanged();

    }

}

QString CodeGenerator::generateHpp()
{
    QString l_hCode;

    //comments
    if(m_comments)
    {
        l_hCode += "/*\n";
        l_hCode += "Author : " + m_author + "\n";
        l_hCode += "Creation date : " + m_creationDate.toString() + "\n";
        l_hCode += "Role :\n" + m_classRole + "\n*/\n\n";
    }

    //Header
    if(m_headerProtectionChecked)
    {
        l_hCode += "#ifndef " + m_headerProtection + "\n";
        l_hCode += "#define " + m_headerProtection + "\n";
    }

    //class
    l_hCode += "class " + m_name;

    if(!m_motherClass.isEmpty())
    {
        l_hCode += " : public " + m_motherClass;
    }

    l_hCode += "\n{\npublic:\n";
    if(m_constructor)
    {
        l_hCode += "    " + m_name + "();\n";
    }
    if(m_destructor)
    {
        l_hCode += "    ~" + m_name + "();\n";
    }

    l_hCode += "\n\n    protected:\n";
    l_hCode += "\n\n    private:\n";
    l_hCode += "};\n\n";

    //close header
    if(m_headerProtectionChecked)
    {
        l_hCode += "#endif //" + m_headerProtection + "\n";
    }

    return l_hCode;
}

QString CodeGenerator::generateCpp()
{
    QString l_cCode = "cpp not yet generated";
    return l_cCode;
}

void CodeGenerator::saveCode()
{

}

void CodeGenerator::updateHeader()
{
    if( m_headerProtectionChecked && !(m_name.isEmpty()) )
    {
        m_headerProtection = "HEADER_" + m_name.toUpper();
    }
    else
    {
        m_headerProtection = QString();
    }

    emit headerProtectionChanged();
}
