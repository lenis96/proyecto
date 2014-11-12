#ifndef NUEVOCONCEPTOVENTANA_H
#define NUEVOCONCEPTOVENTANA_H

#include <QDialog>

namespace Ui {
class nuevoConceptoVentana;
}

class nuevoConceptoVentana : public QDialog
{
    Q_OBJECT

public:
    explicit nuevoConceptoVentana(QWidget *parent = 0);
    ~nuevoConceptoVentana();

private:
    Ui::nuevoConceptoVentana *ui;
};

#endif // NUEVOCONCEPTOVENTANA_H
