#include "cuadroarchivo.h"
#include "ui_cuadroarchivo.h"

CuadroArchivo::CuadroArchivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CuadroArchivo)
{
    ui->setupUi(this);
    cancelado=false;
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(enviarSi()));
    connect(ui->pushButton_2,SIGNAL(pressed()),this,SLOT(enviarNo()));
    connect(ui->pushButton_3,SIGNAL(pressed()),this,SLOT(enviarCancelar()));
}

CuadroArchivo::~CuadroArchivo()
{
    delete ui;
}
void CuadroArchivo::enviarSi(){
    emit emitirSi();
    this->hide();
}
void CuadroArchivo::enviarNo(){
    emit emitirNo();
    this->hide();
}
void CuadroArchivo::enviarCancelar(){
    emit emitirCalncelar();
    cancelado=true;
    this->hide();
}
