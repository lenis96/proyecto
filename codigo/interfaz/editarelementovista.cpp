#include "editarelementovista.h"
#include "ui_editarelementovista.h"

editarElementoVista::editarElementoVista(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editarElementoVista)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(enviarInformacion()));
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(imagenCambiada()));
    connect(ui->pushButton_2,SIGNAL(pressed()),this,SLOT(elimElemento()));
}

editarElementoVista::~editarElementoVista()
{
    delete ui;
}
QSpinBox* editarElementoVista::getSpinBox(){
    return ui->spinBox;
}
void editarElementoVista::maximoElementos(int max){
    ui->spinBox->setMaximum(max);
}
void editarElementoVista::setInformacionElemento(QString cadena,tipoElemento tipo, int x, int y){
    if(tipo==texto){
        ui->pushButton->hide();
        ui->textEdit->setText(cadena);
        ui->textEdit->setEnabled(true);
        ui->spinBox_2->setValue(x);
        ui->spinBox_3->setValue(y);
    }
    else if(tipo==imagen){
        ui->pushButton->show();
        ui->textEdit->setText(cadena);
        ui->textEdit->setEnabled(false);
        ui->spinBox_2->setValue(x);
        ui->spinBox_3->setValue(y);
    }
}
void editarElementoVista::enviarInformacion(){
    emit emitirInformacionElemento(ui->spinBox->value(),ui->textEdit->toPlainText(),cambiarElemento,ui->spinBox_2->value(),ui->spinBox_3->value());

}
void editarElementoVista::elimElemento(){
    emit emitirInformacionElemento(ui->spinBox->value(),ui->textEdit->toPlainText(),eliminarElemento,ui->spinBox_2->value(),ui->spinBox_3->value());
    this->hide();
}
void editarElementoVista::imagenCambiada(){
    QString nombreArchivo=QFileDialog::getOpenFileName(this,tr("seleccionar Imagen"),"","imagenes (*.jpeh | *.png | *.jpg);;All files (*.*)");
    if(nombreArchivo!=""){
    ui->textEdit->setText(nombreArchivo);
   }
}
