#ifndef EDITARELEMENTOVISTA_H
#define EDITARELEMENTOVISTA_H

#include <QDialog>
#include <QtGui>
#include <elementopresentacion.h>
#include <QString>
enum cambioElemento{cambiarElemento,eliminarElemento};
namespace Ui {
class editarElementoVista;
}

class editarElementoVista : public QDialog
{
    Q_OBJECT

public:
    QSpinBox* getSpinBox();
    void maximoElementos(int);
    explicit editarElementoVista(QWidget *parent = 0);
    ~editarElementoVista();
signals:
    void emitirInformacionElemento(int,QString,cambioElemento,int,int);
protected slots:
    virtual void setInformacionElemento(QString,tipoElemento,int,int);
    virtual void enviarInformacion();
    virtual void elimElemento();
    virtual void imagenCambiada();

private:
    Ui::editarElementoVista *ui;
};

#endif // EDITARELEMENTOVISTA_H
