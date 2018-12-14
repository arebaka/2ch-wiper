#include "setup.h"

const string Setup::DIGITS = "0123456789";

Setup::Setup ()
    : hasBoard(false) , hasThread(false) , hasPotocksCount(false) , hasLogMode(false) , hasSolver(false) , hasKey(false) , \
      hasProxyRepeatsCount(false) , hasMode(false) , hasMinBan(false) , hasMaxBan(false) , hasTriggerForm(false) , \
      hasShrapnelCharge(false) , hasMinPostsCount(false) , hasMediaKind(false) , hasMediaGroup(false) , \
      hasMediasCount(false) , hasSageMode(false)
{}

Setup::Setup (const int &argsCount, const char * args[]) {
    *this = parse(argsCount, args);
}

Setup::~Setup () {}



bool Setup::is_digit (const char &c) {
    return DIGITS.find(c) != string::npos;
}

bool Setup::is_num (const string &str) {
    return !str.empty() && \
            ( (str.size() == 1 && is_digit(str[0])) || \
            ((str[0] == '-' || is_digit(str[0])) && is_pos_num(str.substr(1))) );
}

bool Setup::is_pos_num (const string &str) {
    if (str.empty()) return false;
    for (unsigned int pos(0); pos < str.length(); pos++)
        if (!is_digit(str[pos])) return false;
    return true;
}

bool Setup::is_zero (const string &str) {
    return str.size() == 1 && str[0] == '0';
}



void Setup::set_board (const string &board) {
    this->board = board;
    hasBoard = true;
}
void Setup::set_thread (const string &thread) {
    if (is_pos_num(thread)) {
        this->thread = thread;
        hasThread = true;
    } else
        hasThread = false;
}
void Setup::set_potocksCount (const string &potocksCount) {
    if (is_pos_num(potocksCount)) {
        this->potocksCount = potocksCount;
        hasPotocksCount = true;
    } else
        hasPotocksCount = false;
}
void Setup::set_logMode (const char &logMode) {
    if (DIGITS.find(logMode) != string::npos) {
        this->logMode = logMode;
        hasLogMode = true;
    } else
        hasLogMode = false;
}
void Setup::set_solver (const string &solver) {
    if (is_pos_num(solver)) {
        this->solver = solver;
        hasSolver = true;
    } else
        hasSolver = false;
}
void Setup::set_key (const string &key) {
    if (key.empty() || key.length() == 32) {
        this->key = key;
        hasKey = true;
    } else
        hasKey = false;
}
void Setup::set_proxyRepeatsCount (const string &proxyRepeatsCount) {
    if (is_pos_num(proxyRepeatsCount) && !is_zero(proxyRepeatsCount)) {
        this->proxyRepeatsCount = proxyRepeatsCount;
        hasProxyRepeatsCount = true;
    } else
        hasProxyRepeatsCount = false;
}
void Setup::set_mode (const string &mode) {
    if (is_pos_num(mode)) {
        this->mode = mode;
        hasMode = true;
    } else
        hasMode = false;
}
void Setup::set_minBan (const string &minBan) {
    if (is_pos_num(minBan)) {
        this->minBan = minBan;
        hasMinBan = true;
    } else
        hasMinBan = false;
}
void Setup::set_maxBan (const string &maxBan) {
    if (is_pos_num(maxBan)) {
        this->maxBan = maxBan;
        hasMaxBan = true;
    } else
        hasMaxBan = false;
}
void Setup::set_triggerForm (const string &triggerForm) {
    if (is_pos_num(triggerForm)) {
        this->triggerForm = triggerForm;
        hasTriggerForm = true;
    } else
        hasTriggerForm = false;
}
void Setup::set_shrapnelCharge (const string &shrapnelCharge) {
    if (is_pos_num(shrapnelCharge)) {
        this->shrapnelCharge = shrapnelCharge;
        hasShrapnelCharge = true;
    } else
        hasShrapnelCharge = false;
}
void Setup::set_minPostsCount (const string &minPostsCount) {
    if (is_pos_num(minPostsCount)) {
        this->minPostsCount = minPostsCount;
        hasMinPostsCount = true;
    } else
        hasMinPostsCount = false;
}
void Setup::set_mediaKind (const char &mediaKing) {
    if (DIGITS.find(mediaKing) != string::npos) {
        this->mediaKind = mediaKind;
        hasMediaKind = true;
    } else
        hasMediaKind = false;
}
void Setup::set_mediaGroup (const string &mediaGroup) {
    this->mediaGroup = mediaGroup;
    hasMediaGroup = true;
}
void Setup::set_mediasCount (const string &mediasCount) {
    if (is_pos_num(mediasCount)) {
        this->mediasCount = mediasCount;
        hasMediasCount = true;
    }
}
void Setup::set_sageMode (const char &sageMode) {
    if (DIGITS.find(sageMode) != string::npos) {
        this->sageMode = sageMode;
        hasSageMode = true;
    } else
        hasSageMode = false;
}
void Setup::set_shrapnelThreads (const vector<string> &shrapnelThreads) {
    if (!this->shrapnelThreads.empty()) this->shrapnelThreads.clear();
    this->shrapnelThreads.reserve(shrapnelThreads.size());
    this->shrapnelThreads = shrapnelThreads;
}



Setup Setup::parse (const int &argsCount, const char * args[]) {}

unsigned int Setup::validate () {}

bool Setup::complete () {}

string Setup::run () {
    if (validate()) {
        string command(get());
        system(command.c_str());
        return command;
    } else {
        cerr << "Пытаюсь починить..." << endl;
        complete();
        if (validate()) {
            string command(get());
            system(command.c_str());
            return command;
        }
    }
    return "ERROR";
}

string Setup::get () {
    string command(board + " " + thread + " " + potocksCount);
    command += logMode;

    command += (" " + solver + " ");
    if (!hasKey || key == "") command += "0 ";
    else command += (key + " ");
    command += (proxyRepeatsCount + " " + mode + " ");

    if (!hasMinBan) command += "-1 ";
    else command += (minBan + " ");
    if (!hasMaxBan) command += "-1 ";
    else command += (maxBan + " ");

    if (!hasTriggerForm) command += "-1 ";
    else command += (triggerForm + " ");

    if (!hasShrapnelCharge) command += "0 ";
    else command += (shrapnelCharge + " ");
    if (!hasMinPostsCount) command += "-1 ";
    else command += (minPostsCount + " ");

    if (!hasMediaKind) command += "0";
    else command += mediaKind;
    command += " ";
    if (!hasMediaGroup) command += "0 ";
    else command += (mediaGroup + " ");
    if (!hasMediasCount) command += "-1 ";
    else command += (mediasCount + " ");

    command += sageMode;

    if (hasShrapnelCharge && !hasMinPostsCount)
        for (unsigned int i(0); i < shrapnelThreads.size(); i++)
            command += (" " + shrapnelThreads[i]);

    return command;
}
