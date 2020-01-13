#ifndef ARIA2WRAPPER_H
#define ARIA2WRAPPER_H

#include <aria2/aria2.h>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>
#include <QObject>
#include <QPair>
#include <QString>


int downloadEventCallback(aria2::Session* session, aria2::DownloadEvent event, const aria2::A2Gid gid, void* userData);
class Aria2Wrapper : public QObject {
    Q_OBJECT
public:
    explicit Aria2Wrapper(QObject *parent = nullptr);
    aria2::DownloadHandle *getHandlePeerTask();

signals:
private:
    aria2::Session* session;
    aria2::SessionConfig config;
    aria2::KeyVals options;
    aria2::GlobalStat gstat;
    void readConfiger(const QString);
    std::string boolToString(bool);
};

#endif // ARIA2WRAPPER_H
