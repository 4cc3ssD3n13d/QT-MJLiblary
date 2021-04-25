#include <QtCore>

void WriteFile(QByteArray ByteArray, QString Path){
    QSaveFile File(Path);
    File.open(QIODevice::WriteOnly);
    File.write(ByteArray);
    File.commit();
}
