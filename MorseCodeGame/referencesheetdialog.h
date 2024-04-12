#ifndef REFERENCESHEETDIALOG_H
#define REFERENCESHEETDIALOG_H

#include <QDialog>

namespace Ui {
class ReferenceSheetDialog;
}

class ReferenceSheetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReferenceSheetDialog(QWidget *parent = nullptr);
    ~ReferenceSheetDialog();

private:
    Ui::ReferenceSheetDialog *ui;
};

#endif // REFERENCESHEETDIALOG_H
