#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &Widget::onResult);

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::getData);

    connect(this, &Widget::onReady, this, &Widget::readFile);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::onResult(QNetworkReply *reply)
{
    if(reply->error()){
            qDebug() << "ERROR";
            qDebug() << reply->errorString();
    } else {
    corrTime = QTime::currentTime().toString("hh_mm_ss_zzz");
            QFile *file = new QFile("file"+corrTime+".xml");
            if(file->open(QFile::WriteOnly)){
                file->write(reply->readAll());  // ... и записываем всю информацию со страницы в файл
                file->close();                  // закрываем файл
                qDebug() << "Downloading is completed" << corrTime ;
                emit onReady(); // Посылаем сигнал о завершении получения файла
            }
    }
}

void Widget::getData()
{
    strUrl = ui->lineEdit->text(); // to .pro #DEFINES -= QT_NO_URL_CAST_FROM_STRING
    QUrl url(strUrl);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
    //readFile();  //or +timer for finish process???
}

void Widget::readFile()
{
    QFile file("file"+corrTime+".xml");
    if (!file.open(QIODevice::ReadOnly))
            return;
    ui->textEdit->setText(file.readAll());
}
