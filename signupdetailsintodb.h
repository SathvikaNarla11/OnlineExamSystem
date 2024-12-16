#ifndef SIGNUPDETAILSINTODB_H
#define SIGNUPDETAILSINTODB_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QtSql>

#include "questionsdialog.h"

class SignUpDetailsIntoDB : public QObject
{
    Q_OBJECT
public:
    SignUpDetailsIntoDB();
    QuestionsDialog *questionDialogObj;

    QSqlDatabase mydb;
    bool connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/sqlite3/signInStudentDetails.db");
        if(!mydb.open())
        {
            qDebug()<<"Failed to connect from SignUpDetailsIntoDB.h";
            return false;
        }
        else
        {
            qDebug()<<"Connected from SignUpDetailsIntoDB.h";
            return true;
        }
    }
    void connClose()
    {
        mydb.close();
        qDebug()<<"Closed";
        // mydb.removeDatabase(QSqlDatabase::defaultConnection);
        // QString connectionName = mydb.connectionName();
        // mydb.close();
        // QSqlDatabase::removeDatabase(connectionName);

    }

    QSqlQuery qry;
    QuestionsDialog *QuesDialogObj;

public slots:
    void on_pushBtn_CreateAccClicked(QLineEdit *nameSULineEdit, QLineEdit *pwdSULineEdit, QLineEdit *RpwdSULineEdit, QLineEdit *emailSULineEdit, QLineEdit *mobileNumSULineEdit);
    void loginFun(QLineEdit *nameSILineEdit, QLineEdit *pwdSILineEdit);

};

#endif // SIGNUPDETAILSINTODB_H
