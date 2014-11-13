#ifndef NUEVOCONCEPTOVENTANA_H
#define NUEVOCONCEPTOVENTANA_H

#include <QDialog>
#include <QString>
namespace Ui {
class nuevoConceptoVentana;
}

class nuevoConceptoVentana : public QDialog
{
    Q_OBJECT

public:
    explicit nuevoConceptoVentana(QWidget *parent = 0);
    ~nuevoConceptoVentana();
    signals:
    void emitirInformacionConcepto(QString concepto,int posX,int posY);


private:
    Ui::nuevoConceptoVentana *ui;
    protected slots:
    virtual void enviarInformacion();
};

#endif // NUEVOCONCEPTOVENTANA_H
