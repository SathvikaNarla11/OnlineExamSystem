#include "signupdetailsintodb.h"
#include "questionsdialog.h"

#include <QMessageBox>

SignUpDetailsIntoDB::SignUpDetailsIntoDB()
{
    questionDialogObj = new QuestionsDialog();
}

void SignUpDetailsIntoDB::on_pushBtn_CreateAccClicked(QLineEdit *nameSULineEdit, QLineEdit *pwdSULineEdit, QLineEdit *RpwdSULineEdit, QLineEdit *emailSULineEdit, QLineEdit *mobileNumSULineEdit)
{
    qDebug()<<"Create Account Clicked";
    QString name = nameSULineEdit->text();
    qDebug()<<name;

    QString password = pwdSULineEdit->text();
    qDebug()<<password;

    QString rePassword = RpwdSULineEdit->text();
    qDebug()<<rePassword;

    QString emailId = emailSULineEdit->text();
    qDebug()<<emailId;

    QString mobileNum = mobileNumSULineEdit->text();
    qDebug()<<mobileNum;

    if(name.isEmpty() || password.isEmpty() || rePassword.isEmpty() || emailId.isEmpty() || mobileNum.isEmpty())
    {
        qDebug()<<"All fields required";
        // QMessageBox::warning(this, "POP-UP", "All fields required");
        return;
    }

    if(password != rePassword)
    {
        qDebug()<<"Please check your password";
        return;
    }

    if(!connOpen()) //to open database connection
    {
        qDebug()<<"Not connected ";
    }

    QSqlQuery query;
    // query.prepare("INSERT into StudentSignUpDetails (Name, Password, EmailID, MobileNumber) values ('"+name+"', '"+password+"', '"+emailId+"', '"+mobileNum+"')");

    // Use a parameterized query to prevent SQL injection
    query.prepare("INSERT INTO StudentSignUpDetails (Name, Password, EmailID, MobileNumber) "
                  "VALUES (:name, :password, :email, :mobile)");
    query.bindValue(":name", name);
    query.bindValue(":password", password);
    query.bindValue(":email", emailId);
    query.bindValue(":mobile", mobileNum);

    if(query.exec())
    {
        qDebug()<<"query executed";
    }
    else
    {
        qDebug()<<"query not executed";
    }

    connClose();
}

void SignUpDetailsIntoDB::loginFun(QLineEdit *nameSILineEdit, QLineEdit *pwdSILineEdit)
{
    qDebug()<<"Login function call";
    QString nameSI = nameSILineEdit->text();
    QString pwdSI = pwdSILineEdit->text();

    qDebug()<<nameSI;
    qDebug()<<pwdSI;

    if(nameSI.isEmpty() || pwdSI.isEmpty())
    {
        qDebug()<<"All fields required";
        return;
    }

    if(!connOpen())
    {
        qDebug()<<"DB for signIn not connected";
    }

    QSqlQuery query;
    if(query.exec("SELECT * from StudentSignUpDetails where Name = '"+nameSI+"' AND Password = '"+pwdSI+"' "))
    {
        int cnt = 0;
        while(query.next())
        {
            cnt++;
        }
        qDebug()<<"Cnt : "<<cnt;
        if(cnt ==1)
        {
            qDebug()<<"Login successfull";
        }
        else if(cnt == 0)
        {
            qDebug()<<"Enter valid credentials";
        }
    }

    connClose();
}












