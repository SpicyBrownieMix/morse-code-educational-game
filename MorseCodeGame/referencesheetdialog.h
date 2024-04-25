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
    /**
     * @brief ReferenceSheetDialog
     * @param parent
     * Constructor for the reference sheet dialog window. Initializes the layout.
     */
    explicit ReferenceSheetDialog(QWidget *parent = nullptr);
    ~ReferenceSheetDialog();
    /**
     * @brief setBatch
     * @param batch number indicating what level the player is on
     * Sets the letters on the reference sheet to the current level.
     */
    void setBatch(int batch);

private:
    Ui::ReferenceSheetDialog *ui; // ui
    QVBoxLayout *batchOneLayout; // layout for letter batch 1
    QVBoxLayout *batchTwoLayout; // layout for letter batch 2
    QVBoxLayout *batchThreeLayout; // layout for letter batch 3
    QVBoxLayout *batchFourLayout; // layout for letter batch 4
    QVBoxLayout *batchFiveLayout; // layout for letter batch 5
    QVBoxLayout *batchSixLayout; // layout for letter batch 6
    /**
     * @brief addMorseCode
     * @param layout where to add the letter and code
     * @param character  letter
     * @param code morse code of letter
     * Adds inputted letter and morse code pair to inputted layout
     */
    void addMorseCode(QVBoxLayout *layout, const QString &character, const QString &code);
};

#endif // REFERENCESHEETDIALOG_H
