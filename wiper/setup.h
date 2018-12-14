#ifndef SETUP_H
#define SETUP_H
#include <iostream>
#include <vector>
using namespace std;

class Setup {
private:
    string board;
    string thread;
    string potocksCount;
    char logMode;
    string solver, key;
    string proxyRepeatsCount;
    string mode;
    string minBan, maxBan;
    string triggerForm;
    string shrapnelCharge, minPostsCount;
    char mediaKind;
    string mediaGroup, mediasCount;
    char sageMode;
    vector<string> shrapnelThreads;

    bool hasBoard, hasThread, hasPotocksCount, hasLogMode, hasSolver, hasKey, hasProxyRepeatsCount, hasMode, hasMinBan, hasMaxBan, \
        hasTriggerForm, hasShrapnelCharge, hasMinPostsCount, hasMediaKind, hasMediaGroup, hasMediasCount, hasSageMode;

    static const string DIGITS;
    bool is_digit(const char &c);
    bool is_num(const string &str);
    bool is_pos_num(const string &str);
    bool is_zero(const string &str);

    string get();
public:
    Setup();
    Setup(const int &argsCount, const char * args[]);
    ~Setup();

    void set_board(const string &board="b");
    void set_thread(const string &thread="0");
    void set_potocksCount(const string &potocksCount="0");
    void set_logMode(const char &logMode);
    void set_solver(const string &solver="0");
    void set_key(const string &key="");
    void set_proxyRepeatsCount(const string &proxyRepeatsCount="10");
    void set_mode(const string &mode="0");
    void set_minBan(const string &minBan);
    void set_maxBan(const string &maxBan);
    void set_triggerForm(const string &triggerForm="0");
    void set_shrapnelCharge(const string &shrapnelCharge);
    void set_minPostsCount(const string &minPostsCount);
    void set_mediaKind(const char &mediaKing='1');
    void set_mediaGroup(const string &mediaGroup);
    void set_mediasCount(const string &mediasCount="1");
    void set_sageMode(const char &sageMode='0');
    void set_shrapnelThreads(const vector<string> &shrapnelThreads);

    Setup parse(const int &argsCount, const char * args[]);
    unsigned int validate();
    bool complete();
    string run();
};

#endif // SETUP_H
