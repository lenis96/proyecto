#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
void MainWindow::nuevoConcepto(){
    formNc.show();
}
void MainWindow::unirConceptos(){
    QMessageBox msgBox;
    msgBox.setText("Uno dos conceptos");
    msgBox.exec();
}
void MainWindow::editarConcepto(){
    formEc.show();
}
void MainWindow::guardarArchivo(){
    QFileDialog cuadroArchivo;
    cuadroArchivo.setModal(true);
    cuadroArchivo.exec();
}
void MainWindow::guardarComoArchivo(){
    QFileDialog cuadroArchivo;
    cuadroArchivo.setModal(true);
    cuadroArchivo.exec();
}
void MainWindow::abrirArchivo(){
    QFileDialog cuadroArchivo;
    cuadroArchivo.setModal(true);
    cuadroArchivo.exec();
    cuadroArchivo.selectedFilter();
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
    //formNc.setParent(this);
    //formEc.setParent(this);
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(pressed()),this, SLOT(nuevoConcepto()));
    connect(ui->pushButton_2, SIGNAL(pressed()),this, SLOT(unirConceptos()));
    connect(ui->pushButton_3, SIGNAL(pressed()),this, SLOT(editarConcepto()));
    connect(ui->actionAbrir_Archivo, SIGNAL(triggered()),this, SLOT(abrirArchivo()));
    connect(ui->actionGuardar_Archivo, SIGNAL(triggered()),this, SLOT(guardarArchivo()));
    connect(ui->actionGuardar_Como, SIGNAL(triggered()),this, SLOT(guardarComoArchivo()));
    connect(ui->actionNuevo_Archivo, SIGNAL(triggered()),this, SLOT(nuevoArchivo()));
    connect(ui->pushButton_4,SIGNAL(pressed()),this,SLOT(iniciarPresentacion()));
    connect(ui->actionSalir,SIGNAL(triggered()),this,SLOT(close()));
}


MainWindow::~MainWindow()
{
    delete ui;
}


