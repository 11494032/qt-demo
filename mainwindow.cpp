#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

#include "writejson.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_choiceFileButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("文件选择"), "",tr("test(*)"));
    qDebug()<<filename;
    ui->fineNameLineEdit->clear();
    ui->fineNameLineEdit->setText(filename);
    if( filename.isEmpty())
    {
        QMessageBox::about(this,tr("提示信息"),tr("空文件"));
        return;
    }

     QStringList displayString;
     QFile file( filename );
     if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
         QMessageBox::about(this,tr("提示信息"),tr("不能打开的文件"));
         qDebug()<<"Can't open the file!"<<endl;
     }
     while(!file.atEnd())
     {
         QByteArray line = file.readLine();
         QString str(line);
         if( str.contains("NP_100_A",Qt::CaseSensitive) )
         {
           // qDebug()<< str;
            displayString.append(str);

         }
     }

     WriteJson writeJson;
     writeJson.WriteData( displayString );
}

void MainWindow::on_pushButton_clicked()
{

}
