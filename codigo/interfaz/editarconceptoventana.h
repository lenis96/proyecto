#ifndef EDITARCONCEPTOVENTANA_H
#define EDITARCONCEPTOVENTANA_H

#include <QDialog>
#include <QSpinBox>
enum cambioConcepto{cambiarConcepto,eliminarConcepto};
namespace Ui {
class editarConceptoVentana;
}

class editarConceptoVentana : public QDialog
{
    Q_OBJECT

public:
    explicit editarConceptoVentana(QWidget *parent = 0);
    ~editarConceptoVentana();
    void maximoConceptos(int);
    QSpinBox* idConcepto();
signals:
    void emitirInformacionConcepto(int,QString,int,int,cambioConcepto);

private:
    Ui::editarConceptoVentana *ui;
protected slots:
    virtual void setInformacionConcepto(QString,int,int);
    virtual void enviarInformacion();
    virtual void elimComcepto();
};

#endif // EDITARCONCEPTOVENTANA_H
