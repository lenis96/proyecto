#include "nuevoconceptoventana.h"
#include "ui_nuevoconceptoventana.h"

nuevoConceptoVentana::nuevoConceptoVentana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nuevoConceptoVentana)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(enviarInformacion()));
}

nuevoConceptoVentana::~nuevoConceptoVentana()
{
    delete ui;
}
void nuevoConceptoVentana::enviarInformacion(){
    emit emitirInformacionConcepto(ui->lineEdit->text(),ui->spinBox->value(),ui->spinBox_2->value());
}
