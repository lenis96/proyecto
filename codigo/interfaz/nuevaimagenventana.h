#ifndef NUEVAIMAGENVENTANA_H
#define NUEVAIMAGENVENTANA_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class nuevaImagenVentana;
}

class nuevaImagenVentana : public QDialog
{
    Q_OBJECT

public:
    explicit nuevaImagenVentana(QWidget *parent = 0);
    ~nuevaImagenVentana();
    bool pedirImagen();
signals:
    void emitirInformacionImagen(QString,int,int);

private:
    Ui::nuevaImagenVentana *ui;
protected slots:
    void enviarInformacion();
};

#endif // NUEVAIMAGENVENTANA_H
