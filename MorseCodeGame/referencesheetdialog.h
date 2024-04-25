#ifndef REFERENCESHEETDIALOG_H
#define REFERENCESHEETDIALOG_H

#include <QDialog>
#include<QLabel>
#include<QVBoxLayout>

/** This class was made for the Assignment 9, Educational App, in CS3505 at the University of Utah.
 *
 * @brief The ReferenceSheetDialog class
 * This calss controls the Reference Sheet Popoup box that appears when the user clicks on the
 * reference sheet button. This class is primarily just responsible for setting up the ui, and has
 * little associated logic.
 *
 * @version April 2024
 * @author Spencer Hoth
 */

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
