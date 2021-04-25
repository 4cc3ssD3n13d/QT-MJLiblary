#include <QtCore>

QString CalculateByteSize(qlonglong Bytes){
    QString Number;
    if(Bytes < 0x400){
        Number = QLocale::system().toString(Bytes);
        Number.append(" B");
        return Number;
    }
    else{
        if(Bytes >= 0x400 && Bytes < 0x100000){
            qlonglong Result = (Bytes + (0x400 / 2)) / 0x400;
            if(Result < 0x400){
                Number = QLocale::system().toString(Result);
                Number.append(" KB");
                return Number;
            }
            else{
                qlonglong Result = (Bytes + (0x100000 / 2)) / 0x100000;
                Number = QLocale::system().toString(Result);
                Number.append(" MB");
                return Number;
            }
        }
        else{
            if(Bytes >= 0x100000 && Bytes < 0x40000000){
                qlonglong Result = (Bytes + (0x100000 / 2)) / 0x100000;
                if(Result < 0x100000){
                    Number = QLocale::system().toString(Result);
                    Number.append(" MB");
                    return Number;
                }
                else{
                    qlonglong Result = (Bytes + (0x40000000 / 2)) / 0x40000000;
                    Number = QLocale::system().toString(Result);
                    Number.append(" GB");
                    return Number;
                }
            }
            else{
                if(Bytes >= 0x40000000 && Bytes < 0x10000000000){
                    qlonglong Result = (Bytes + (0x40000000 / 2)) / 0x40000000;
                    if(Result < 0x40000000){
                        Number = QLocale::system().toString(Result);
                        Number.append(" GB");
                        return Number;
                    }
                    else{
                        qlonglong Result = (Bytes + (0x10000000000 / 2)) / 0x10000000000;
                        Number = QLocale::system().toString(Result);
                        Number.append(" TB");
                        return Number;
                    }
                }
                else{
                    qlonglong Result = (Bytes + (0x10000000000 / 2)) / 0x10000000000; //If more than 1 TB, report in TB
                    Number = QLocale::system().toString(Result);
                    Number.append(" TB");
                    return Number;
                }
            }
        }
    }
}
