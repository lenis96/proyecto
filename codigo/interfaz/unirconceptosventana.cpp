#include "unirconceptosventana.h"
#include "ui_unirconceptosventana.h"

unirConceptosVentana::unirConceptosVentana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unirConceptosVentana)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(0);
    ui->spinBox_2->setMinimum(0);
    ui->texto1->setText("");
    ui->texto2->setText("");
    ui->x1->setText("");
    ui->x2->setText("");
    ui->y1->setText("");
    ui->y2->setText("");
    //connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(mismoConcepto()));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(enviarInformacion()));
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(elimUnion()));
}

void unirConceptosVentana::maximoConceptos(int max){
    ui->spinBox->setMaximum(max);
    ui->spinBox_2->setMaximum(max);
}

unirConceptosVentana::~unirConceptosVentana()
{
    delete ui;
}

/*void unirConceptosVentana::mismoConcepto(){
    if(ui->spinBox->value()==ui->spinBox_2->value()){
        ui->buttonBox->setEnabled(false);
    }
}*/

void unirConceptosVentana::setInformacionConcepto1(QString texto, int x, int y){
    ui->texto1->setText(texto);
    ui->x1->setText(QString::number(x));
    ui->y1->setText(QString::number(y));
}

void unirConceptosVentana::setInformacionConcepto2(QString texto, int x, int y){
    ui->texto2->setText(texto);
    ui->x2->setText(QString::number(x));
    ui->y2->setText(QString::number(y));
}
void unirConceptosVentana::enviarInformacion(){
    emit emitirInformacion(ui->spinBox->value(),ui->spinBox_2->value(),crearUnion);
    //ui->spinBox->selectAll();
    ui->spinBox_2->selectAll();
}

QSpinBox* unirConceptosVentana::id1Concepto(){
    return ui->spinBox;
}

QSpinBox* unirConceptosVentana::id2Concepto(){
    return ui->spinBox_2;
}
void unirConceptosVentana::elimUnion(){
    emit emitirInformacion(ui->spinBox->value(),ui->spinBox_2->value(),eliminarUnion);
    this->hide();
    ui->spinBox->selectAll();
}


