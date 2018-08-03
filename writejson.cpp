#include "writejson.h"
#include <QFile>

WriteJson::WriteJson()
{

}

void WriteJson::WriteData( QStringList data )
{

    QJsonDocument json;
    QJsonArray array;
    QJsonObject object;
    QStringList sections;

    for( int j = 0; j < data.length(); j++)
    {
        sections = data[j].split(QRegExp("[ ]")); //把每一个块装进一个QStringList中
       // for( int i = 0; i<sections.length(); i++)
       // qDebug() << sections.at(2).trimmed() << endl;   //大时间
        //qDebug() << sections.at(3).trimmed() << endl;   //小时间

       // qDebug() << sections.at(9).trimmed() << endl;

        QStringList sections_part;
        //报文信息 "msg::00069"  "869405030455100" "1529971167" "102" "1" "100" "BC95HB-02-STD_900~V100R100C10B657SP5" "NP_100_A~OTS_CC_1.3|2288154" "-533" "273" "7547" "113" "215611138" "0"  "99"  "-65" "-234" "h=900|t=20|308:308:28:3:3:94:-61:-232:0:80:60"
        sections_part = sections.at(9).trimmed().split(QRegExp("[,]"));


        QStringList sections_id;
        sections_id = sections_part.at(0).trimmed().split(QRegExp("[:]"));

        object.insert("nb_state", sections_part.at(8) );
        object.insert("ver", sections_part.at(7) );
        object.insert("nb_ver", sections_part.at(6) );
        object.insert("bat", sections_part.at(5) );
        object.insert("net_state", sections_part.at(4) );
        object.insert("car_status", sections_part.at(3) );
        object.insert("timestamp", sections_part.at(2) );
        object.insert("imei", sections_part.at(1) );
        object.insert("seq", sections_id.at(2) );
        object.insert("time ",sections.at(2).trimmed() +" " + sections.at(3).trimmed() );
        json.setObject(object);
        qDebug()<<json.toJson(QJsonDocument::Compact);
    }

    //最外层是大括号所以是object

}
