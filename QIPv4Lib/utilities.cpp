#include "utilities.h"

#include <QStringList>
#include <QRegularExpression>

namespace QIPv4WidgetLib
{
    QString naturalizeIP(const QString& ip)
    {
        QStringList parts = ip.split(".");
        for (int i = 0; i < parts.length(); i++)
        {
            if (parts[i].length() == 3)
            {
                parts[i].replace(QRegularExpression("^(0)|^(\\s)"), "");
            }
            if (parts[i].length() == 2)
            {
                parts[i].replace(QRegularExpression("^(0)|^(\\s)"), "");
            }
        }
        QString result;
        result = parts.join(".");
        return result;
    }
}
