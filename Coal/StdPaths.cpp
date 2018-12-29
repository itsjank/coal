
#include "StdPaths.h"
#include "AppConfig.h"
#include <QStandardPaths>
#include <QFileInfo>
#include <QDir>
#include <QCoreApplication>
using namespace coal;

namespace coal {

QString GetVst32Directory() {
    QString envPath(qgetenv("COAL_VST32_PATH"));
    if (!envPath.isEmpty()) { return envPath;
    } else {
        QString configVst32Path = eAppConfig.vst32Path;
        if (QDir(configVst32Path).exists()) { return configVst32Path;
        } else {
            // TODO
            return envPath;
        }
    }
    return envPath; // never reached
}

QString GetVst64Directory() {
    // TODO: check platform, if not 64-bit do not offer this function
    QString envPath(qgetenv("COAL_VST64_PATH"));
    if (!envPath.isEmpty()) { return envPath; 
    } else {
        QString configVst64Path = eAppConfig.vst64Path;
        if (QDir(configVst64Path).exists()) { return configVst64Path;
        } else {
            // TODO
            return envPath;
        }
    }
    return envPath; // never reached
}

QString GetApplicationDirectory() {
    return QCoreApplication::applicationFilePath();
}

QString GetDataDirectory() {
// if WIN
    return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
}

QString GetDocumentsDirectory() {
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Coal";
}

QString GetUserDirectory() {
    return QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
}

} // namespace