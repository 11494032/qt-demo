#include "writexml.h"
#include <QDebug>
#include <QTxml/QDomDocument>
#include <iostream>

WriteXml::WriteXml()
{
}

bool WriteXml::writeFile( QStringList data)
{
    QString strDoc;
    QFile file("mydocument.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
         qDebug()<<"Can't open the file!"<<endl;
        return false;
    }

    QDomDocument doc("first version");
    QDomText text;
    QDomElement element;

    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"GB2312\"");

    doc.appendChild(instruction);

#if 0
     QDomElement root = doc.documentElement();
     root = doc.createElement("root");
    doc.appendChild( root );

    //getElementsByTagName('root');

    QDomElement general = doc.createElement("general");
    doc.appendChild( general );



    element = doc.createElement("author");
    text = doc.createTextNode( "zeki" );
    element.appendChild(text);
    general.appendChild( element );

    element = doc.createElement("ss");
    text = doc.createTextNode( "wo" );
    element.appendChild(text);
    general.appendChild( element );
#endif

    QStringList sections;
    for( int j = 0; j < data.length(); j++)
    {
        sections = data[j].split(QRegExp("[ ]")); //把每一个块装进一个QStringList中
       // for( int i = 0; i<sections.length(); i++)
        qDebug() << sections.at(2).trimmed() << endl;   //大时间
        qDebug() << sections.at(3).trimmed() << endl;   //小时间

       // qDebug() << sections.at(9).trimmed() << endl;

        QStringList sections_part;
        //报文信息 "msg::00069"  "869405030455100" "1529971167" "102" "1" "100" "BC95HB-02-STD_900~V100R100C10B657SP5" "NP_100_A~OTS_CC_1.3|2288154" "-533" "273" "7547" "113" "215611138" "0"  "99"  "-65" "-234" "h=900|t=20|308:308:28:3:3:94:-61:-232:0:80:60"
        sections_part = sections.at(9).trimmed().split(QRegExp("[,]"));
        for( int i = 0; i<sections_part.length(); i++)
        {
            qDebug() << sections_part.at(i).trimmed() << endl;
        }

        QDomNodeList list=doc.childNodes();
        for(int i=0;i<list.count();i++){
            QDomNode node=list.at(i);
           // qDebug()<<"node name is "<<node.nodeName();
           // qDebug()<<"node type is "<<node.nodeType();

        }

    }

    QTextStream out(&file);
    doc.save(out,4);

    file.close();
    return true;
}
