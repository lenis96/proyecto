#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nuevoconceptoventana.h"
#include "editarconceptoventana.h"
#include "unirconceptosventana.h"
#include "mapa.h"
#include <QtGui>
#include <QList>
#include <QPair>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void dibujarMapa();
    void enlazarItems();
signals:
    void InformacionConcepto(QString,int,int);
    void InformacionConcepto1(QString,int,int);
    void InformacionConcepto2(QString,int,int);
protected slots:
    virtual void nuevoConcepto();
    virtual void unirConceptos();
    virtual void editarConcepto();
    virtual void guardarArchivo();
    virtual void guardarComoArchivo();
    virtual void abrirArchivo();
    virtual void nuevoArchivo();
    virtual void iniciarPresentacion();
    virtual void actualizar();
    virtual void nuevoConcepto(QString,int,int);
    virtual void idConceptoCambiado(int);
    virtual void ConceptoCambiado(int,QString,int,int,cambioConcepto);
    virtual void idConceptoCambiado1(int);
    virtual void idConceptoCambiado2(int);
    virtual void editarUnion(int,int,cambioUnion);

private:
    Ui::MainWindow *ui;
    nuevoConceptoVentana* formNc;
    editarConceptoVentana* formEc;
    unirConceptosVentana* formUc;
    QGraphicsScene *escena;
    mapa mapaC;
    QList <QPair<int,QGraphicsTextItem*> > conceptItems ;
    QString ubicacionArchivo;
    bool archivoGuardado;
};
int promedio(int,int);

#endif // MAINWINDOW_H
