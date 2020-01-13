#include "newdownloadfile.h"
#include "ui_newdownloadfile.h"

NewDownloadFile::NewDownloadFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewDownloadFile)
{
    ui->setupUi(this);
}

NewDownloadFile::~NewDownloadFile()
{
    delete ui;
}
