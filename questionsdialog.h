#ifndef QUESTIONSDIALOG_H
#define QUESTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class QuestionsDialog;
}

class QuestionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionsDialog(QWidget *parent = nullptr);
    ~QuestionsDialog();

private:
    Ui::QuestionsDialog *ui;
};

#endif // QUESTIONSDIALOG_H
