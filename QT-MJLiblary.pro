QT += core gui
QT += widgets
QT += network

CONFIG += c++17

SOURCES += \
    Main.cpp \
    MainWindow.cpp

HEADERS += \
    CalculateByteSize.h \
    DownloadPixmap.h \
    DownloadString.h \
    GetArchitecture.h \
    GetCpuName.h \
    GetGpuName.h \
    GetMemorySize.h \
    Global.h \
    MainWindow.h \
    RandomInt.h \
    RandomString.h \
    WriteFile.h

FORMS += \
    MainWindow.ui
