#include "nuevoconceptoventana.h"
#include "ui_nuevoconceptoventana.h"

nuevoConceptoVentana::nuevoConceptoVentana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nuevoConceptoVentana)
{
    ui->setupUi(this);
}

nuevoConceptoVentana::~nuevoConceptoVentana()
{
    delete ui;
}
