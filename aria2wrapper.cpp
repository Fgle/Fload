#include "aria2wrapper.h"

Aria2Wrapper::Aria2Wrapper(QObject *parent) : QObject(parent) {
    aria2::libraryInit();
    readConfiger("FloadConfiger.json");
    config.downloadEventCallback = downloadEventCallback;
    session = aria2::sessionNew(options, config);
}

int downloadEventCallback(aria2::Session *session, aria2::DownloadEvent event, const aria2::A2Gid gid, void *userData) {

}

void Aria2Wrapper::readConfiger(const QString path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Aria2::Configer::read json file failed" << endl;
        return;
    }
    QByteArray conf = file.readAll();
    QJsonParseError e;
    auto doc = QJsonDocument::fromJson(conf, &e);
    if (e.error != QJsonParseError::NoError || doc.isNull()) {
        qDebug() << "Aria2::Json::" << e.errorString() << endl;
        return;
    }
    auto obj = doc.object();
    options.push_back(std::pair<std::string, std::string>("input-file", "aria2.session"));
    options.push_back(std::pair<std::string, std::string>("save-session", "aria2.session"));
    options.push_back(std::pair<std::string, std::string>("continue", boolToString(obj["continue"].toBool())));
    options.push_back(std::pair<std::string, std::string>("dir", obj["dir"].toString().toStdString()));
    options.push_back(std::pair<std::string, std::string>("max-concurrent-downloads", QString::number(obj["max-concurrent-downloads"].toInt()).toStdString()));
    options.push_back(std::pair<std::string, std::string>("max-connection-per-server", QString::number(obj["max-connection-per-server"].toInt()).toStdString()));
    options.push_back(std::pair<std::string, std::string>("max-overall-download-limit", obj["max-overall-download-limit"].toString().toStdString()));
    options.push_back(std::pair<std::string, std::string>("max-overall-upload-limit", obj["max-overall-upload-limit"].toString().toStdString()));
    options.push_back(std::pair<std::string, std::string>());
    options.push_back(std::pair<std::string, std::string>());
    options.push_back(std::pair<std::string, std::string>());
}

std::string Aria2Wrapper::boolToString(bool state) {
    if (state)
        return "true";
    else
        return "false";
}
