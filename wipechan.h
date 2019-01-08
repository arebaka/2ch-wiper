#ifndef WIPECHAN_H
#define WIPECHAN_H

#include <QObject>
#include <QWidget>
#include <QPlainTextEdit>
#include <QDir>
#include <iostream>
#include <fstream>

class Wipechan : public QFrame {
private:
    struct {
        std::vector<std::string> salute;
        std::vector<std::string> comeback;
        std::vector<std::string> start;
        std::vector<std::string> averageFinish;
        std::vector<std::string> wellFinish;
        std::vector<std::string> badFinish;
        std::vector<std::string> error;
        std::vector<std::string> banned;
        std::vector<std::string> forbidden;
    } quoteBank;

    QPlainTextEdit * blockquote;
    std::string * quote;

    bool called;
    bool wasCalled;
    unsigned int rand;

    void set_height();
    void set_quote(const std::string &quote, std::vector<std::string> * bank);
    void set_quote_bank();
    void add_quote_part(const std::vector<std::string> &bank, const std::vector<std::string> &params);

    void hello(const std::string &username);
    void start(const std::string &username);
    void error(const std::vector<std::string> &errors);
    void finish(const std::string &postsCount);


public:
    Wipechan();
    Wipechan(QWidget * centralWidget);
    Wipechan(QWidget * centralWidget, QPlainTextEdit * blockquote);
    void set_blockquote(QPlainTextEdit * blockquote);

    void call(const std::string &request, const std::vector<std::string> &params={});
    void uncall();
    bool is_called();
    bool was_called();

};

#endif // WIPECHAN_H
