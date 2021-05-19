TEMPLATE = subdirs

SUBDIRS += \
    QIPv4Lib \
    QIPv4TestApp

QIPv4TestApp.depends = QIPv4Lib
