#include "writexml.h"
#include <QDebug>
#include <QTxml/QDomDocument>
WriteXml::WriteXml()
{
}

bool WriteXml::writeFile( QString fileName )
{

    QFile file("mydocument.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
         qDebug()<<"Can't open the file!"<<endl;
        return false;
    }

    QDomDocument doc("mydocument");
    QDomText text;
    QDomElement element;

    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\'1.0\'");

    doc.appendChild(instruction);

    QDomElement root = doc.createElement("root");
    doc.appendChild( root );
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


    QTextStream out(&file);
    doc.save(out,4);

    file.close();
    return true;
}
