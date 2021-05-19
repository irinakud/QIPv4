#include "qappwidget.h"
#include "qipv4edit.h"
#include "qinvalidipv4exception.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

QAppWidget::QAppWidget(QWidget* parent) : QGroupBox(tr("Enter IP Address:"), parent)
{
    QGridLayout* test1Layout = new QGridLayout;

    test1Layout->addWidget(new QLabel(tr("QLineEdit:")), 0, 0, Qt::AlignRight);
    m_lineEdit = new QLineEdit;
    test1Layout->addWidget(m_lineEdit, 0, 1);
    QPushButton* tryIPButton = new QPushButton("Copy to QIPv4Edit");
    tryIPButton->setToolTip(tr("Set the value from QLineEdit to QIPv4Edit"));
    test1Layout->addWidget(tryIPButton, 0, 2);

    test1Layout->addWidget(new QLabel(tr("QIPv4Edit:")), 1, 0, Qt::AlignRight);
    m_IPv4edit = new QIPv4WidgetLib::QIPv4Edit;
    test1Layout->addWidget(m_IPv4edit, 1, 1);

    test1Layout->addWidget(new QLabel(tr("QIPv4Edit Status:")), 2, 0, Qt::AlignRight);
    m_errorOutput = new QLineEdit;
    m_errorOutput->setReadOnly(true);
    test1Layout->addWidget(m_errorOutput, 2, 1);

    connect(m_IPv4edit, &QIPv4WidgetLib::QIPv4Edit::textChanged, this, &QAppWidget::updateStatusText);
    connect(tryIPButton, &QPushButton::clicked, this, &QAppWidget::setQIPv4EditValue);

    setLayout(test1Layout);
}
QAppWidget::~QAppWidget()
{

}
void QAppWidget::updateStatusText()
{
    if (m_IPv4edit->hasAcceptableInput())
    {
        m_errorOutput->setText(tr("Valid IP Address"));
        m_errorOutput->setStyleSheet("color: green;");
    }
    else
    {
        m_errorOutput->setText(tr("Invalid IP Address"));
        m_errorOutput->setStyleSheet("color: red;");
    }
}
void QAppWidget::setQIPv4EditValue()
{
    try
    {
        m_IPv4edit->setIP(m_lineEdit->text());
    }
    catch (QIPv4WidgetLib::QInvalidIPv4Exception& ex)
    {
        QMessageBox errorMessage;
        errorMessage.setText("QInvalidIPv4Exception: " + ex.getMessage());
        errorMessage.setIcon(QMessageBox::Critical);
        errorMessage.exec();
    }
}
