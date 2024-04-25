#ifndef REFERENCESHEETDIALOG_H
#define REFERENCESHEETDIALOG_H

#include <QDialog>
#include<QLabel>
#include<QVBoxLayout>

namespace Ui {
class ReferenceSheetDialog;
}

class ReferenceSheetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReferenceSheetDialog(QWidget *parent = nullptr);
    ~ReferenceSheetDialog();
    void setBatch(int batch);

private:
    Ui::ReferenceSheetDialog *ui;
    QVBoxLayout *batchOneLayout;
    QVBoxLayout *batchTwoLayout;
    QVBoxLayout *batchThreeLayout;
    QVBoxLayout *batchFourLayout;
    QVBoxLayout *batchFiveLayout;
    QVBoxLayout *batchSixLayout;
    void addMorseCode(QVBoxLayout *layout, const QString &character, const QString &code);
};

#endif // REFERENCESHEETDIALOG_H
