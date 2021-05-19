#ifndef QIPV4EDIT_H
#define QIPV4EDIT_H

#include <QLineEdit>

class QValidator;

namespace QIPv4WidgetLib
{
    /*!
       \brief QIPv4Edit class is a QWidget which only supports IPv4 IP address entry. Throws and exception on invalid input to setIP method.
       Derived from QLineEdit.
    */
    class QIPv4Edit : public QLineEdit
    {
    public:
        QIPv4Edit(QWidget* parent = nullptr);
        ~QIPv4Edit();

        QString getIP() const;

        /*!
           \brief Formats input to a "natural" form, i.e. "127.000. 00.010" will format to "127.0.0.10". Throws and exception on invalid input.
        */
        void setIP(const QString& ip);

    private:
        QValidator* m_validator;
    };

}

#endif // QIPV4EDIT_H
