#include "writexml.h"
#include <QDebug>
#include <QTxml/QDomDocument>
#include <iostream>
WriteXml::WriteXml()
{
}

bool WriteXml::writeFile( QString data)
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

    QDomNodeList list=doc.childNodes();
    for(int i=0;i<list.count();i++){
        QDomNode node=list.at(i);
        qDebug()<<"node name is "<<node.nodeName();
        qDebug()<<"node type is "<<node.nodeType();
    }
    QTextStream out(&file);
    doc.save(out,4);

    file.close();
    return true;
}
