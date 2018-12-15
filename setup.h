#ifndef SETUP_H
#define SETUP_H
#include <iostream>
#include <vector>
using namespace std;

class Setup {
private:
    string board;  // доска
    string thread;  // тред
    string potocksCount;  // число потоков
    char logMode;  // режим логов
    string solver, key;  // номер решателя и ключ
    string proxyRepeatsCount;  // число повторов прокси
    string mode;  // режим вайпалки
    string minBan, maxBan;  // наименьший и наибольший номера банов
    string triggerForm;  // режим триггера
    string shrapnelCharge, minPostsCount;  // число тредов для шрапнели
    char mediaKind;  // тип прикреплений
    string mediaGroup, mediasCount;  // подкаталог прикреплений и их число на пост
    char sageMode;  // режим сажи
    vector<string> shrapnelThreads;  // треды для шрапнели при ручном указании

    bool hasBoard, hasThread, hasPotocksCount, hasLogMode, hasSolver, hasKey, hasProxyRepeatsCount, hasMode, hasMinBan, hasMaxBan, \
        hasTriggerForm, hasShrapnelCharge, hasMinPostsCount, hasMediaKind, hasMediaGroup, hasMediasCount, hasSageMode;

    static const string DIGITS;
    bool is_digit(const char &c);
    bool is_num(const string &str);
    bool is_pos_num(const string &str);
    bool is_zero(const string &str);

    string comline();

public:
    Setup();
    Setup(const int &argsCount, const char * args[]);
    ~Setup();

    void set_board(const string &board="b");
    void set_thread(const string &thread="0");
    void set_potocksCount(const string &potocksCount="0");
    void set_logMode(const char &logMode='0');
    void set_solver(const string &solver="0");
    void set_key(const string &key);
    void set_proxyRepeatsCount(const string &proxyRepeatsCount="10");
    void set_mode(const string &mode);
    void set_minBan(const string &minBan);
    void set_maxBan(const string &maxBan);
    void set_triggerForm(const string &triggerForm="0");
    void set_shrapnelCharge(const string &shrapnelCharge);
    void set_minPostsCount(const string &minPostsCount="0");
    void set_mediaKind(const char &mediaKind);
    void set_mediaGroup(const string &mediaGroup="");
    void set_mediasCount(const string &mediasCount="1");
    void set_sageMode(const char &sageMode='0');
    void set_shrapnelThreads(const vector<string> &shrapnelThreads);

    void clear();
    Setup parse(const int &argsCount, const char * args[]);
    vector<string> validate();
    unsigned char complete();
    vector<string> start();
};

#endif // SETUP_H