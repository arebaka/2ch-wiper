#include "wipechan.h"
#include <stdlib.h>

Wipechan::Wipechan () : QFrame() , called(false) , wasCalled(false) {
    quote = new std::string;
    blockquote = new QPlainTextEdit;
    set_quote_bank();
}

Wipechan::Wipechan (QWidget * centralWidget) : QFrame(centralWidget) , called(false) , wasCalled(false) {
    quote = new std::string;
    blockquote = new QPlainTextEdit;
    set_quote_bank();
}

Wipechan::Wipechan (QWidget * centralWidget, QPlainTextEdit * blockquote) : QFrame(centralWidget) , called(false) , wasCalled(false) {
    quote = new std::string;
    this->blockquote = blockquote;
    set_quote_bank();
}

void Wipechan::set_blockquote (QPlainTextEdit * blockquote) {
    this->blockquote = blockquote;
    blockquote->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


void Wipechan::set_quote (const std::string &quote, std::vector<std::string> * bank) {
    std::string row;
    std::ifstream file(QDir::currentPath().toStdString()+"/gui/Wipe-chan/quote-bank/"+quote);
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, row);
            bank->push_back(row);
        }
        bank->pop_back();
        file.close();
    }
}

void Wipechan::set_quote_bank () {
    set_quote("meet", &quoteBank.meet);
    set_quote("hello/bad", &quoteBank.hello[0]);
    set_quote("hello/neutral", &quoteBank.hello[1]);
    set_quote("hello/well", &quoteBank.hello[2]);
    set_quote("start/bad", &quoteBank.start[0]);
    set_quote("start/neutral", &quoteBank.start[1]);
    set_quote("start/well", &quoteBank.start[2]);
    set_quote("finish/bad", &quoteBank.finish[0]);
    set_quote("finish/neutral", &quoteBank.finish[1]);
    set_quote("finish/well", &quoteBank.finish[2]);
    set_quote("error/bad", &quoteBank.error[0]);
    set_quote("error/neutral", &quoteBank.error[1]);
    set_quote("error/well", &quoteBank.error[2]);
    set_quote("banned", &quoteBank.banned);
    set_quote("forbidden", &quoteBank.forbidden);
}



bool Wipechan::is_called () {
    return called;
}

bool Wipechan::was_called () {
    return wasCalled;
}

void Wipechan::call (const std::string &request, const std::vector<std::string> &params) {
    if (request == "hello") hello(params[0]);
    else if (request == "start") start(params[0]);
    else if (request == "error") error(params);
    else if (request == "finish") finish(params[0]);

    blockquote->setPlainText(quote->c_str());
    set_height();
}

void Wipechan::uncall () {
    hide();
    called = false;
}

void Wipechan::set_height () {
    unsigned char rowsCount = blockquote->document()->documentLayout()->documentSize().height();
    if (rowsCount == 0) rowsCount = 1;
    blockquote->resize(blockquote->size().width(), rowsCount * 2 * blockquote->font().pixelSize() + 10);
    if (blockquote->height() > size().height()-20) blockquote->resize(blockquote->size().width(), size().height()-20);
    blockquote->moveCursor(QTextCursor::Start);
    blockquote->ensureCursorVisible();
}



void Wipechan::add_quote_part(const std::vector<std::string> &bank, const std::vector<std::string> &params) {
    rand = random() % bank.size();
    unsigned int tabPos(bank[rand].find("\t"));
    quote->append(bank[rand].substr(0, tabPos));
    if (tabPos != -1) {
        quote->append(params[0]);
        quote->append(bank[rand].substr(tabPos+1, bank[rand].length()));
    }
}

void Wipechan::hello (const std::string &username) {
    quote->clear();
    if (!wasCalled) {
        add_quote_part(quoteBank.meet, {username});
        wasCalled = true;

    } else
        add_quote_part(quoteBank.hello[1], {username});

    show();
    called = true;
}

void Wipechan::start (const std::string &username) {
    quote->clear();
    add_quote_part(quoteBank.start[1], {username});
    repaint();
}

void Wipechan::error (const std::vector<std::string> &errors) {
    blockquote->setStyleSheet("background: white;");
    quote->clear();
    rand = random() % quoteBank.error[1].size();
    quote->append(quoteBank.error[1][rand] + "\n");
    for (unsigned int i(0); i < errors.size(); i++)
        quote->append(errors[i] + "\n");

    show();

}

void Wipechan::finish (const std::string &postsCount) {
    quote->clear();
    if (atoi(postsCount.c_str()) > 200)
        add_quote_part(quoteBank.finish[2], {postsCount});
    else if (atoi(postsCount.c_str()) < 20)
        add_quote_part(quoteBank.finish[0], {postsCount});
    else
        add_quote_part(quoteBank.finish[1], {postsCount});
}
