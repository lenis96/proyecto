#include "nuevaimagenventana.h"
#include "ui_nuevaimagenventana.h"

nuevaImagenVentana::nuevaImagenVentana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nuevaImagenVentana)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(enviarInformacion()));
}

nuevaImagenVentana::~nuevaImagenVentana()
{
    delete ui;
}
bool nuevaImagenVentana::pedirImagen(){
    QString nombreArchivo=QFileDialog::getOpenFileName(this,tr("seleccionar Imagen"),"","imagenes (*.jpeh | *.png | *.jpg);;All files (*.*)");
    ui->label_4->setText(nombreArchivo);
    if(ui->label_4->text()==""){
        return false;
    }
    else{
        return true;
    }

}
void nuevaImagenVentana::enviarInformacion(){
    emit emitirInformacionImagen(ui->label_4->text(),ui->spinBox->value(),ui->spinBox_2->value());
}
