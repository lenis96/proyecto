#ifndef CUADROARCHIVO_H
#define CUADROARCHIVO_H

#include <QDialog>

namespace Ui {
class CuadroArchivo;
}

class CuadroArchivo : public QDialog
{
    Q_OBJECT

public:
    explicit CuadroArchivo(QWidget *parent = 0);
    ~CuadroArchivo();
    bool cancelado;
signals:
    void emitirSi();
    void emitirNo();
    void emitirCalncelar();

private:
    Ui::CuadroArchivo *ui;
protected slots:
    virtual void enviarSi();
    virtual void enviarNo();
    virtual void enviarCancelar();
};

#endif // CUADROARCHIVO_H
