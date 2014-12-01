#include "nuevotexto.h"
#include "ui_nuevotexto.h"

nuevoTextoVentana::nuevoTextoVentana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nuevoTexto)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(enviarInformacion()));
    ui->textEdit->setText("escriba aqui el texto");
    ui->textEdit->selectAll();
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
}

nuevoTextoVentana::~nuevoTextoVentana()
{
    delete ui;
}
void nuevoTextoVentana::enviarInformacion(){
    emit emitirInformacionTexto(ui->textEdit->toPlainText(),ui->spinBox->value(),ui->spinBox_2->value());
    ui->textEdit->setText("escriba aqui el texto");
    ui->textEdit->selectAll();
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
}
