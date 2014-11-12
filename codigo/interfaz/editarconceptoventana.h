#ifndef EDITARCONCEPTOVENTANA_H
#define EDITARCONCEPTOVENTANA_H

#include <QDialog>

namespace Ui {
class editarConceptoVentana;
}

class editarConceptoVentana : public QDialog
{
    Q_OBJECT

public:
    explicit editarConceptoVentana(QWidget *parent = 0);
    ~editarConceptoVentana();

private:
    Ui::editarConceptoVentana *ui;
};

#endif // EDITARCONCEPTOVENTANA_H
