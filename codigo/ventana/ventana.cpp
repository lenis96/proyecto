#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QGroupBox>

 
int main(int argc, char *argv[])
{
    QApplication aplicacion(argc, argv);
    QWidget ventana;
    QGroupBox box("nose",&ventana);
    QHBoxLayout layout(&ventana);
    ventana.setWindowTitle("nose");
    //ventana.resize(300,200);
    QLabel label1("primer programa",&ventana);
    QPushButton boton("no oprima",&ventana);
    QTextEdit texto("nose",&ventana);
    //boton.setIndent(0);
    //boton.setMargin(20);
    //label1.setIndent(100);
    layout.addWidget(&texto);
    layout.addWidget(&label1);
    layout.addWidget(&boton);
    //label1.setGeometry(0,0,10,40);
    box.setLayout(&layout);
    //entana.adjustSize();
    ventana.resize(1000,1500);
 
    ventana.show();
    return aplicacion.exec();
}