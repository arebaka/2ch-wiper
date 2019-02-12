#include "setup.h"
#include "gui.h"
#include "banner.h"
#include <QApplication>
#include <QSplashScreen>
#include <QMessageBox>

int main (int argc, char * argv[]) {
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap(QDir::currentPath()+"/gui/splash.png"));
    splash.show();
    GUI w;

    if (argc == 2) {
        if (argv[1] == "-d" || argv[1] == "--debug") w.debug(2);
        else if (argv[1] == "-l" || argv[2] == "--log") w.debug(1);
    }

    w.show();
    Banner banner;
    // banner.show();
    splash.finish(&w);
    QMessageBox::information(NULL, "АХТУНГ", "Данная программа создана в ознакомительных целях, её предназначением не является оскорбление чьих-либо чувств, а создатели не несут ответственности за действия, совершаемые с её помощью и не поддерживают никаких противозаконных намерений.");

    return a.exec();
}
