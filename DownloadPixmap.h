#include <QtCore>
#include <QWidget>
#include <QtNetwork>

QPixmap DownloadPixmap(QString Url, int Width,int Height){
    QNetworkAccessManager* Manager = new QNetworkAccessManager;
    QNetworkRequest Request;
    Request.setUrl(Url);
    QSslConfiguration SSLConfig(QSslConfiguration::defaultConfiguration());
    SSLConfig.setProtocol(QSsl::TlsV1_3);
    Request.setSslConfiguration(SSLConfig);
    QNetworkReply *Response = Manager->get(Request);
    QEventLoop Event;
    QObject::connect(Response, SIGNAL(finished()), &Event, SLOT(quit()));
    Event.exec();
    QByteArray Bytes = Response->readAll();
    QImage Img(Width, Height, QImage::Format_Indexed8);
    Img.loadFromData(Bytes);
    return QPixmap::fromImage(Img);
}
