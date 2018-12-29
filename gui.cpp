#include "gui.h"
#include "ui_gui.h"
#include <stdlib.h>

GUI::GUI (QWidget * parent)
    : QMainWindow(parent) , ui(new Ui::GUI) , started(false)
{
    ui->setupUi(this);
    fileDialog = new QFileDialog;

    QFile style;
    style.setFileName(QDir::currentPath() + "/gui/gui.css");
    style.open(QFile::ReadOnly);
    QString QSS = style.readAll();
    setStyleSheet(QSS);

    music = new QSound(QDir::currentPath()+"/gui/gachi.wav");
    anima = new QMovie(QDir::currentPath()+"/gui/desu.gif");
    ui->anima->setMovie(anima);
    ui->musicButton->setChecked(false);
    ui->peedorBarButton->setChecked(false);
    isPidor = false;
    isPlaying = false;
    ui->rollUp->hide();
    ui->close->hide();

    ui->key->setEchoMode(QLineEdit::Password);

    ui->triggerSet->hide();
    ui->sageSet->hide();
    ui->shaskalSet->hide();
    ui->randChaos->setDisabled(true);
    ui->toThread->setDisabled(true);
    ui->key->setDisabled(true);
    ui->imagesCount->setDisabled(true);
    ui->videosCount->setDisabled(true);
    ui->imagesFolder->setDisabled(true);
    ui->videosFolder->setDisabled(true);

    ui->board->setDisabled(true);
    ui->thread->setDisabled(true);
    ui->potocks->setDisabled(true);
    ui->shrapnelBoard->setDisabled(true);
    ui->threads->setDisabled(true);
    ui->minPosts->setDisabled(true);
    ui->shrapnelPotocks->setDisabled(true);
}

GUI::~GUI () {
    delete ui;
}

void GUI::debug (const char &mode) {
    setup.set_logMode(mode);
}




void GUI::on_button_clicked () {
    if (started == false) {
        //if (start()) started = true;
        start();
    } else stop();
}

bool GUI::start () {
    setup.clear();
    ui->textBrowser->clear();

    if (ui->mainMode->isChecked()) {
        setup.set_board(ui->board->currentText().toStdString());
        setup.set_potocksCount(ui->potocks->text().toStdString());
        setup.set_thread(ui->thread->text().toStdString());

    } else if (ui->shrapnelMode->isChecked()) {
        setup.set_board(ui->shrapnelBoard->currentText().toStdString());
        setup.set_minPostsCount(ui->minPosts->text().toStdString());
        setup.set_potocksCount(ui->shrapnelPotocks->text().toStdString());
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
    else if (ui->quoting->isChecked())
        setup.set_mode("3");
    else if (ui->copying->isChecked())
        setup.set_mode("7");
    else if (ui->overload->isChecked())
        setup.set_mode("5");
    else if (ui->pastes->isChecked())
        setup.set_mode("4");
    else if (ui->random->isChecked()) {
        setup.set_mode("0");
        setup.set_triggerForm("0");
    }

    if (!ui->random->isChecked()) {
        if (ui->chaining->isChecked()) setup.set_triggerForm("1");
        else if (ui->randTrigger->isChecked()) setup.set_triggerForm("2");
        else if (ui->shashlik->isChecked()) setup.set_triggerForm("3");
        else if (ui->oppost->isChecked()) setup.set_triggerForm("4");
        else setup.set_triggerForm("0");
    }

    if (ui->chaos->isChecked()) {
        if (ui->randChaos->isChecked())
            setup.set_chaos("0");
        else
            setup.set_chaos(ui->toThread->text().toStdString());
    }

    if (ui->images->isChecked()) {
        setup.set_mediaKind('1');
        setup.set_mediasCount(ui->imagesCount->text().toStdString());
        setup.set_mediaGroup(ui->imagesFolder->text().toStdString());
    } else if (ui->videos->isChecked()) {
        setup.set_mediaKind('2');
        setup.set_mediasCount(ui->videosCount->text().toStdString());
        setup.set_mediaGroup(ui->videosFolder->text().toStdString());
    } else if (ui->medias->isChecked())
        setup.set_mediaKind('3');
    else if (ui->noMedia->isChecked())
        setup.set_mediaKind('0');

    if (ui->sage->isChecked())
        if (ui->sageFromPosts->isChecked())
            setup.set_sageMode('2');
        else
            setup.set_sageMode('1');
    else setup.set_sageMode('0');

    setup.set_shackal_power(ui->shakalPower->value());
    setup.set_shackal_color(ui->shakalColor->isChecked());
    setup.set_shackal_affine(ui->shakalAffine->isChecked());
    setup.set_2PNG(ui->toPNG->isChecked());

    vector<string> response(setup.start());
    if (!(response[0] == "OK")) {
        string errors("");
        for (unsigned char i(0); i < response.size(); i++)
            errors += (response[i] + "\n");
        ui->textBrowser->setText(errors.c_str());
        return false;
    } else
        return true;
}

bool GUI::stop () {
    system("q");
    started = false;
}



void GUI::mouseMoveEvent (QMouseEvent * event) {
    if (!isPidor) return;
    if (event->buttons() & Qt::LeftButton) {
        QPoint diff = event->pos() - mpos;
        QPoint newpos = this->pos() + diff;
        this->move(newpos);
    }
}

void GUI::mousePressEvent (QMouseEvent * event) {
    if (!isPidor) return;
    mpos = event->pos();
}



void GUI::closeEvent (QCloseEvent * event) {
    system("exit");
}

void GUI::exposeEvent (QExposeEvent * event) {
    event->ignore();
}

void GUI::on_close_clicked () {
    close();
}

void GUI::on_rollUp_clicked () {
    showMinimized();
}



void GUI::on_musicButton_clicked () {
    if (!isPlaying) {
        music->play();
        anima->start();
        ui->musicButton->setChecked(true);
        isPlaying = true;
        ui->musicButton->repaint();
    } else {
        music->stop();
        anima->stop();
        ui->musicButton->setChecked(false);
        isPlaying = false;
        ui->musicButton->repaint();
    }
}

void GUI::on_peedorBarButton_clicked () {
    if (!isPidor) {
        setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
        show();
        ui->rollUp->show();
        ui->close->show();
        isPidor = true;
        ui->peedorBarButton->setChecked(true);
        ui->peedorBarButton->repaint();

    } else {
        setWindowFlags(windowFlags() & ~Qt::FramelessWindowHint);
        show();
        ui->rollUp->hide();
        ui->close->hide();
        isPidor = false;
        ui->peedorBarButton->setChecked(false);
        ui->peedorBarButton->repaint();
    }
}



void GUI::on_noText_clicked () {
    ui->triggerSet->show();
}

void GUI::on_quoting_clicked () {
    ui->triggerSet->show();
}

void GUI::on_copying_clicked () {
    ui->triggerSet->show();
}

void GUI::on_overload_clicked () {
    ui->triggerSet->show();
}

void GUI::on_pastes_clicked () {
    ui->triggerSet->show();
}

void GUI::on_random_clicked () {
    ui->triggerSet->hide();
}

void GUI::on_sage_clicked (bool checked) {
    if (checked) ui->sageSet->show();
    else ui->sageSet->hide();
}

void GUI::on_serverKey_clicked (bool checked) {
    if (checked) ui->key->setDisabled(true);
    else ui->key->setDisabled(false);
}

void GUI::on_chaos_clicked (bool checked) {
    if (checked) {
        ui->randChaos->setDisabled(false);
        if (!ui->randChaos->isChecked())
            ui->toThread->setDisabled(false);
    } else {
        ui->randChaos->setDisabled(true);
        ui->toThread->setDisabled(true);
    }
}

void GUI::on_randChaos_clicked (bool checked) {
    if (checked) ui->toThread->setDisabled(true);
    else ui->toThread->setDisabled(false);
}





void GUI::on_images_clicked () {
    ui->imagesCount->setDisabled(false);
    ui->videosCount->setDisabled(true);
    ui->imagesFolder->setDisabled(false);
    ui->videosFolder->setDisabled(true);
    ui->shaskalSet->show();
}

void GUI::on_videos_clicked () {
    ui->imagesCount->setDisabled(true);
    ui->videosCount->setDisabled(false);
    ui->imagesFolder->setDisabled(true);
    ui->videosFolder->setDisabled(false);
    ui->shaskalSet->hide();
}

void GUI::on_medias_clicked () {
    ui->imagesCount->setDisabled(true);
    ui->videosCount->setDisabled(true);
    ui->imagesFolder->setDisabled(true);
    ui->videosFolder->setDisabled(true);
    ui->shaskalSet->show();
}

void GUI::on_noMedia_clicked () {
    ui->imagesCount->setDisabled(true);
    ui->videosCount->setDisabled(true);
    ui->imagesFolder->setDisabled(true);
    ui->videosFolder->setDisabled(true);
    ui->shaskalSet->hide();
}





void GUI::on_openButton_clicked () {
    std::string fileName = fileDialog->getOpenFileName().toStdString();
    std::ifstream config(fileName);
    std::string value;

    getline(config, value);
    if (value == "main") {
        ui->mainMode->setChecked(true);
        ui->board->setDisabled(false);
        ui->thread->setDisabled(false);
        ui->potocks->setDisabled(false);
        ui->shrapnelBoard->setDisabled(true);
        ui->threads->setDisabled(true);
        ui->minPosts->setDisabled(true);
        ui->shrapnelPotocks->setDisabled(true);
    } else if (value == "shrapnel") {
        ui->shrapnelMode->setChecked(true);
        ui->board->setDisabled(true);
        ui->thread->setDisabled(true);
        ui->potocks->setDisabled(true);
        ui->shrapnelBoard->setDisabled(false);
        ui->threads->setDisabled(false);
        ui->minPosts->setDisabled(false);
        ui->shrapnelPotocks->setDisabled(false);
    }

    getline(config, value);
    ui->board->setCurrentText(value.c_str());
    getline(config, value);
    ui->thread->setText(value.c_str());
    getline(config, value);
    ui->potocks->setText(value.c_str());
    getline(config, value);
    ui->shrapnelBoard->setCurrentText(value.c_str());
    getline(config, value);
    ui->threads->setText(value.c_str());
    getline(config, value);
    ui->minPosts->setText(value.c_str());
    getline(config, value);
    ui->shrapnelPotocks->setText(value.c_str());

    getline(config, value);
    if (value == "anticaptcha") ui->anticaptcha->setChecked(true);
    else if (value == "guro-captcha") ui->gurocaptcha->setChecked(true);
    else if (value == "x-captcha") ui->x_captcha->setChecked(true);
    else if (value == "(reserved)") ui->reserved->setChecked(true);

    getline(config, value);
    ui->key->setText(value.c_str());
    getline(config, value);
    if (value == "from server") {
        ui->serverKey->setChecked(true);
        ui->key->setDisabled(true);
    } else {
        ui->serverKey->setChecked(false);
        ui->key->setDisabled(false);
    }

    getline(config, value);
    ui->repeats->setText(value.c_str());

    getline(config, value);
    if (value == "no text") {
        ui->noText->setChecked(true);
        ui->triggerSet->show();
    } else if (value == "quoting") {
        ui->quoting->setChecked(true);
        ui->triggerSet->show();
    } else if (value == "copying") {
        ui->copying->setChecked(true);
        ui->triggerSet->show();
    } else if (value == "overload") {
        ui->overload->setChecked(true);
        ui->triggerSet->show();
    } else if (value == "pastes") {
        ui->pastes->setChecked(true);
        ui->triggerSet->show();
    } else if (value == "random") {
        ui->random->setChecked(true);
        ui->triggerSet->hide();
    } else
        ui->triggerSet->hide();

    getline(config, value);
    if (value == "chaining") ui->chaining->setChecked(true);
    else if (value == "random") ui->randTrigger->setChecked(true);
    else if (value == "shashlik") ui->shashlik->setChecked(true);
    else if (value == "op post") ui->oppost->setChecked(true);
    else if (value == "no trigger") ui->notrigger->setChecked(true);

    getline(config, value);
    if (value == "chaos") {
        ui->chaos->setChecked(true);
        ui->randChaos->setDisabled(false);
        ui->toThread->setDisabled(false);
    } else {
        ui->chaos->setChecked(false);
        ui->randChaos->setDisabled(true);
        ui->toThread->setDisabled(true);
    }
    getline(config, value);
    if (value == "random") {
        ui->randChaos->setChecked(true);
        ui->toThread->setDisabled(true);
    } else
        ui->randChaos->setChecked(false);
    getline(config, value);
    ui->toThread->setText(value.c_str());

    getline(config, value);
    if (value == "sage") {
        ui->sage->setChecked(true);
        ui->sageSet->show();
    } else {
        ui->sage->setChecked(false);
        ui->sageSet->hide();
    }
    getline(config, value);
    if (value == "always") ui->sageAlways->setChecked(true);
    else if (value == "from posts") ui->sageFromPosts->setChecked(true);

    getline(config, value);
    if (value == "images") {
        ui->images->setChecked(true);
        ui->imagesCount->setDisabled(false);
        ui->videosCount->setDisabled(true);
        ui->imagesFolder->setDisabled(false);
        ui->videosFolder->setDisabled(true);
        ui->shaskalSet->show();
    } else if (value == "videos") {
        ui->videos->setChecked(true);
        ui->imagesCount->setDisabled(true);
        ui->videosCount->setDisabled(false);
        ui->imagesFolder->setDisabled(true);
        ui->videosFolder->setDisabled(false);
        ui->shaskalSet->hide();
    } else if (value == "medias") {
        ui->medias->setChecked(true);
        ui->imagesCount->setDisabled(true);
        ui->videosCount->setDisabled(true);
        ui->imagesFolder->setDisabled(true);
        ui->videosFolder->setDisabled(true);
        ui->shaskalSet->show();
    } else if (value == "nothing") {
        ui->noMedia->setChecked(true);
        ui->imagesCount->setDisabled(true);
        ui->videosCount->setDisabled(false);
        ui->imagesFolder->setDisabled(true);
        ui->videosFolder->setDisabled(true);
        ui->shaskalSet->hide();
    }
    getline(config, value);
    ui->imagesCount->setText(value.c_str());
    getline(config, value);
    ui->videosCount->setText(value.c_str());
    getline(config, value);
    ui->imagesFolder->setText(value.c_str());
    getline(config, value);
    ui->videosFolder->setText(value.c_str());

    getline(config, value);
    ui->shakalPower->setValue(atoi(value.c_str()));
    getline(config, value);
    if (value == "color") ui->shakalColor->setChecked(true);
    getline(config, value);
    if (value == "affine") ui->shakalAffine->setChecked(true);
}

void GUI::on_saveButton_clicked () {
    std::string fileName = fileDialog->getSaveFileName().toStdString();
    std::ofstream config(fileName);

    if (ui->mainMode->isChecked()) config << "main";
    else if (ui->shrapnelMode->isChecked()) config << "shrapnel";
    config << std::endl;

    config << ui->board->currentText().toStdString() << std::endl << ui->thread->text().toStdString() << std::endl << ui->potocks->text().toStdString() << std::endl << ui->shrapnelBoard->currentText().toStdString() << std::endl << ui->threads->text().toStdString() << std::endl << ui->minPosts->text().toStdString() << std::endl << ui->shrapnelPotocks->text().toStdString() << std::endl;

    if (ui->anticaptcha->isChecked()) config << "anticaptcha";
    else if (ui->gurocaptcha->isChecked()) config << "guro-captcha";
    else if (ui->x_captcha->isChecked()) config << "x-captcha";
    else if (ui->reserved->isChecked()) config << "(reserved)";
    config << std::endl;

    config << ui->key->text().toStdString() << std::endl;
    if (ui->serverKey->isChecked()) config << "from server";
    config << std::endl;

    config << ui->repeats->text().toStdString() << std::endl;

    if (ui->noText->isChecked()) config << "no text";
    else if (ui->quoting->isChecked()) config << "quoting";
    else if (ui->copying->isChecked()) config << "copying";
    else if (ui->overload->isChecked()) config << "overload";
    else if (ui->pastes->isChecked()) config << "pastes";
    else if (ui->random->isChecked()) config << "random";
    config << std::endl;

    if (ui->chaining->isChecked()) config << "chaining";
    else if (ui->randTrigger->isChecked()) config << "random";
    else if (ui->shashlik->isChecked()) config << "shashlik";
    else if (ui->oppost->isChecked()) config << "op post";
    else if (ui->notrigger->isChecked()) config << "no trigger";
    config << std::endl;

    if (ui->chaos->isChecked()) config << "chaos";
    config << std::endl;
    if (ui->randChaos->isChecked()) config << "random";
    config << std::endl;
    config << ui->toThread->text().toStdString() << std::endl;

    if (ui->sage->isChecked()) config << "sage";
    config << std::endl;
    if (ui->sageAlways->isChecked()) config << "always";
    else if (ui->sageFromPosts->isChecked()) config << "from posts";
    config<< std::endl;

    if (ui->images->isChecked()) config << "images";
    else if (ui->videos->isChecked()) config << "videos";
    else if (ui->medias->isChecked()) config << "medias";
    else if (ui->noMedia->isChecked()) config << "nothing";
    config << std::endl;

    config << ui->imagesCount->text().toStdString() << std::endl;
    config << ui->videosCount->text().toStdString() << std::endl;
    config << ui->imagesFolder->text().toStdString() << std::endl;
    config << ui->videosFolder->text().toStdString() << std::endl;

    config << ui->shakalPower->value() << std::endl;
    if (ui->shakalColor->isChecked()) config << "color";
    config << std::endl;
    if (ui->shakalAffine->isChecked()) config << "affine";
    config << std::endl;
}





void GUI::on_mainMode_clicked () {
    ui->board->setDisabled(false);
    ui->thread->setDisabled(false);
    ui->potocks->setDisabled(false);
    ui->shrapnelBoard->setDisabled(true);
    ui->threads->setDisabled(true);
    ui->minPosts->setDisabled(true);
    ui->shrapnelPotocks->setDisabled(true);
}

void GUI::on_shrapnelMode_clicked () {
    ui->board->setDisabled(true);
    ui->thread->setDisabled(true);
    ui->potocks->setDisabled(true);
    ui->shrapnelBoard->setDisabled(false);
    ui->threads->setDisabled(false);
    ui->minPosts->setDisabled(false);
    ui->shrapnelPotocks->setDisabled(false);
}
