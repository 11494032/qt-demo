#ifndef WRITEJSON_H
#define WRITEJSON_H

#include <QCoreApplication>
#include <QJsonDocument>//json文档
#include <QJsonArray>//json数组
#include <QJsonObject>//json对象
#include <QJsonValue>//json值
#include <QJsonParseError>//错误处理
#include <QDebug>

class WriteJson
{
public:
    WriteJson();
    void WriteData( QStringList data );
};

#endif // WRITEJSON_H
