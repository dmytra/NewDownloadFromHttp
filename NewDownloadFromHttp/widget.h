#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    QString strUrl;
    QString corrTime;
    ~Widget();

private:
    QNetworkAccessManager *manager;
    Ui::Widget *ui;

signals:
    void onReady();

public slots:
    void readFile();
    void getData();
    void onResult(QNetworkReply *reply);
};

#endif // WIDGET_H
