#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nuevoconceptoventana.h"
#include "editarconceptoventana.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected slots:
    virtual void nuevoConcepto();
    virtual void unirConceptos();
    virtual void editarConcepto();
    virtual void guardarArchivo();
    virtual void guardarComoArchivo();
    virtual void abrirArchivo();
    virtual void nuevoArchivo();
    virtual void iniciarPresentacion();

private:
    Ui::MainWindow *ui;
    nuevoConceptoVentana formNc;
    editarConceptoVentana formEc;
};

#endif // MAINWINDOW_H
