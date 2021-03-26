#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;
    QTranslator guiTranslator;

    QStringList languages;
//    languages << tr("Chinese") << tr("English") << tr("French");
    languages << "Chinese" << "English" << "French";

//    QString lang = QInputDialog::getItem(nullptr, tr("Select language"), tr("Language"), languages);
    QString lang = QInputDialog::getItem(nullptr, "Select language", "Language", languages);

    if (lang == "Chinese")
    {
        qDebug() << "Loading Translation_zh_CN.qm";
        t.load(":/resources/languages/Translation_zh_CN.qm");
        guiTranslator.load("/usr/share/qt5/translations/qt_zh_CN.qm");
    }
    else if (lang == "French")
    {
        t.load(":/resources/languages/Translation_fr_FR.qm");
        guiTranslator.load("/usr/share/qt5/translations/qtbase_fr.qm");
    }

    if (lang != "English")
    {
        a.installTranslator(&t);
        a.installTranslator(&guiTranslator);
    }

    MainWindow w;
    w.show();
    return a.exec();
}
