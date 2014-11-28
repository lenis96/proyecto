#ifndef UNIRCONCEPTOSVENTANA_H
#define UNIRCONCEPTOSVENTANA_H

#include <QDialog>
#include <QSpinBox>
enum cambioUnion{crearUnion,eliminarUnion};
namespace Ui {
class unirConceptosVentana;
}

class unirConceptosVentana : public QDialog
{
    Q_OBJECT

public:
    explicit unirConceptosVentana(QWidget *parent = 0);
    ~unirConceptosVentana();
    void maximoConceptos(int);
    QSpinBox* id1Concepto();
    QSpinBox* id2Concepto();
signals:
    void emitirInformacion(int,int,cambioUnion);

private:
    Ui::unirConceptosVentana *ui;
protected slots:
    //virtual void mismoConcepto();
    virtual void setInformacionConcepto1(QString,int,int);
    virtual void setInformacionConcepto2(QString,int,int);
    virtual void enviarInformacion();
    virtual void elimUnion();
};

#endif // UNIRCONCEPTOSVENTANA_H
