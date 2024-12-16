#include "questionsdialog.h"
#include "ui_questionsdialog.h"

QuestionsDialog::QuestionsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QuestionsDialog)
{
    ui->setupUi(this);
}

QuestionsDialog::~QuestionsDialog()
{
    delete ui;
}
