#ifndef SHOWALLDIALOG_H
#define SHOWALLDIALOG_H

#include <QDialog>

namespace Ui {
class ShowAllDialog;
}

class ShowAllDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowAllDialog(QWidget *parent = nullptr);
    ~ShowAllDialog();

private:
    Ui::ShowAllDialog *ui;
};

#endif // SHOWALLDIALOG_H
