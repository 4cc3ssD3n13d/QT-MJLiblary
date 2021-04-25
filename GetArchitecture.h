#include <QtCore>
#include <windows.h>

QString GetArchitecture(){
    _SYSTEM_INFO SysInfo;
    GetNativeSystemInfo(&SysInfo);
    QString Architecture;
    if (SysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL){
         Architecture = "x86";
    }
    if (SysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64){
        Architecture = "x64";
    }
    return Architecture;
}
