#include "presentacionvista.h"
#include "ui_presentacionvista.h"

presentacionVista::presentacionVista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::presentacionVista)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(0);
    formNt=new nuevoTextoVentana();
    formNi=new nuevaImagenVentana();
    formEe=new editarElementoVista();
    connect(ui->pushButton_4,SIGNAL(pressed()),this,SLOT(ocultar()));
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(nuevoTexto()));
    connect(ui->pushButton_2,SIGNAL(pressed()),this,SLOT(nuevaImagen()));
    connect(ui->pushButton_3,SIGNAL(pressed()),this,SLOT(editarElemento()));
    connect(formNt,SIGNAL(emitirInformacionTexto(QString,int,int)),this,SLOT(enviarInformacionTexto(QString,int,int)));
    connect(formNi,SIGNAL(emitirInformacionImagen(QString,int,int)),this,SLOT(enviarInformacionImagen(QString,int,int)));
    connect(this,SIGNAL(asignarInformacionElem(QString,tipoElemento,int,int)),formEe,SLOT(setInformacionElemento(QString,tipoElemento,int,int)));
    connect(formEe,SIGNAL(emitirInformacionElemento(int,QString,cambioElemento,int,int)),this,SLOT(enviarInformacionElemento(int,QString,cambioElemento,int,int)));
}

presentacionVista::~presentacionVista()
{
    delete ui;
}
void presentacionVista::setInformacionConcepto(QString texto, int x, int y){
    ui->texto1->setText(texto);
    ui->x1->setText(QString::number(x));
    ui->y1->setText(QString::number(y));
}
void presentacionVista::enviarInformacionTexto(QString text,int x, int y){
    emit emtirInformacionElem(ui->spinBox->value(),text,texto,x,y);
}
void presentacionVista::enviarInformacionImagen(QString ubicacion, int x, int y){
    emit emtirInformacionElem(ui->spinBox->value(),ubicacion,imagen,x,y);
}

QSpinBox* presentacionVista::idConcepto(){
    return ui->spinBox;
}
QSpinBox* presentacionVista::idElemento(){
    return formEe->getSpinBox();
}

void presentacionVista::maximoConceptos(int max){
    ui->spinBox->setMaximum(max);
}
void presentacionVista::ocultar(){
    this->hide();
    emit ocultado();
}
void presentacionVista::nuevoTexto(){
    formNt->show();
}
void presentacionVista::nuevaImagen(){
    if(formNi->pedirImagen()){
        formNi->show();
    }

}
void presentacionVista::editarElemento(){
    formEe->show();

}
void presentacionVista::maximoElementos(int max){
    formEe->maximoElementos(max);
}

void presentacionVista::ocultarElementos(){
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->texto1->hide();
    ui->x1->hide();
    ui->y1->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    //ui->pushButton_4->hide();
    ui->spinBox->setValue(1);
    ui->spinBox->selectAll();
    ui->spinBox->setFocus(Qt::ActiveWindowFocusReason);
}
void presentacionVista::mostrarElementos(){
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->texto1->show();
    ui->x1->show();
    ui->y1->show();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
}
void presentacionVista::setInformacionElemento(QString cadena, tipoElemento tipo, int x, int y){
    emit asignarInformacionElem(cadena,tipo,x,y);

}
void presentacionVista::enviarInformacionElemento(int idE, QString cadena, cambioElemento tipo, int x, int y){
    emit emtirInformacionEdicionElem(ui->spinBox->value(),idE,cadena,tipo,x,y);
}

