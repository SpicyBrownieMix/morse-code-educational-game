#ifndef SHOWALLDIALOG_H
#define SHOWALLDIALOG_H

#include <QDialog>
#include <string>
#include <QLabel>

/** This class was made for the Assignment 9, Educational App, in CS3505 at the University of Utah.
 *
 * @brief The ShowAllDialog class
 * This calss controls the Entire Message Popoup box that appears when the user clicks on the
 * "Show Entire Message" button. This class is primarily just responsible for setting up the ui, and has
 * little associated logic.
 *
 * @version April 2024
 * @author Spencer Hoth
 */

namespace Ui {
class ShowAllDialog;
}

class ShowAllDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief ShowAllDialog
     * @param parent
     * Constructor for the show entire message dialog window. Initializes the layout.
     */
    explicit ShowAllDialog(QWidget *parent = nullptr);
    ~ShowAllDialog();
    /**
     * @brief setText
     * @param s text the will be displayed
     * Puts inputted string onto the window.
     */
    void setText(std::string s);

private:
    Ui::ShowAllDialog *ui; // ui
    QLabel *label; // label that holds the text of the window
};

#endif // SHOWALLDIALOG_H
