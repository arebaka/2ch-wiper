#ifndef GUI_H
#define GUI_H
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QFile>
#include <QDir>
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

private:
    Ui::GUI * ui;

    bool started;  // start/stop
    bool start();
    bool stop();

    void closeEvent (QCloseEvent * event);

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
