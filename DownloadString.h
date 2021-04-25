#include <QtCore>
#include <QtNetwork>

QString DownloadString(QString Url){
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
    return Response->readAll();
}
