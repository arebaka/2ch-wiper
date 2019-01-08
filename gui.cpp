#include "gui.h"
#include "ui_gui.h"
#include <stdlib.h>
#include <QDesktopWidget>

GUI::GUI (QWidget * parent)
    : QMainWindow(parent) , ui(new Ui::GUI) , started(false) , postsCount("0")
{
    ui->setupUi(this);
    fileDialog = new QFileDialog;
    ui->wipechan->set_blockquote(ui->blockquote);

    set_classes();

    QFile style;
    style.setFileName(QDir::currentPath()+"/gui/gui.css");
    style.open(QFile::ReadOnly);
    QString QSS = style.readAll();
    setStyleSheet(QSS);

    set_layout(QDir::currentPath().toStdString()+"/gui/layout");

    music = new QSound(QDir::currentPath()+"/gui/gachi.wav");
    anima = new QMovie(QDir::currentPath()+"/gui/desu.gif");
    ui->anima->setMovie(anima);
    ui->musicButton->setChecked(false);
    ui->peedorBarButton->setChecked(false);
    isPidor = false;
    isPlaying = false;
    ui->wipechan->uncall();
    ui->rollUp->hide();
    ui->close->hide();
    ui->backBanner->hide();

    ui->mainModeSet->hide();
    ui->shrapnelSet->hide();
    ui->triggerSet->hide();
    ui->complainSet->hide();
    ui->sageSet->hide();
    ui->shackalSet->hide();
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

    updateData();
}

GUI::~GUI () {
    delete ui;
}

void GUI::set_classes () {
    ui->topBanner->property("class");
    ui->backBanner->property("class");
    ui->topBanner->setProperty("class", "banner");
    ui->topBanner->setProperty("class", "banner");

    ui->helpButton->property("class");
    ui->peedorBarButton->property("class");
    ui->musicButton->property("class");
    ui->openButton->property("class");
    ui->saveButton->property("class");
    ui->helpButton->setProperty("class", "left-button");
    ui->peedorBarButton->setProperty("class", "left-button");
    ui->musicButton->setProperty("class", "left-button");
    ui->openButton->setProperty("class", "left-button");
    ui->saveButton->setProperty("class", "left-button");

    ui->rollUp->property("class");
    ui->close->property("class");
    ui->rollUp->setProperty("class", "right-button");
    ui->close->setProperty("class", "right-button");

    ui->mainSet->property("class");
    ui->solverSet->property("class");
    ui->postSet->property("class");
    ui->mediaSet->property("class");
    ui->mainSet->setProperty("class", "settings-frame");
    ui->solverSet->setProperty("class", "settings-frame");
    ui->postSet->setProperty("class", "settings-frame");
    ui->mediaSet->setProperty("class", "settings-frame");

    ui->mainSetHeader->property("class");
    ui->solverSetHeader->property("class");
    ui->postSetHeader->property("class");
    ui->mediaSetHeader->property("class");
    ui->mainSetHeader->setProperty("class", "settings-frame-header");
    ui->solverSetHeader->setProperty("class", "settings-frame-header");
    ui->postSetHeader->setProperty("class", "settings-frame-header");
    ui->mediaSetHeader->setProperty("class", "settings-frame-header");

    ui->mainModeSet->property("class");
    ui->shrapnelSet->property("class");
    ui->triggerSet->property("class");
    ui->complainSet->property("class");
    ui->sageSet->property("class");
    ui->shackalSet->property("class");
    ui->mainModeSet->setProperty("class", "box-frame");
    ui->shrapnelSet->setProperty("class", "box-frame");
    ui->triggerSet->setProperty("class", "box-frame");
    ui->complainSet->setProperty("class", "box-frame");
    ui->sageSet->setProperty("class", "box-frame");
    ui->shackalSet->setProperty("class", "box-frame");
}

void GUI::set_layout (std::string path) {
    std::string data, key, x, y, width, height, text;
    QWidget * widget;  QLabel * label;  QPushButton * button;  QCheckBox * checkBox;  QRadioButton * radioButton;  QLineEdit * edit;  QSpinBox * spin;
    char type;
    std::ifstream layout(path);
    if (layout.is_open()) {
        while(!layout.eof()) {
            getline(layout, data);
            if (!data.empty()) {
                key = data.substr(0, data.find(' '));
                data = data.substr(data.find(' ')+1, data.length()-1);
                if (key == "GUI") {
                    width = data.substr(0, data.find(' '));
                    height = data.substr(data.find(' ')+1, data.length()-1);
                    setMinimumSize(atoi(width.c_str()), atoi(height.c_str()));
                    setMaximumSize(atoi(width.c_str()), atoi(height.c_str()));
                    setGeometry(
                        QStyle::alignedRect(
                            Qt::LeftToRight,
                            Qt::AlignCenter,
                            QSize(atoi(width.c_str()), atoi(height.c_str())),
                            qApp->desktop()->availableGeometry()
                        )
                    );
                } else {
                    if (key == "top_banner") { widget = label = ui->topBanner; type = 'l'; }
                    else if (key == "help_button") { widget = button = ui->helpButton; type = 'b'; }
                    else if (key == "peedor_bar_button") { widget = button = ui->peedorBarButton; type = 'b'; }
                    else if (key == "music_button") { widget = button = ui->musicButton; type = 'b'; }
                    else if (key == "open_config_button") { widget = button = ui->openButton; type = 'b'; }
                    else if (key == "save_config_button") { widget = button = ui->saveButton; type = 'b'; }
                    else if (key == "username_label") { widget = label = ui->usernameLabel; type = 'l'; }
                    else if (key == "username") { widget = edit = ui->username; type = 'e'; }
                    else if (key == "roll_up_button") { widget = button = ui->rollUp; type = 'b'; }
                    else if (key == "close_button") { widget = button = ui->close; type = 'b'; }

                    else if (key == "main_set") { widget = ui->mainSet; type = 'w'; }
                    else if (key == "main_set_header") { widget = label = ui->mainSetHeader; type = 'l'; }

                    else if (key == "main_mode") { widget = radioButton = ui->mainMode; type = 'r'; }
                    else if (key == "main_mode_set") { widget = ui->mainModeSet; type = 'w'; }
                    else if (key == "board_label") { widget = label = ui->boardLabel; type = 'l'; }
                    else if (key == "board") { widget = ui->board; type = 'w'; }
                    else if (key == "thread_label") { widget = label = ui->threadLabel; type = 'l'; }
                    else if (key == "thread") { widget = edit = ui->thread; type = 'e'; }
                    else if (key == "potocks_label") { widget = label = ui->potocksLabel; type = 'l'; }
                    else if (key == "potocks") { widget = edit = ui->potocks; type = 'e'; }

                    else if (key == "shrapnel_mode") { widget = radioButton = ui->shrapnelMode; type = 'r'; }
                    else if (key == "shrapnel_set") { widget = ui->shrapnelSet; type = 'w'; }
                    else if (key == "shrapnel_board_label") { widget = label = ui->shrapnelBoardLabel; type = 'l'; }
                    else if (key == "shrapnel_board") { widget = ui->shrapnelBoard; type = 'w'; }
                    else if (key == "threads_label") { widget = label = ui->threadsLabel; type = 'l'; }
                    else if (key == "threads") { widget = edit = ui->threads; type = 'e'; }
                    else if (key == "min_posts_label") { widget = label = ui->minPostsLabel; type = 'l'; }
                    else if (key == "min_posts") { widget = edit = ui->minPosts; type = 'e'; }
                    else if (key == "shrapnel_potocks_label") { widget = label = ui->shrapnelPotocksLabel; type = 'l'; }
                    else if (key == "shrapnel_potocks") { widget = edit = ui->shrapnelPotocks; type = 'e'; }

                    else if (key == "solver_set") { widget = ui->solverSet; type = 'w'; }
                    else if (key == "solver_set_header") { widget = label = ui->solverSetHeader; type = 'l'; }

                    else if (key == "solver_label") { widget = label = ui->solverLabel; type = 'l'; }
                    else if (key == "anticaptcha") { widget = radioButton = ui->anticaptcha; type = 'r'; }
                    else if (key == "guro_captcha") { widget = radioButton = ui->gurocaptcha; type = 'r'; }
                    else if (key == "x_captcha") { widget = radioButton = ui->x_captcha; type = 'r'; }
                    else if (key == "reserved") { widget = radioButton = ui->reserved; type = 'r'; }

                    else if (key == "key_label") { widget = label = ui->keyLabel; type = 'l'; }
                    else if (key == "key") { widget = edit = ui->key; type = 'e'; }
                    else if (key == "server_key") { widget = checkBox = ui->serverKey; type = 'c'; }

                    else if (key == "wipe_chan") { widget = ui->wipechan; type = 'w'; }
                    else if (key == "blockquote") { widget = ui->blockquote; type = 'w'; }
                    else if (key == "back_banner") { widget = ui->blockquote; type = 'w'; }

                    else if (key == "post_set") { widget = ui->postSet; type = 'w'; }
                    else if (key == "post_set_header") { widget = label = ui->postSetHeader; type = 'l'; }

                    else if (key == "no_text") { widget = radioButton = ui->noText; type = 'r'; }
                    else if (key == "quoting") { widget = radioButton = ui->quoting; type = 'r'; }
                    else if (key == "copying") { widget = radioButton = ui->copying; type = 'r'; }
                    else if (key == "overload") { widget = radioButton = ui->overload; type = 'r'; }
                    else if (key == "pastes") { widget = radioButton = ui->pastes; type = 'r'; }
                    else if (key == "complain") { widget = radioButton = ui->complain; type = 'r'; }
                    else if (key == "random") { widget = radioButton = ui->random; type = 'r'; }

                    else if (key == "repeats_label") { widget = label = ui->repeatsLabel; type = 'l'; }
                    else if (key == "repeats") { widget = edit = ui->repeats; type = 'e'; }

                    else if (key == "trigger_set") { widget = ui->triggerSet; type = 'w'; }
                    else if (key == "trigger_mode_label") { widget = label = ui->triggerModeLabel; type = 'l'; }
                    else if (key == "chaining") { widget = radioButton = ui->chaining; type = 'r'; }
                    else if (key == "random_trigger") { widget = radioButton = ui->randTrigger; type = 'r'; }
                    else if (key == "shashlik") { widget = radioButton = ui->shashlik; type = 'r'; }
                    else if (key == "op_post_trigger") { widget = radioButton = ui->oppost; type = 'r'; }
                    else if (key == "no_trigger") { widget = radioButton = ui->notrigger; type = 'r'; }

                    else if (key == "complain_set") { widget = ui->complainSet; type = 'w'; }
                    else if (key == "complain_set_label") { widget = label = ui->complainSetLabel; type = 'l'; }
                    else if (key == "complain_board_label") { widget = label = ui->complainBoardLabel; type = 'l'; }
                    else if (key == "complain_board") { widget = ui->complainBoard; type = 'w'; }
                    else if (key == "links_count_label") { widget = label = ui->linksCountLabel; type = 'l'; }
                    else if (key == "links_count") { widget = spin = ui->linksCount; type = 's'; }
                    else if (key == "with_posts") { widget = checkBox = ui->withPosts; type = 'c'; }

                    else if (key == "line1") { widget = ui->line1; type = 'w'; }

                    else if (key == "chaos") { widget = checkBox = ui->chaos; type = 'r'; }
                    else if (key == "random_chaos") { widget = checkBox = ui->randChaos; type = 'r'; }
                    else if (key == "to_thread_label") { widget = label = ui->toThreadLabel; type = 'l'; }
                    else if (key == "to_thread") { widget = edit = ui->toThread; type = 'e'; }

                    else if (key == "line2") { widget = ui->line2; type = 'w'; }

                    else if (key == "sage") { widget = checkBox = ui->sage; type = 'c'; }
                    else if (key == "sage_set") { widget = ui->sageSet; type = 'w'; }
                    else if (key == "sage_always") { widget = radioButton = ui->sageAlways; type = 'r'; }
                    else if (key == "sage_from_posts") { widget = radioButton = ui->sageFromPosts; type = 'r'; }

                    else if (key == "media_set") { widget = ui->mediaSet; type = 'w'; }
                    else if (key == "media_set_header") { widget = label = ui->mediaSetHeader; type = 'l'; }

                    else if (key == "images") { widget = radioButton = ui->images; type = 'r'; }
                    else if (key == "images_count_label") { widget = label = ui->imagesCountLabel; type = 'l'; }
                    else if (key == "images_count") { widget = spin = ui->imagesCount; type = 's'; }
                    else if (key == "images_folder_label") { widget = label = ui->imagesFolderLabel; type = 'l'; }
                    else if (key == "images_folder") { widget = edit = ui->imagesFolder; type = 'e'; }
                    else if (key == "videos") { widget = radioButton = ui->videos; type = 'r'; }
                    else if (key == "videos_count_label") { widget = label = ui->videosCountLabel; type = 'l'; }
                    else if (key == "videos_count") { widget = spin = ui->videosCount; type = 's'; }
                    else if (key == "videos_folder_label") { widget = label = ui->videosFolderLabel; type = 'l'; }
                    else if (key == "videos_folder") { widget = edit = ui->videosFolder; type = 'e'; }
                    else if (key == "medias_from_posts") { widget = radioButton = ui->medias; type = 'r'; }
                    else if (key == "no_media") { widget = radioButton = ui->noMedia; type = 'r'; }

                    else if (key == "shackal_set") { widget = ui->shackalSet; type = 'w'; }
                    else if (key == "shackal_degree_label") { widget = label = ui->shakalPowerLabel; type = 'l'; }
                    else if (key == "shackal_degree") { widget = ui->shakalPower; type = 'w'; }
                    else if (key == "colorization") { widget = checkBox = ui->shakalColor; type = 'c'; }
                    else if (key == "affine") { widget = checkBox = ui->shakalAffine; type = 'c'; }
                    else if (key == "to_PNG") { widget = checkBox = ui->toPNG; type = 'c'; }
                    else if (key == "start_button") { widget = button = ui->button; type = 'b'; }

                    else type = 0;

                    if (type != 0) {
                        x = data.substr(0, data.find(' '));
                        data = data.substr(data.find(' ')+1, data.length()-1);
                        y = data.substr(0, data.find(' '));
                        data = data.substr(data.find(' ')+1, data.length()-1);
                        width = data.substr(0, data.find(' '));
                        data = data.substr(data.find(' ')+1, data.length()-1);
                        height = data.substr(0, data.find(' '));
                        widget->setGeometry(atoi(x.c_str()), atoi(y.c_str()), atoi(width.c_str()), atoi(height.c_str()));

                        if (data.find(' ') != -1) {
                            text = data.substr(data.find(' ')+1, data.length()-1);
                            if (type == 'b') button->setText(text.c_str());
                            else if (type == 'l') label->setText(text.c_str());
                            else if (type == 'r') radioButton->setText(text.c_str());
                            else if (type == 'e') edit->setPlaceholderText(text.c_str());
                            else if (type == 'c') checkBox->setText(text.c_str());
                            else if (type == 's') spin->setValue(atoi(text.c_str()));
                        }
                    }
                }
            }
        }
    }
}




void GUI::debug (const char &mode) {
    setup.set_logMode(mode);
}

void GUI::updateData () {
    std::string datum, key, value;
    std::ifstream config(".config");
    if (config.is_open()) {
        while(!config.eof()) {
            getline(config, datum);
            key = datum.substr(0, datum.find(' '));
            value = datum.substr(datum.find(' ')+1, datum.length()-1);
            if (key == "total_posts") {
                ui->totalPosts->display(atoi(value.c_str()));
                totalPosts = value;
            } else if (key == "posts")
                postsCount = value;
            else if (key == "username") {
                ui->username->setText(value.c_str());
                username = value;
            }
        }

    } else {
        ui->totalPosts->display(0);
        ui->username->setText("Сэмпай");
        totalPosts = "0";
        username = "Сэмпай";

        updateConfig();
    }

    ui->totalPosts->repaint();
}

void GUI::updateConfig () {
    std::ofstream config(".config");
    config << "total_posts " << totalPosts << std::endl;
    config << "username " << username << std::endl;
}





void GUI::on_button_clicked () {
    if (started == false) {
        ui->wipechan->call("start", {username});
        //if (start()) started = true;
        if (start()) {
            updateData();
            ui->wipechan->call("finish", {postsCount});
        }
    } else stop();
}

bool GUI::start () {
    setup.clear();
    setup.set_username(username);

    if (ui->mainMode->isChecked()) {
        setup.set_board(ui->board->currentText().toStdString());
        if (ui->thread->text().toStdString().empty())
            setup.set_thread(ui->thread->placeholderText().toStdString());
        else
            setup.set_thread(ui->thread->text().toStdString());
        if (ui->potocks->text().toStdString().empty())
            setup.set_potocksCount(ui->potocks->placeholderText().toStdString());
        else
            setup.set_potocksCount(ui->potocks->text().toStdString());
        setup.set_shrapnelCharge("0");

    } else if (ui->shrapnelMode->isChecked()) {
        setup.set_thread("1");
        setup.set_board(ui->shrapnelBoard->currentText().toStdString());
        if (ui->threads->text().toStdString().empty())
            setup.set_shrapnelCharge(ui->threads->placeholderText().toStdString());
        else
            setup.set_shrapnelCharge(ui->threads->text().toStdString());
        if (ui->minPosts->text().toStdString().empty())
            setup.set_minPostsCount(ui->minPosts->placeholderText().toStdString());
        else
            setup.set_minPostsCount(ui->minPosts->text().toStdString());
        if (ui->shrapnelPotocks->text().toStdString().empty())
            setup.set_potocksCount(ui->shrapnelPotocks->placeholderText().toStdString());
        else
            setup.set_potocksCount(ui->shrapnelPotocks->text().toStdString());

    }

    if (ui->anticaptcha->isChecked())
        setup.set_solver("2");
    else if (ui->x_captcha->isChecked())
        setup.set_solver("0");
    else if (ui->gurocaptcha->isChecked())
        setup.set_solver("1");

    if (ui->serverKey->isChecked())
        setup.set_key("");
    else if (ui->key->text() == "")
        setup.set_key(ui->key->placeholderText().toStdString());
    else
        setup.set_key(ui->key->text().toStdString());

    if (ui->repeats->text() == "")
        setup.set_proxyRepeatsCount(ui->repeats->placeholderText().toStdString());
    else
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
    else if (ui->complain->isChecked()) {
        setup.set_mode("1");
        setup.set_triggerForm("0");
    } else if (ui->random->isChecked()) {
        setup.set_mode("0");
        setup.set_triggerForm("0");
    }

    if (!ui->random->isChecked() && !ui->complain->isChecked()) {
        if (ui->chaining->isChecked()) setup.set_triggerForm("1");
        else if (ui->randTrigger->isChecked()) setup.set_triggerForm("2");
        else if (ui->shashlik->isChecked()) setup.set_triggerForm("3");
        else if (ui->oppost->isChecked()) setup.set_triggerForm("4");
        else setup.set_triggerForm("0");

    } else if (ui->complain->isChecked()) {
        setup.set_complain_board(ui->complainBoard->currentText().toStdString());
        setup.set_complains_count(ui->linksCount->value());
        setup.set_complains_with_posts(ui->withPosts->isChecked());
    }

    if (ui->chaos->isChecked()) {
        if (ui->randChaos->isChecked())
            setup.set_chaos("0");
        else if (ui->toThread->text() == "")
            setup.set_chaos(ui->toThread->placeholderText().toStdString());
        else
            setup.set_chaos(ui->toThread->text().toStdString());
    }

    if (ui->images->isChecked()) {
        setup.set_mediaKind('1');
        setup.set_mediasCount(ui->imagesCount->text().toStdString());
        if (ui->imagesFolder->text() == "")
            setup.set_mediaGroup(ui->imagesFolder->placeholderText().toStdString());
        else
            setup.set_mediaGroup(ui->imagesFolder->text().toStdString());
    } else if (ui->videos->isChecked()) {
        setup.set_mediaKind('2');
        setup.set_mediasCount(ui->videosCount->text().toStdString());
        if (ui->videosFolder->text() == "")
            setup.set_mediaGroup(ui->videosFolder->placeholderText().toStdString());
        else
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
        ui->wipechan->call("error", response);
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
    updateConfig();
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
    ui->complainSet->hide();
    ui->triggerSet->show();
}

void GUI::on_quoting_clicked () {
    ui->complainSet->hide();
    ui->triggerSet->show();
}

void GUI::on_copying_clicked () {
    ui->complainSet->hide();
    ui->triggerSet->show();
}

void GUI::on_overload_clicked () {
    ui->complainSet->hide();
    ui->triggerSet->show();
}

void GUI::on_pastes_clicked () {
    ui->complainSet->hide();
    ui->triggerSet->show();
}

void GUI::on_complain_clicked () {
    ui->triggerSet->hide();
    ui->complainSet->show();
}

void GUI::on_random_clicked () {
    ui->complainSet->hide();
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
    ui->shackalSet->show();
}

void GUI::on_videos_clicked () {
    ui->imagesCount->setDisabled(true);
    ui->videosCount->setDisabled(false);
    ui->imagesFolder->setDisabled(true);
    ui->videosFolder->setDisabled(false);
    ui->shackalSet->hide();
}

void GUI::on_medias_clicked () {
    ui->imagesCount->setDisabled(true);
    ui->videosCount->setDisabled(true);
    ui->imagesFolder->setDisabled(true);
    ui->videosFolder->setDisabled(true);
    ui->shackalSet->show();
}

void GUI::on_noMedia_clicked () {
    ui->imagesCount->setDisabled(true);
    ui->videosCount->setDisabled(true);
    ui->imagesFolder->setDisabled(true);
    ui->videosFolder->setDisabled(true);
    ui->shackalSet->hide();
}





void GUI::on_openButton_clicked () {
    std::string fileName = fileDialog->getOpenFileName().toStdString();
    std::ifstream config(fileName);
    std::string value;

    getline(config, value);
    if (value == "main") {
        ui->shrapnelSet->hide();
        ui->mainModeSet->show();
        ui->mainMode->setChecked(true);
        ui->board->setDisabled(false);
        ui->thread->setDisabled(false);
        ui->potocks->setDisabled(false);
        ui->shrapnelBoard->setDisabled(true);
        ui->threads->setDisabled(true);
        ui->minPosts->setDisabled(true);
        ui->shrapnelPotocks->setDisabled(true);
    } else if (value == "shrapnel") {
        ui->mainModeSet->hide();
        ui->shrapnelSet->show();
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
        ui->complainSet->hide();
        ui->triggerSet->show();
    } else if (value == "quoting") {
        ui->quoting->setChecked(true);
        ui->complainSet->hide();
        ui->triggerSet->show();
    } else if (value == "copying") {
        ui->copying->setChecked(true);
        ui->complainSet->hide();
        ui->triggerSet->show();
    } else if (value == "overload") {
        ui->overload->setChecked(true);
        ui->complainSet->hide();
        ui->triggerSet->show();
    } else if (value == "pastes") {
        ui->pastes->setChecked(true);
        ui->complainSet->hide();
        ui->triggerSet->show();
    } else if (value == "complain") {
        ui->complain->setChecked(true);
        ui->triggerSet->hide();
        ui->complainSet->show();
    } else if (value == "random") {
        ui->random->setChecked(true);
        ui->complainSet->hide();
        ui->triggerSet->hide();
    } else
        ui->complainSet->hide();
        ui->triggerSet->hide();

    getline(config, value);
    if (value == "chaining") ui->chaining->setChecked(true);
    else if (value == "random") ui->randTrigger->setChecked(true);
    else if (value == "shashlik") ui->shashlik->setChecked(true);
    else if (value == "op post") ui->oppost->setChecked(true);
    else if (value == "no trigger") ui->notrigger->setChecked(true);

    getline(config, value);
    ui->complainBoard->setCurrentText(value.c_str());
    getline(config, value);
    ui->linksCount->setValue(atoi(value.c_str()));
    getline(config, value);
    if (value == "with posts") ui->withPosts->setChecked(true);
    else ui->withPosts->setChecked(false);

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
        ui->shackalSet->show();
    } else if (value == "videos") {
        ui->videos->setChecked(true);
        ui->imagesCount->setDisabled(true);
        ui->videosCount->setDisabled(false);
        ui->imagesFolder->setDisabled(true);
        ui->videosFolder->setDisabled(false);
        ui->shackalSet->hide();
    } else if (value == "medias") {
        ui->medias->setChecked(true);
        ui->imagesCount->setDisabled(true);
        ui->videosCount->setDisabled(true);
        ui->imagesFolder->setDisabled(true);
        ui->videosFolder->setDisabled(true);
        ui->shackalSet->show();
    } else if (value == "nothing") {
        ui->noMedia->setChecked(true);
        ui->imagesCount->setDisabled(true);
        ui->videosCount->setDisabled(false);
        ui->imagesFolder->setDisabled(true);
        ui->videosFolder->setDisabled(true);
        ui->shackalSet->hide();
    }
    getline(config, value);
    ui->imagesCount->setValue(atoi(value.c_str()));
    getline(config, value);
    ui->videosCount->setValue(atoi(value.c_str()));
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

    config << ui->complainBoard->currentText().toStdString() << std::endl;
    config << to_string(ui->linksCount->value()) << std::endl;
    if (ui->withPosts->isChecked()) config << "with posts";
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
    ui->shrapnelSet->hide();
    ui->mainModeSet->show();
    ui->board->setDisabled(false);
    ui->thread->setDisabled(false);
    ui->potocks->setDisabled(false);
    ui->shrapnelBoard->setDisabled(true);
    ui->threads->setDisabled(true);
    ui->minPosts->setDisabled(true);
    ui->shrapnelPotocks->setDisabled(true);
}

void GUI::on_shrapnelMode_clicked () {
    ui->mainModeSet->hide();
    ui->shrapnelSet->show();
    ui->board->setDisabled(true);
    ui->thread->setDisabled(true);
    ui->potocks->setDisabled(true);
    ui->shrapnelBoard->setDisabled(false);
    ui->threads->setDisabled(false);
    ui->minPosts->setDisabled(false);
    ui->shrapnelPotocks->setDisabled(false);
}




void GUI::on_username_editingFinished () {
    username = ui->username->text().toStdString();
}





void GUI::on_helpButton_clicked () {
    if (ui->wipechan->is_called()) ui->wipechan->uncall();
    else ui->wipechan->call("hello", {username});
}
