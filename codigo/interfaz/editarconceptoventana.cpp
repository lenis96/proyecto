#include "editarconceptoventana.h"
#include "ui_editarconceptoventana.h"

editarConceptoVentana::editarConceptoVentana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editarConceptoVentana)
{
    ui->setupUi(this);
    connect(ui->buttonBox_2,SIGNAL(accepted()),this,SLOT(enviarInformacion()));
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(enviarInformacion()));
    connect(ui->pushButton_2,SIGNAL(pressed()),this,SLOT(elimComcepto()));
}

editarConceptoVentana::~editarConceptoVentana()
{
    delete ui;
}
void editarConceptoVentana::maximoConceptos(int max){
    ui->spinBox_3->setMaximum(max);
}
QSpinBox* editarConceptoVentana::idConcepto(){
    return ui->spinBox_3;
}
void editarConceptoVentana::setInformacionConcepto(QString texto, int x, int y){
    ui->lineEdit->setText(texto);
    ui->spinBox_2->setValue(x);
    ui->spinBox->setValue(y);
}
void editarConceptoVentana::enviarInformacion(){
    emit emitirInformacionConcepto(ui->spinBox_3->value(),ui->lineEdit->text(),ui->spinBox_2->value(),ui->spinBox->value(),cambiarConcepto);
    ui->spinBox_3->selectAll();
}
void editarConceptoVentana::elimComcepto(){
    emit emitirInformacionConcepto(ui->spinBox_3->value(),"",0,0,eliminarConcepto);
    this->hide();
    ui->spinBox_3->selectAll();
}

