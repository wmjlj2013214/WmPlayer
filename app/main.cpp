﻿#include <QApplication>
#include <QSplashScreen>
#include <QMainWindow>
#include <QThread>
#include <QLabel>
#include <QMovie>

const char ccAppName[] = "WmPlayer";

static void setHighDpiEnvironmentVariable()
{
    static const char ENV_VAR_QT_DEVICE_PIXEL_RATIO[] = "QT_DEVICE_PIXEL_RATIO";
    if (!qEnvironmentVariableIsSet(ENV_VAR_QT_DEVICE_PIXEL_RATIO) // legacy in 5.6, but still functional
            && !qEnvironmentVariableIsSet("QT_AUTO_SCREEN_SCALE_FACTOR")
            && !qEnvironmentVariableIsSet("QT_SCALE_FACTOR")
            && !qEnvironmentVariableIsSet("QT_SCREEN_SCALE_FACTORS"))
    {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
}

int main(int argc, char **argv)
{
    setHighDpiEnvironmentVariable();

    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_UseHighDpiPixmaps);

    QSplashScreen splash(QPixmap(":/app/wmplayer1.png"));
    splash.show();
    app.processEvents();

    QMainWindow mw;
    mw.show();

    splash.finish(&mw);

    return app.exec();
}
