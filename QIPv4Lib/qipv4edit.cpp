#include "qipv4edit.h"
#include "utilities.h"
#include "qinvalidipv4exception.h"

#include <QRegularExpressionValidator>
#include <QRegularExpression>

namespace QIPv4WidgetLib
{
    QIPv4Edit::QIPv4Edit(QWidget* parent) : QLineEdit(parent)
    {
        QString rx_number_0_to_255 = "(\\s{0,2}[0-9]{1}|\\s{0,1}[1-9]{1}[0-9]{0,1}|1{1}[0-9]{0,2}|2[0-4]{0,1}[0-9]{0,1}|25[0-5]{0,1})";
        QRegularExpression rx("(" + rx_number_0_to_255 + "\\.){3}" + rx_number_0_to_255);

        m_validator = new QRegularExpressionValidator(rx, this);
        setValidator(m_validator);
    }
    QIPv4Edit::~QIPv4Edit()
    {

    }
    void QIPv4Edit::setIP(const QString& ip)
    {
        QString naturalizedIP = naturalizeIP(ip);
        int pos = 0;

        if (m_validator->validate(naturalizedIP, pos) != QValidator::Acceptable)
            throw QInvalidIPv4Exception("Invalid IP");

        setText(naturalizedIP);
    }
    QString QIPv4Edit::getIP() const
    {
        return text();
    }
}
