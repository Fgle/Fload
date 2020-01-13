#ifndef NEWDOWNLOADFILE_H
#define NEWDOWNLOADFILE_H

#include <QWidget>

namespace Ui {
class NewDownloadFile;
}

class NewDownloadFile : public QWidget
{
    Q_OBJECT

public:
    explicit NewDownloadFile(QWidget *parent = nullptr);
    ~NewDownloadFile();

private:
    Ui::NewDownloadFile *ui;
};

#endif // NEWDOWNLOADFILE_H
