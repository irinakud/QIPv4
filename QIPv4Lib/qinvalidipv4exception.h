#ifndef QIPV4EXCEPTION_H
#define QIPV4EXCEPTION_H

#include <QException>

namespace QIPv4WidgetLib
{
    /*!
      \brief QInvalidIPv4Exception class derived from QException, contains a message which can be accessed through the getMessage() method.
     */
    class QInvalidIPv4Exception : public QException
    {
    public:
        QInvalidIPv4Exception(const QString& message = "") : m_message(message) {}

        void raise() const override { throw *this; }
        QInvalidIPv4Exception *clone() const override { return new QInvalidIPv4Exception(*this); }

        QString getMessage() const { return m_message; }

    private:
        QString m_message;

    };
}

#endif // QIPV4EXCEPTION_H
