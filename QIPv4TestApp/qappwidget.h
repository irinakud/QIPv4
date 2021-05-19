#ifndef QAPPWIDGET_H
#define QAPPWIDGET_H

#include <QGroupBox>

class QLineEdit;
namespace QIPv4WidgetLib
{
    class QIPv4Edit;
}

class QAppWidget : public QGroupBox
{
    Q_OBJECT

public:
    QAppWidget(QWidget* parent = nullptr);
    ~QAppWidget();

private Q_SLOTS:
    void updateStatusText();
    void setQIPv4EditValue();

private:
    QIPv4WidgetLib::QIPv4Edit* m_IPv4edit;
    QLineEdit* m_errorOutput;
    QLineEdit* m_lineEdit;
};

#endif // QAPPWIDGET_H
