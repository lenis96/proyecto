#include "editarconceptoventana.h"
#include "ui_editarconceptoventana.h"

editarConceptoVentana::editarConceptoVentana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editarConceptoVentana)
{
    ui->setupUi(this);
}

editarConceptoVentana::~editarConceptoVentana()
{
    delete ui;
}
