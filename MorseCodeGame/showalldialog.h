#ifndef SHOWALLDIALOG_H
#define SHOWALLDIALOG_H

#include <QDialog>
#include <string>
#include <QLabel>

namespace Ui {
class ShowAllDialog;
}

class ShowAllDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowAllDialog(QWidget *parent = nullptr);
    ~ShowAllDialog();
    void setText(std::string s);

private:
    Ui::ShowAllDialog *ui;
    QLabel *label;
};

#endif // SHOWALLDIALOG_H
