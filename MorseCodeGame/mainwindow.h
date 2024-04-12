#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include <QMainWindow>
#include <string>
#include <QtMultimedia>
#include "referencesheetdialog.h"
#include "showalldialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Model& model, QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void submitTextInput(QString text);
    void refrenceOpened();

public slots:
    void textEditingComplete();
    void playDotSound();
    void playDashSound();
    void recieveMorseChar(std::string s);
    void clearMorseBox();
    void toggleCaptain();
    void showCaptainText(QString text);
    void showRefrenceSheet();
    void showEntireMessage();
    void showCurrentStreak(int streak);

private:
    Ui::MainWindow *ui;
    Model* model;
    QMediaPlayer *dotPlayer;
    QAudioOutput *dotAudioOutput;
    QMediaPlayer *dashPlayer;
    QAudioOutput *dashAudioOutput;
    ReferenceSheetDialog* referenceSheetDialog;
    ShowAllDialog* showAllDialog;
};
#endif // MAINWINDOW_H
