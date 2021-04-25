#include <QtCore>
#include <windows.h>

QString GetMemorySize(){
    MEMORYSTATUSEX Status;
    Status.dwLength = sizeof(Status);
    GlobalMemoryStatusEx(&Status);
    return CalculateByteSize(Status.ullTotalPhys);
}
