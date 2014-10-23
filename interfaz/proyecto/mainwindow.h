#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
