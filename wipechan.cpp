#include "wipechan.h"

Wipechan::Wipechan () : QFrame() , called(false) , wasCalled(false) {
    quote = new std::string;
    blockquote = new QLabel;
    set_quote_bank();
}

Wipechan::Wipechan (QWidget * centralWidget) : QFrame(centralWidget) , called(false) , wasCalled(false) {
    quote = new std::string;
    blockquote = new QLabel;
    set_quote_bank();
}

Wipechan::Wipechan (QWidget * centralWidget, QLabel * blockquote) : QFrame(centralWidget) , called(false) , wasCalled(false) {
    quote = new std::string;
    this->blockquote = blockquote;
    set_quote_bank();
}

void Wipechan::set_blockquote (QLabel * blockquote) {
    this->blockquote = blockquote;
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
    set_quote("salute", &quoteBank.salute);
    set_quote("comeback", &quoteBank.comeback);
    set_quote("start", &quoteBank.start);
    set_quote("finish", &quoteBank.finish);
    set_quote("error", &quoteBank.error);
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

    set_height();
    blockquote->setText(quote->c_str());
}

void Wipechan::uncall () {
    hide();
    called = false;
}

void Wipechan::set_height () {
    unsigned char rowsCount = quote->length() * blockquote->font().pixelSize() * 2/3 / (blockquote->size().width() - 10);
    if (quote->length() * blockquote->font().pixelSize() * 2/3 % (blockquote->size().width() - 10) != 0) rowsCount++;
    if (rowsCount == 1) rowsCount++;
    blockquote->resize(blockquote->size().width(), rowsCount * blockquote->font().pixelSize() + 10);
}




void Wipechan::hello (const std::string &username) {
    setStyleSheet("background: url(gui/Wipe-chan/images/patch.png);");
    blockquote->setStyleSheet("background: white;");
    quote->clear();
    if (!wasCalled) {
        rand = random() % quoteBank.salute.size();
        quote->append(quoteBank.salute[rand].substr(0, quoteBank.salute[rand].find("\t")));
        quote->append(username);
        quote->append(quoteBank.salute[rand].substr(quoteBank.salute[rand].find("\t")+1, quoteBank.salute[rand].length()));
        wasCalled = true;

    } else {
        rand = random() % quoteBank.comeback.size();
        quote->append(quoteBank.comeback[rand].substr(0, quoteBank.comeback[rand].find("\t")));
        quote->append(username);
        quote->append(quoteBank.comeback[rand].substr(quoteBank.comeback[rand].find("\t")+1, quoteBank.comeback[rand].length()));
    }

    show();
    called = true;
}

void Wipechan::start (const std::string &username) {
    quote->clear();
    rand = random() % quoteBank.start.size();
    quote->append(quoteBank.start[rand].substr(0, quoteBank.start[rand].find("\t")));
    quote->append(username);
    quote->append(quoteBank.start[rand].substr(quoteBank.start[rand].find("\t")+1, quoteBank.start[rand].length()));
}

void Wipechan::error (const std::vector<std::string> &errors) {
    setStyleSheet("background: url(gui/Wipe-chan/images/patch.png);");
    blockquote->setStyleSheet("background: white;");
    quote->clear();
    rand = random() % quoteBank.error.size();
    quote->append(quoteBank.error[rand] + "\n");
    for (unsigned int i(0); i < errors.size(); i++)
        quote->append(errors[i] + "\n");

    show();
}

void Wipechan::finish (const std::string &postsCount) {
    quote->clear();
    rand = random() % quoteBank.finish.size();
    quote->append(quoteBank.finish[rand].substr(0, quoteBank.finish[rand].find("\t")));
    quote->append(postsCount);
    quote->append(quoteBank.finish[rand].substr(quoteBank.finish[rand].find("\t")+1, quoteBank.finish[rand].length()));
}
