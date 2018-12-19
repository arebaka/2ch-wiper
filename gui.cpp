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

    if (ui->noText->isChecked()) {
        setup.set_mode("2");
        if (ui->chaining0->isChecked()) setup.set_triggerForm("1");
        else if (ui->trigger0->isChecked()) setup.set_triggerForm("2");
        else if (ui->loaf0->isChecked()) setup.set_triggerForm("3");
        else if (ui->oppost0->isChecked()) setup.set_triggerForm("4");
        else setup.set_triggerForm("0");
    }
    else if (ui->quoting->isChecked()) {
        setup.set_mode("3");
        if (ui->chaining1->isChecked()) setup.set_triggerForm("1");
        else if (ui->trigger1->isChecked()) setup.set_triggerForm("2");
        else if (ui->loaf1->isChecked()) setup.set_triggerForm("3");
        else if (ui->oppost1->isChecked()) setup.set_triggerForm("4");
        else setup.set_triggerForm("0");
    }
    else if (ui->copying->isChecked()) {
        setup.set_mode("7");
        if (ui->chaining2->isChecked()) setup.set_triggerForm("1");
        else if (ui->trigger2->isChecked()) setup.set_triggerForm("2");
        else if (ui->loaf2->isChecked()) setup.set_triggerForm("3");
        else if (ui->oppost2->isChecked()) setup.set_triggerForm("4");
        else setup.set_triggerForm("0");
    }
    else if (ui->overload->isChecked()) {
        setup.set_mode("5");
        if (ui->chaining3->isChecked()) setup.set_triggerForm("1");
        else if (ui->trigger3->isChecked()) setup.set_triggerForm("2");
        else if (ui->loaf3->isChecked()) setup.set_triggerForm("3");
        else if (ui->oppost3->isChecked()) setup.set_triggerForm("4");
        else setup.set_triggerForm("0");
    }
    else if (ui->pastes->isChecked()) {
        setup.set_mode("4");
        if (ui->chaining4->isChecked()) setup.set_triggerForm("1");
        else if (ui->trigger4->isChecked()) setup.set_triggerForm("2");
        else if (ui->loaf4->isChecked()) setup.set_triggerForm("3");
        else if (ui->oppost4->isChecked()) setup.set_triggerForm("4");
        else setup.set_triggerForm("0");
    }
    else if (ui->random->isChecked()) {
        setup.set_mode("0");
        setup.set_triggerForm("0");
    }

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



void GUI::mouseMoveEvent (QMouseEvent * event) {
    if (event->buttons() & Qt::LeftButton) {
        QPoint diff = event->pos() - mpos;
        QPoint newpos = this->pos() + diff;
        this->move(newpos);
    }
}

void GUI::mousePressEvent (QMouseEvent * event) {
    mpos = event->pos();
}



void GUI::closeEvent (QCloseEvent * event) {
    system("q\nexit");
}

void GUI::on_close_clicked () {
    close();
}

void GUI::on_rollUp_clicked () {
    showMinimized();
}

