
#ifndef __AppConfig_h__
#define __AppConfig_h__

#include <QString>

namespace coal {

#define CFG_SAVE_VER 181229 // YY-MM-DD

struct AppConfig {
    AppConfig();

    QString vst32Path;
    QString vst64Path;
    QString themeName;

    void Load(QString fromPath);
    void Save(QString toPath);
};

extern AppConfig eAppConfig;

} // namespace

#endif // __AppConfig_h__