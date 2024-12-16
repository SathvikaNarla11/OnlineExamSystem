#include "signupdetailsintodb.h"
#include <QCoreApplication>
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#define CONNECT QObject::connect

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow window;
    QWidget *mainwidget = new QWidget(&window);
    QHBoxLayout *mainHLayout = new QHBoxLayout(mainwidget);

    QGroupBox *SignInGB = new QGroupBox("SIGN-IN",mainwidget);
    SignInGB->setFixedSize(300, 370);

    QVBoxLayout *vlayout2 = new QVBoxLayout(); //Vertical layout for name and passowrd
    QVBoxLayout *vlayout3 = new QVBoxLayout();
    QVBoxLayout *vlayout4 = new QVBoxLayout(SignInGB);

    QHBoxLayout *hlayoutName = new QHBoxLayout(); //hlayout name
    QLabel *nameSILabel = new QLabel("Name : ");
    QLineEdit *nameSILineEdit = new QLineEdit();
    nameSILineEdit->setFixedWidth(200);

    hlayoutName->addWidget(nameSILabel);
    hlayoutName->addWidget(nameSILineEdit);

    QHBoxLayout *hlayoutPwd = new QHBoxLayout(); //hlayout pwd
    QLabel *pwdSILabel = new QLabel("Password : " );
    QLineEdit *pwdSILineEdit = new QLineEdit();
    pwdSILineEdit->setFixedWidth(200);
    hlayoutPwd->addWidget(pwdSILabel);
    hlayoutPwd->addWidget(pwdSILineEdit);

    QPushButton *signInBtn = new QPushButton("SignIn");

    vlayout2->addLayout(hlayoutName); //v2 layout for name and psw
    vlayout2->addLayout(hlayoutPwd);
    vlayout2->addWidget(signInBtn);
    vlayout2->setAlignment(Qt::AlignLeft);

    QLabel *emptyLabel = new QLabel(" ", SignInGB); //empty label
    emptyLabel->setFixedHeight(25);
    QLabel *orLabel = new QLabel("SignUp to create a new account ", SignInGB); //or label
    orLabel->setFixedHeight(30);
    QPushButton *btnSignUp = new QPushButton("SignUp",SignInGB); //sign up btn
    btnSignUp->setFixedWidth(80);

    vlayout3->addWidget(orLabel); //vlayout3 for empty, or, signup btn
    vlayout3->addWidget(btnSignUp);
    vlayout3->setSpacing(0);
    vlayout3->setAlignment(Qt::AlignLeft);

    vlayout4->addLayout(vlayout2);
    vlayout4->addWidget(emptyLabel);
    vlayout4->addLayout(vlayout3);
    vlayout4->setAlignment(Qt::AlignHCenter);


    /********************************************************************************************/

    QGroupBox *SignUpGB = new QGroupBox("SIGN UP",mainwidget);
    SignUpGB->setFixedSize(300, 370);
    SignUpGB->hide();
    QVBoxLayout *gbVLayout = new QVBoxLayout(SignUpGB);

    QHBoxLayout *nameSUHLayout = new QHBoxLayout();
    QLabel *nameSULabel = new QLabel("Name : ", SignUpGB);
    QLineEdit *nameSULineEdit = new QLineEdit(SignUpGB);
    nameSULineEdit->setFixedWidth(160);
    nameSUHLayout->addWidget(nameSULabel);
    nameSUHLayout->addWidget(nameSULineEdit);

    QHBoxLayout *pwdSUHLayout = new QHBoxLayout();
    QLabel *pwdSULabel = new QLabel("Password : ", SignUpGB);
    QLineEdit *pwdSULineEdit = new QLineEdit(SignUpGB);
    pwdSULineEdit->setFixedWidth(160);
    pwdSUHLayout->addWidget(pwdSULabel);
    pwdSUHLayout->addWidget(pwdSULineEdit);

    QHBoxLayout *RpwdSUHLayout = new QHBoxLayout();
    QLabel *RpwdSULabel = new QLabel("Re-enter Password : ", SignUpGB);
    QLineEdit *RpwdSULineEdit = new QLineEdit(SignUpGB);
    RpwdSULineEdit->setFixedWidth(160);
    RpwdSUHLayout->addWidget(RpwdSULabel);
    RpwdSUHLayout->addWidget(RpwdSULineEdit);

    QHBoxLayout *emailSUHLayout = new QHBoxLayout();
    QLabel *emailSULabel = new QLabel("Email-ID : ", SignUpGB);
    QLineEdit *emailSULineEdit = new QLineEdit(SignUpGB);
    emailSULineEdit->setFixedWidth(160);
    emailSUHLayout->addWidget(emailSULabel);
    emailSUHLayout->addWidget(emailSULineEdit);

    QHBoxLayout *mobileNumSUHLayout = new QHBoxLayout();
    QLabel *mobileNumSULabel = new QLabel("Mobile Number : ", SignUpGB);
    QLineEdit *mobileNumSULineEdit = new QLineEdit(SignUpGB);
    mobileNumSULineEdit->setFixedWidth(160);
    mobileNumSUHLayout->addWidget(mobileNumSULabel);
    mobileNumSUHLayout->addWidget(mobileNumSULineEdit);

    QPushButton *CreateAccount = new QPushButton("Create Account");

    gbVLayout->addLayout(nameSUHLayout);
    gbVLayout->addLayout(pwdSUHLayout);
    gbVLayout->addLayout(RpwdSUHLayout);
    gbVLayout->addLayout(emailSUHLayout);
    gbVLayout->addLayout(mobileNumSUHLayout);
    gbVLayout->addWidget(CreateAccount);
    gbVLayout->setAlignment(Qt::AlignHCenter);

    SignUpDetailsIntoDB signUpObj;

    QObject::connect(btnSignUp, &QPushButton::clicked, [=]() {
        SignUpGB->show();

    });


    QObject::connect(CreateAccount, &QPushButton::clicked, [&](){
        qDebug()<<"Invoked";
        signUpObj.on_pushBtn_CreateAccClicked(nameSULineEdit, pwdSULineEdit, RpwdSULineEdit, emailSULineEdit, mobileNumSULineEdit);

    });


    QObject::connect(signInBtn, &QPushButton::clicked, [&](){
        qDebug()<<"Called";
        signUpObj.loginFun(nameSILineEdit, pwdSILineEdit);
    });



    mainHLayout->addWidget(SignInGB);
    mainHLayout->addWidget(SignUpGB);
    mainHLayout->setAlignment(Qt::AlignLeft);
    window.setCentralWidget(mainwidget);
    window.setFixedSize(700, 400);
    window.show();
    return a.exec();
}


// QObject::connect(CreateAccount, &QPushButton::clicked, [&](){
//     qDebug()<<"Invoked";
//     SignUpGB->hide();
//     signUpObj.on_pushBtn_signUpClicked(nameSULineEdit, pwdSULineEdit, RpwdSULineEdit, emailSULineEdit, mobileNumSULineEdit);
// });


// Set up code that uses the Qt event loop here.
// Call a.quit() or a.exit() to quit the application.
// A not very useful example would be including
// #include <QTimer>
// near the top of the file and calling
// QTimer::singleShot(5000, &a, &QCoreApplication::quit);
// which quits the application after 5 seconds.

// If you do not need a running Qt event loop, remove the call
// to a.exec() or use the Non-Qt Plain C++ Application template.
