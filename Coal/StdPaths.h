
#ifndef __StdPaths_h__
#define __StdPaths_h__

#include <QString>

namespace coal {

QString GetVst32Directory();
QString GetVst64Directory();
QString GetApplicationDirectory();
QString GetDataDirectory();
QString GetDocumentsDirectory();

QString GetUserDirectory(); // for path making

} // namespace

#endif // __StdPaths_h__