#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStandardPaths>
#include <QString>
// JQLibrary lib improt
#include "JQQRCodeWriter.h"
#include "JQQRCodeReader.h"
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

void MainWindow::on_test_pushButton_clicked()
{
    QString str;
    if(ui->lineEdit_name->text() == "")
    {
        return;
    }
    str=ui->label_name->text()+ui->lineEdit_name->text()+"\n";//添加姓名
    if(ui->lineEdit_sex->text().isEmpty() == false)
    {
        str=str+ui->label_sex->text()+ui->lineEdit_sex->text()+"\n";//添加性别
    }
    //添加相关联系方式
    if(ui->lineEdit_QQ->text().isEmpty() == false)
    {
        str=str+ui->label_QQ->text()+ui->lineEdit_QQ->text()+"\n";//添加QQ
    }
    if(ui->lineEdit_weix->text()!="")
    {
         str=str+ui->label_weix->text()+ui->lineEdit_weix->text()+"\n";//添加微信
    }
    if(ui->lineEdit_phone->text().isEmpty() == false)
    {
         str=str+ui->label_phone->text()+ui->lineEdit_phone->text()+"\n";//添加联系方式
    }
    if(ui->lineEdit_Email->text().isEmpty() == false)
    {
         str=str+ui->label_Email->text()+ui->lineEdit_Email->text()+"\n";//添加邮箱
    }
    const auto &&qrCodeImage = JQQRCodeWriter::makeQRcode(str);
    if ( qrCodeImage.isNull() )
    {
        return ;
    }
    //生成的图片保存路径确认
    QString file_path = QCoreApplication::applicationDirPath()+"/"+ui->lineEdit_name->text()+".png";
    qDebug() << "save png succeed:" <<qrCodeImage.save(file_path,"PNG");
}

void MainWindow::on_pushButton_read_clicked()
{
    QString file_path = QCoreApplication::applicationDirPath()+"/"+ui->lineEdit_name->text()+".png";
    const QImage testImage(file_path);
    JQQRCodeReader qrCodeReader;
    qDebug()<<"file_path = "<<file_path<< "decodeImage return:" << qrCodeReader.decodeImage( testImage, JQQRCodeReader::DecodeQrCodeType );
}
