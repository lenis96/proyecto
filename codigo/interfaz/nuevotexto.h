#ifndef NUEVOTEXTO_H
#define NUEVOTEXTO_H

#include <QDialog>
#include <QString>

namespace Ui {
class nuevoTexto;
}

class nuevoTextoVentana : public QDialog
{
    Q_OBJECT

public:
    explicit nuevoTextoVentana(QWidget *parent = 0);
    ~nuevoTextoVentana();
signals:
    void emitirInformacionTexto(QString,int,int);

private:
    Ui::nuevoTexto *ui;
protected slots:
    virtual void enviarInformacion();
};

#endif // NUEVOTEXTO_H
