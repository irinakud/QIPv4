#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>

namespace QIPv4WidgetLib
{
    /*!
     * \brief Removes padding with spaces from the input IP and then formats it to a "natural" form, i.e. "127. 00.000.  1" will format to "127.0.0.1"
     */
    QString naturalizeIP(const QString& ip);
}

#endif // UTILITIES_H
