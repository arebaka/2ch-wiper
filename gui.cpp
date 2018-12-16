#include "gui.h"
#include "ui_gui.h"

GUI::GUI (QWidget * parent)
    : QMainWindow(parent) , ui(new Ui::GUI) , started(false)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);

    QFile style;
    style.setFileName(QDir::currentPath() + "/gui/gui.css");
    style.open(QFile::ReadOnly);
    QString QSS = style.readAll();
    setStyleSheet(QSS);

}

GUI::~GUI () {
    delete ui;
    system("exit");
}





void GUI::on_button_clicked () {
    if (started == false) {
        if (start()) started = true;
    } else stop();
}

bool GUI::start () {
    setup.clear();
    ui->textBrowser->clear();

    if (ui->mainMode->isChecked()) {
        setup.set_board(ui->board->text().toStdString());
        setup.set_potocksCount(ui->potocks->text().toStdString());
        setup.set_thread(ui->thread->text().toStdString());
    } else if (ui->shrapnelMode->isChecked()) {
        setup.set_board(ui->board->text().toStdString());
        setup.set_potocksCount(ui->potocks->text().toStdString());
        setup.set_thread("1");
        setup.set_shrapnelCharge(ui->threads->text().toStdString());
    }

    if (ui->anticaptcha->isChecked())
        setup.set_solver("2");
    else if (ui->x_captcha->isChecked())
        setup.set_solver("0");
    else if (ui->gurocaptcha->isChecked())
        setup.set_solver("1");

    if (ui->serverKey->isChecked())
        setup.set_key("");
    else if (ui->key->text() != "")
        setup.set_key(ui->key->text().toStdString());

    setup.set_proxyRepeatsCount(ui->repeats->text().toStdString());

    if (ui->noText->isChecked())
        setup.set_mode("2");
    else if (ui->overload->isChecked())
        setup.set_mode("5");
    else if (ui->quoting->isChecked())
        setup.set_mode("3");
    else if (ui->pastes->isChecked())
        setup.set_mode("4");
    else if (ui->copying->isChecked())
        setup.set_mode("7");
    else if (ui->random->isChecked())
        setup.set_mode("0");

    if (ui->images->isChecked()) {
        setup.set_mediaKind('1');
        setup.set_mediasCount(ui->imagesCount->text().toStdString());
    } else if (ui->videos->isChecked()) {
        setup.set_mediaKind('2');
        setup.set_mediasCount(ui->videosCount->text().toStdString());
    } else if (ui->medias->isChecked())
        setup.set_mediaKind('3');
    else if (ui->noMedia->isChecked())
        setup.set_mediaKind('0');

    if (ui->sage->isChecked())
        setup.set_sageMode('1');
    else setup.set_sageMode('0');

    vector<string> response(setup.start());
    if (!(response[0] == "OK")) {
        string errors("");
        for (unsigned char i(0); i < response.size(); i++)
            errors += (response[i] + "\n");
        ui->textBrowser->setText(errors.c_str());
        return false;
    } else return true;
}

bool GUI::stop () {
    system("q");
    started = false;
}



void GUI::closeEvent (QCloseEvent * event) {
    system("exit");
}

void GUI::on_close_clicked () {
    close();
}

void GUI::on_rollUp_clicked () {
    hide();
}

