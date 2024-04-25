#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

/** This class was made for the Assignment 9, Educational App, in CS3505 at the University of Utah.
 *
 * @brief The AboutDialog class
 * This class controls the About popoup window that appears when the user clicks on the
 * about button. This class is primarily just responsible for setting up the ui, and has
 * little associated logic.
 *
 * @version April 2024
 * @author Spencer Hoth
 */

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief AboutDialog
     * @param parent
     * Constructor for the about dialog window. Initializes the layout.
     */
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();

private:
    Ui::AboutDialog *ui; //ui
};

#endif // ABOUTDIALOG_H
