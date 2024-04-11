#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include <QMainWindow>
#include <string>
#include <QtMultimedia>

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

public slots:
    void textEditingComplete();
    void playDotSound();
    void playDashSound();
    void recieveMorseChar(std::string s);
    void clearMorseBox();
    void toggleCaptain();
    void showCaptainText(QString text);

private:
    Ui::MainWindow *ui;
    Model* model;
    QMediaPlayer *dotPlayer;
    QAudioOutput *dotAudioOutput;
    QMediaPlayer *dashPlayer;
    QAudioOutput *dashAudioOutput;
};
#endif // MAINWINDOW_H
