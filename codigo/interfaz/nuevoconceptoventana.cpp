#include "nuevoconceptoventana.h"
#include "ui_nuevoconceptoventana.h"

nuevoConceptoVentana::nuevoConceptoVentana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nuevoConceptoVentana)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(enviarInformacion()));
    ui->lineEdit->setText("nuevo Concepto");
    ui->lineEdit->selectAll();
    ui->spinBox->setValue(0);
    //ui->spinBox->setSi
    ui->spinBox_2->setValue(0);
}

nuevoConceptoVentana::~nuevoConceptoVentana()
{
    delete ui;
}
void nuevoConceptoVentana::enviarInformacion(){
    emit emitirInformacionConcepto(ui->lineEdit->text(),ui->spinBox_2->value(),ui->spinBox->value());

    ui->lineEdit->setText("nuevo Concepto");
    ui->lineEdit->selectAll();
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    //emit si();
}
