#ifndef GUI_H
#define GUI_H
#include <QMainWindow>
#include <QFile>
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

private:
    Ui::GUI * ui;

    bool started;  // start/stop
    bool start();
    bool stop();

    void closeEvent (QCloseEvent * event);

};

#endif // GUI_H
