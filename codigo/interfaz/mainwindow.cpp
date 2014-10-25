#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
void MainWindow::nuevoConcepto(){
    QMessageBox msgBox;
    msgBox.setText("Creo un nuevo Concepto");
    msgBox.exec();
}
void MainWindow::unirConceptos(){
    QMessageBox msgBox;
    msgBox.setText("Uno dos conceptos");
    msgBox.exec();
}
void MainWindow::editarConcepto(){
    QMessageBox msgBox;
    msgBox.setText("Edito un Concepto");
    msgBox.exec();
}
void MainWindow::guardarArchivo(){
    QMessageBox msgBox;
    msgBox.setText("Guardo el Archivo");
    msgBox.exec();
}
void MainWindow::guardarComoArchivo(){
    QMessageBox msgBox;
    msgBox.setText("Guardo un nuevo Archivo");
    msgBox.exec();
}
void MainWindow::abrirArchivo(){
    QMessageBox msgBox;
    msgBox.setText("Abro un Archivo");
    msgBox.exec();
}
void MainWindow::nuevoArchivo(){
    QMessageBox msgBox;
    msgBox.setText("Creo un nuevo Archivo");
    msgBox.exec();
}
void MainWindow::iniciarPresentacion(){
    QMessageBox msgBox;
    msgBox.setText("Comienza la presentación");
    msgBox.exec();
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(pressed()),this, SLOT(nuevoConcepto()));
    connect(ui->pushButton_2, SIGNAL(pressed()),this, SLOT(unirConceptos()));
    connect(ui->pushButton_3, SIGNAL(pressed()),this, SLOT(editarConcepto()));
    connect(ui->actionAbrir_Archivo, SIGNAL(triggered()),this, SLOT(abrirArchivo()));
    connect(ui->actionGuardar_Archivo, SIGNAL(triggered()),this, SLOT(guardarArchivo()));
    connect(ui->actionGuardar_Como, SIGNAL(triggered()),this, SLOT(guardarComoArchivo()));
    connect(ui->actionNuevo_Archivo, SIGNAL(triggered()),this, SLOT(nuevoArchivo()));
    connect(ui->pushButton_4,SIGNAL(pressed()),this,SLOT(iniciarPresentacion()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
