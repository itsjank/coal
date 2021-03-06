
#include "AppConfig.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
using namespace coal;

namespace coal {

AppConfig eAppConfig;

AppConfig::AppConfig()
    : vst32Path("USE_ENV_VAR"),
      vst64Path("USE_ENV_VAR"),
      themeName("defaultLight")
{}

void AppConfig::Load(QString fromPath) {
    QFile f(fromPath);
    if (f.exists() && f.open(QIODevice::ReadOnly)) {
        QXmlStreamReader rd(&f);
        while (!rd.atEnd()) {
            rd.readNext();
            if (rd.isStartElement()) {
                if (rd.name() == "Theme") {
                    rd.readNext();
                    themeName = rd.text().toString();
                } else if (rd.name() == "Vst32Path") {
                    rd.readNext();
                    vst32Path = rd.text().toString();
                } else if (rd.name() == "Vst64Path") {
                    rd.readNext();
                    vst64Path = rd.text().toString();
                }
            } else {
                // Error, file probably messed up (?)
                return;
            }
        }
        if (rd.hasError()) { return; }
        f.close();
    }
}

void AppConfig::Save(QString toPath) {
    QFile f(toPath);
    if (!f.open(QIODevice::WriteOnly)) { return; }

    QXmlStreamWriter wr(&f);
    wr.setAutoFormatting(true);

    // <HEAD>
    wr.writeComment("Auto-generated by Coal");
    wr.writeStartDocument(); // doc
    wr.writeStartElement("Configuration");

    wr.writeTextElement("CfgSaveVersion", QString::number(CFG_SAVE_VER));
    wr.writeTextElement("Theme", themeName);
    wr.writeTextElement("Vst32Path", vst32Path);
    wr.writeTextElement("Vst64Path", vst64Path);

    // </HEAD>
    wr.writeEndElement();
    wr.writeEndDocument();

    f.close();
}

} // namespace