#ifndef PRESENTACIONVISTA_H
#define PRESENTACIONVISTA_H

#include <QWidget>
#include <elementopresentacion.h>
#include <nuevotexto.h>
#include <nuevaimagenventana.h>
#include <editarelementovista.h>
namespace Ui {
class presentacionVista;
}

class presentacionVista : public QWidget
{
    Q_OBJECT

public:
    explicit presentacionVista(QWidget *parent = 0);
    ~presentacionVista();
    void maximoConceptos(int);
    void maximoElementos(int);
    QSpinBox* idConcepto();
    QSpinBox* idElemento();
    void ocultarElementos();
    void mostrarElementos();
signals:
    void emtirInformacionElem(int,QString,tipoElemento,int,int);
    void asignarInformacionElem(QString,tipoElemento,int,int);
    void ocultado();
    void emtirInformacionEdicionElem(int,int,QString,cambioElemento,int,int);

private:
    Ui::presentacionVista *ui;
    nuevoTextoVentana* formNt;
    nuevaImagenVentana* formNi;
    editarElementoVista* formEe;
protected slots:
    virtual void setInformacionConcepto(QString,int,int);
    virtual void enviarInformacionTexto(QString,int,int);
    virtual void enviarInformacionImagen(QString,int,int);
    virtual void setInformacionElemento(QString,tipoElemento,int,int);
    virtual void nuevaImagen();
    virtual void nuevoTexto();
    virtual void editarElemento();
    virtual void ocultar();
    virtual void enviarInformacionElemento(int,QString,cambioElemento,int,int);
};

#endif // PRESENTACIONVISTA_H
