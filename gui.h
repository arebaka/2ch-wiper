#ifndef GUI_H
#define GUI_H
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QFile>
#include <QDir>
#include <QSound>
#include <QFileDialog>
#include <QMovie>
#include <fstream>
#include "setup.h"

namespace Ui {
class GUI;
}

class GUI : public QMainWindow {
    Q_OBJECT

public:
    explicit GUI(QWidget * parent = nullptr);
    ~GUI();

    Setup setup;

private slots:
    void on_button_clicked();
    void on_close_clicked();
    void on_rollUp_clicked();
    void on_peedorBarButton_clicked();
    void on_noText_clicked();
    void on_quoting_clicked();
    void on_copying_clicked();
    void on_overload_clicked();
    void on_pastes_clicked();
    void on_random_clicked();
    void on_sage_clicked(bool checked);
    void on_serverKey_clicked(bool checked);
    void on_chaos_clicked(bool checked);
    void on_randChaos_clicked(bool checked);
    void on_musicButton_clicked();
    void on_images_clicked();
    void on_videos_clicked();
    void on_medias_clicked();
    void on_noMedia_clicked();
    void on_openButton_clicked();
    void on_saveButton_clicked();
    void on_mainMode_clicked();
    void on_shrapnelMode_clicked();

private:
    Ui::GUI * ui;
    QFileDialog * fileDialog;

    bool started;  // start/stop
    bool start();
    bool stop();

    void closeEvent (QCloseEvent * event);
    void exposeEvent(QExposeEvent * event);

    QSound * music;
    bool isPlaying;
    bool isPidor;
    QMovie * anima;

    QPoint mpos;
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);

};




class Term : public QPlainTextEdit {
public:
    Term (QWidget * parent) {
        QPalette p = palette();
        p.setColor(QPalette::Base, Qt::black);
        p.setColor(QPalette::Text, Qt::green);
        setPalette(p);
    }

    void keyPressEvent(QKeyEvent *event) {
        if (event->key() >= 0x20 && event->key() <= 0x7E && (event->modifiers() == Qt::NoModifier || event->modifiers() == Qt::ShiftModifier))
            QPlainTextEdit::keyPressEvent(event);
        if (event->key() == Qt::Key_Backspace && event->modifiers() == Qt::NoModifier)
            QPlainTextEdit::keyPressEvent(event);
        if (event->key() == Qt::Key_Return && event->modifiers() == Qt::NoModifier)
            ;
    }
    void mousePressEvent(QMouseEvent *) { setFocus(); }
    void mouseDoubleClickEvent(QMouseEvent *) {}
    void contentMenuEvent(QContextMenuEvent *) {}


};



#endif // GUI_H
