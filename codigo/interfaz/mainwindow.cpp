#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
void MainWindow::nuevoConcepto(){
    formNc->show();

}
void MainWindow::unirConceptos(){
    formUc->maximoConceptos(mapaC.getNumConceptos());
    formUc->show();
}
void MainWindow::editarConcepto(){
    formEc->maximoConceptos(mapaC.getNumConceptos());
    formEc->show();
}
void MainWindow::guardarArchivo(){
    if(ubicacionArchivo=="no hay"){
        this->guardarComoArchivo();
    }
    else{
        mapaC.guardar(ubicacionArchivo);
        archivoGuardado=true;
    }
}
void MainWindow::guardarComoArchivo(){
    QFileDialog cuadroArchivo;
    cuadroArchivo.setModal(true);
    cuadroArchivo.selectedFilter();
    ubicacionArchivo=cuadroArchivo.getSaveFileName();
    if(ubicacionArchivo==""){
        ubicacionArchivo="no hay";
    }
    mapaC.guardar(ubicacionArchivo);
    archivoGuardado=true;
}
void MainWindow::abrirArchivo(){
    QFileDialog cuadroArchivo;
    cuadroArchivo.setModal(true);
    cuadroArchivo.selectedFilter();
    ubicacionArchivo=cuadroArchivo.getOpenFileName();
    mapaC.abrir(ubicacionArchivo);
    if(mapaC.tieneError()){
        QMessageBox msgBox;
        msgBox.setText("Hay un error en el archivo");
        msgBox.exec();
    }
    else{
        //escena->addText(QString::fromStdString(mapaC.getConceptoNum(1).getTexto()));
        this->enlazarItems();
        //this->dibujarMapa();
    }
}
void MainWindow::nuevoArchivo(){
    if(!archivoGuardado){
        cuadroA->show();
        if(!cuadroA->cancelado){
            mapaC.~mapa();
        }
    }
    dibujarMapa();

}
void MainWindow::iniciarPresentacion(){
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    this->escena->clear();
    presVista->show();
    presVista->ocultarElementos();
    presVista->maximoConceptos(mapaC.getNumConceptos());
    vistaPresentacion=true;
    dibujarPresentacion(1);
    this->showFullScreen();
    ui->graphicsView->showFullScreen();
}
void MainWindow::iniciarModoPresentacion(){
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    this->escena->clear();
    presVista->show();
    presVista->maximoConceptos(mapaC.getNumConceptos());
    vistaPresentacion=true;
}

void MainWindow::actualizar(){
    //QList conceptos;
    QMutableListIterator <QPair<int,QGraphicsTextItem*> > i(conceptItems);
    i.toFront();
    //qDebug()<<i.hasNext();

    while(i.hasNext()){
        concepto c(mapaC.getConceptoNum(i.peekNext().first).getTexto(),i.peekNext().second->x(),i.peekNext().second->y());
        mapaC.setConcepto(i.peekNext().first,c);
        /*
        //qDebug()<<mapaC.getConceptoNum(i.peekNext().first).getPosY();
        //i.peekNext().first.peekNext().second->x());
        qDebug()<<"i: "<<i.peekNext().first;
        qDebug()<<"->y "<<i.peekNext().second->y();
        qDebug()<<"old y "<<mapaC.getConceptoNum(i.peekNext().first).getPosY();
        //mapaC.getConceptoNum(i.peekNext().first).setPosX(130);
        mapaC.getConceptoNum(i.peekNext().first).setPosY(i.peekNext().second->y());
        qDebug()<<"new y "<<mapaC.getConceptoNum(i.peekNext().first).getPosY();
        //i.peekNext().first.setPosY(i.peekNext().second->y());
        */
        i.next();
    }
    this->dibujarMapa();
}
void MainWindow::enlazarItems(){
    //mapaC.imprimirConceptos();
    conceptItems.clear();
    for(int i=1;i<=mapaC.getNumConceptos();i++){
        if(mapaC.existeConcepto(i)){
            QGraphicsTextItem *texto=new QGraphicsTextItem(QString::fromStdString(mapaC.getConceptoNum(i).getTexto()));
            //qDebug()<<"---------"<<mapaC.getConceptoNum(i).getPosX()<<"--"<<mapaC.getConceptoNum(i).getPosY();
            texto->setPos(mapaC.getConceptoNum(i).getPosX(),mapaC.getConceptoNum(i).getPosY());
            texto->setFlag(QGraphicsItem::ItemIsMovable);

            texto->setTextInteractionFlags(Qt::TextEditorInteraction);
            conceptItems.append(QPair<int,QGraphicsTextItem*> (i,texto));
        }
    }
    this->dibujarMapa();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //formNc.setParent(this);
    //formEc.setParent(this);
    ui->setupUi(this);
    ubicacionArchivo="no hay";
    archivoGuardado=true;
    vistaPresentacion=false;
    formNc=new nuevoConceptoVentana(this);
    formEc=new editarConceptoVentana(this);
    formUc=new unirConceptosVentana(this);
    presVista=new presentacionVista(this);
    cuadroA=new CuadroArchivo(this);
    presVista->hide();
    formUc->move(this->width()*0.05,50);
    formNc->move(this->width()*0.05,50);
    formEc->move(this->width()*0.05,50);
    connect(ui->pushButton, SIGNAL(pressed()),this, SLOT(nuevoConcepto()));
    connect(ui->pushButton_2, SIGNAL(pressed()),this, SLOT(unirConceptos()));
    //connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(actualizar()));
    connect(cuadroA,SIGNAL(emitirSi()),this,SLOT(guardarArchivo()));
    connect(ui->actionExportar,SIGNAL(triggered()),this,SLOT(exportar()));
    connect(ui->pushButton_3, SIGNAL(pressed()),this, SLOT(editarConcepto()));
    connect(ui->actionAbrir_Archivo, SIGNAL(triggered()),this, SLOT(abrirArchivo()));
    connect(ui->actionGuardar_Archivo, SIGNAL(triggered()),this, SLOT(guardarArchivo()));
    connect(ui->actionGuardar_Como, SIGNAL(triggered()),this, SLOT(guardarComoArchivo()));
    connect(ui->actionNuevo_Archivo, SIGNAL(triggered()),this, SLOT(nuevoArchivo()));
    connect(ui->pushButton_4,SIGNAL(pressed()),this,SLOT(iniciarPresentacion()));
    connect(ui->actionSalir,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->pushButton_5,SIGNAL(pressed()),this,SLOT(iniciarModoPresentacion()));
    connect(formNc,SIGNAL(emitirInformacionConcepto(QString,int,int)),this,SLOT(nuevoConcepto(QString,int,int)));
    connect(formEc->idConcepto(),SIGNAL(valueChanged(int)),this,SLOT(idConceptoCambiado(int)));
    connect(this,SIGNAL(InformacionConcepto(QString,int,int)),formEc,SLOT(setInformacionConcepto(QString,int,int)));
    connect(formEc,SIGNAL(emitirInformacionConcepto(int,QString,int,int,cambioConcepto)),this,SLOT(ConceptoCambiado(int,QString,int,int,cambioConcepto)));
    connect(formUc->id1Concepto(),SIGNAL(valueChanged(int)),this,SLOT(idConceptoCambiado1(int)));
    connect(this,SIGNAL(InformacionConcepto1(QString,int,int)),formUc,SLOT(setInformacionConcepto1(QString,int,int)));
    connect(formUc->id2Concepto(),SIGNAL(valueChanged(int)),this,SLOT(idConceptoCambiado2(int)));
    connect(this,SIGNAL(InformacionConcepto2(QString,int,int)),formUc,SLOT(setInformacionConcepto2(QString,int,int)));
    connect(formUc,SIGNAL(emitirInformacion(int,int,cambioUnion)),this,SLOT(editarUnion(int,int,cambioUnion)));
    connect(presVista->idConcepto(),SIGNAL(valueChanged(int)),this,SLOT(idConceptoCambiado1(int)));
    connect(this,SIGNAL(InformacionConcepto1(QString,int,int)),presVista,SLOT(setInformacionConcepto(QString,int,int)));
    connect(presVista,SIGNAL(ocultado()),this,SLOT(mostraVistaMapaConceptual()));
    connect(presVista,SIGNAL(emtirInformacionElem(int,QString,tipoElemento,int,int)),this,SLOT(crearElementoTexto(int,QString,tipoElemento,int,int)));
    connect(presVista,SIGNAL(emtirInformacionElem(int,QString,tipoElemento,int,int)),this,SLOT(crearElementoImagen(int,QString,tipoElemento,int,int)));
    connect(presVista->idElemento(),SIGNAL(valueChanged(int)),this,SLOT(idElementoCambiado(int)));
    connect(this,SIGNAL(InformacionElemento(QString,tipoElemento,int,int)),presVista,SLOT(setInformacionElemento(QString,tipoElemento,int,int)));
    connect(presVista,SIGNAL(emtirInformacionEdicionElem(int,int,QString,cambioElemento,int,int)),this,SLOT(hacerEdicionElemento(int,int,QString,cambioElemento,int,int)));

    //connect(escena,SIGNAL(changed()),this,SLOT(actualizar()));
    escena=new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);

    //conceptItems();
}
void MainWindow::idElementoCambiado(int id){
    if(mapaC.existeConcepto(presVista->idConcepto()->value())){
        concepto c=mapaC.getConceptoNum(presVista->idConcepto()->value());
        elementoPresentacion* ptrE= c.getPtrElem(id);
        if(ptrE!=NULL && ptrE->getTipo()==texto){
            QGraphicsTextItem* t=(QGraphicsTextItem*)ptrE->getElem();
            emit InformacionElemento(t->toPlainText(),texto,t->x(),t->y());
        }
        else if(ptrE!=NULL && ptrE->getTipo()==imagen){
            QGraphicsPixmapItem* i=(QGraphicsPixmapItem*)ptrE->getElem();
            emit InformacionElemento(ptrE->getCadena(),imagen,i->x(),i->y());
        }
        else{
            emit InformacionElemento("<no exsiste este elemento>",nulo,0,0);
        }
    }
}

void MainWindow::hacerEdicionElemento(int idC, int idE, QString cadena, cambioElemento tipo, int x, int y){
    if(tipo==cambiarElemento){
        concepto* c=mapaC.getPtrNum(idC);
        if(c!=NULL){
               elementoPresentacion* e=c->getPtrElem(idE);
               e->setInformacion(cadena,x,y);
        }
    }
    else if(tipo==eliminarElemento){
        concepto* c=mapaC.getPtrNum(idC);
        if(c!=NULL){
            c->eliminarElemento(idE);
        }
    }
    this->dibujarPresentacion(idC);
}

void MainWindow::nuevoConcepto(QString texto,int x,int y){
    concepto c(texto.toStdString(),x,y);
    this->mapaC.agregarConcepto(c);
    this->dibujarMapa();
    archivoGuardado=false;
}
void MainWindow::centrarEscena(){
    escena->setSceneRect(-2000,-2000,4000,4000);
    ui->graphicsView->centerOn(0,0);
    //escena->setSceneRect(-5000,-5000,200,5000);
    //esce4
}

void MainWindow::idConceptoCambiado(int a){
    if(mapaC.existeConcepto(a)){
        concepto c(mapaC.getConceptoNum(a));
        emit InformacionConcepto(QString::fromStdString(c.getTexto()),c.getPosX(),c.getPosY());

    }
    else{
        emit InformacionConcepto("<no hay concepto>",0,0);

    }
}

void MainWindow::idConceptoCambiado1(int a){
    if(mapaC.existeConcepto(a)){
        concepto c(mapaC.getConceptoNum(a));
        emit InformacionConcepto1(QString::fromStdString(c.getTexto()),c.getPosX(),c.getPosY());
        if(vistaPresentacion){
            dibujarPresentacion(a);
        }
        presVista->maximoElementos(mapaC.getConceptoNum(a).getNumElementos());
    }
    else{
        emit InformacionConcepto1("<no hay concepto>",0,0);
        if(vistaPresentacion){
            escena->clear();
        }
        presVista->maximoElementos(0);
    }
}

void MainWindow::idConceptoCambiado2(int a){
    if(mapaC.existeConcepto(a)){
        concepto c(mapaC.getConceptoNum(a));
        emit InformacionConcepto2(QString::fromStdString(c.getTexto()),c.getPosX(),c.getPosY());
    }
    else{
        emit InformacionConcepto2("<no hay concepto>",0,0);
    }
}
void MainWindow::editarUnion(int n1,int n2,cambioUnion tipo){
    if(tipo==crearUnion && n1!=n2){
        mapaC.agregarUnion(n1,n2);
    }
    else if(tipo==eliminarUnion && n1!=n2 && mapaC.existeUnion(n1,n2)){
        mapaC.eliminarUnion(n1,n2);
    }
    this->dibujarMapa();
}
void MainWindow::ConceptoCambiado(int id,QString texto,int x,int y,cambioConcepto tipo){
    if(mapaC.existeConcepto(id) && tipo==cambiarConcepto){
        concepto c(texto.toStdString(),x,y);
        mapaC.setConcepto(id,c);
        archivoGuardado=false;
    }
    else if (mapaC.existeConcepto(id) && tipo==eliminarConcepto){
        mapaC.eliminarConcepto(id);
    }
    else{
        //concepto c(texto.toStdString(),x,y,id);
        //mapaC.cargarConcepto(c);
    }
    this->dibujarMapa();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dibujarMapa(){
    escena->clear();
    for(int i=1;i<=mapaC.getNumConceptos();i++){
        for(int j=1;j<i;j++){
            if(mapaC.existeUnion(i,j)){

                QGraphicsTextItem *texto1=new QGraphicsTextItem(QString::fromStdString(mapaC.getConceptoNum(i).getTexto()));
                texto1->setPos(mapaC.getConceptoNum(i).getPosX(),mapaC.getConceptoNum(i).getPosY()*-1);
                QGraphicsTextItem *texto2=new QGraphicsTextItem(QString::fromStdString(mapaC.getConceptoNum(j).getTexto()));
                texto2->setPos(mapaC.getConceptoNum(j).getPosX(),mapaC.getConceptoNum(j).getPosY()*-1);
                int promedioX1=promedio(texto1->x(),texto1->x()+texto1->document()->size().width());
                int promedioY1=promedio(texto1->y(),texto1->y()+texto1->document()->size().height());
                int promedioX2=promedio(texto2->x(),texto2->x()+texto2->document()->size().width());
                int promedioY2=promedio(texto2->y(),texto2->y()+texto2->document()->size().height());
                QGraphicsLineItem *linea=new QGraphicsLineItem(promedioX1,promedioY1,promedioX2,promedioY2);
                //qDebug()<<promedioX1;
                //QGraphicsLineItem *linea=new QGraphicsLineItem(mapaC.getConceptoNum(i).getPosX(),mapaC.getConceptoNum(i).getPosY(),mapaC.getConceptoNum(j).getPosX(),mapaC.getConceptoNum(j).getPosY());
                escena->addItem(linea);
            }
        }
    }
    //QListIterator <QPair<int,QGraphicsTextItem*> > i(conceptItems);
    for(int i=1;i<=mapaC.getNumConceptos();i++){
        if(mapaC.existeConcepto(i)){
            //QGraphicsTextItem* texto=i.peekNext().second;
            QGraphicsTextItem *texto=new QGraphicsTextItem(QString::fromStdString(mapaC.getConceptoNum(i).getTexto()));
            //qDebug()<<"---------"<<mapaC.getConceptoNum(i).getPosX()<<"--"<<mapaC.getConceptoNum(i).getPosY();
            texto->setPos(mapaC.getConceptoNum(i).getPosX(),mapaC.getConceptoNum(i).getPosY()*-1);
            //texto->setFlag(QGraphicsItem::ItemIsMovable);
            //texto->setTextInteractionFlags(Qt::TextEditorInteraction);
            QGraphicsEllipseItem *elipse=new QGraphicsEllipseItem(texto->x(),texto->y(),texto->document()->size().width(),texto->document()->size().height());
            QGraphicsItemGroup *c=new QGraphicsItemGroup();
            elipse->setBrush(QColor::fromRgb(180,190,230));
            c->addToGroup(elipse);
            c->addToGroup(texto);
            //c->setFlag(QGraphicsItem::ItemIsMovable);
            //c->setHandlesChildEvents(false);
            escena->addItem(c);
            //qDebug()<<"fin concepto";
            //i.next();
        }
    }
    this->centrarEscena();
    /*
    for(int i=1;i<=mapaC.getNumConceptos();i++){
        if(mapaC.existeConcepto(i)){

            //connect(escena,SIGNAL(selectionChanged()),this,SLOT(actualizar()));
            //connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(actualizar()));
            //c->setFlags(Qt::TextEditorInteraction);
            escena->addItem(c);
            //conceptItems.append(QPair<concepto,QGraphicsItemGroup*> (mapaC.getConceptoNum(i),c));
            //escena->1
            //connect(texto,SIGNAL(Changed()x),this,SLOT(editarConcepto()));
        }
    }*/
    //QString fileName = "/home/lenis96/Escritorio/nose.png";
    //QPixmap pixMap = QPixmap::grabWidget(ui->graphicsView);
    //pixMap.save(fileName);
}
void MainWindow::mostraVistaMapaConceptual(){
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    vistaPresentacion=false;
    escena->clear();
    dibujarMapa();
    this->showMaximized();
}

void MainWindow::crearElementoTexto(int id, QString text, tipoElemento tipo, int x, int y){
    if(mapaC.existeConcepto(id) && tipo==texto){
        concepto* c=mapaC.getPtrNum(id);
        c->crearElementoTexto(text,x,y);
        dibujarPresentacion(id);
    }

}
void MainWindow::crearElementoImagen(int id, QString ubicacion, tipoElemento tipo, int x, int y){
    if(mapaC.existeConcepto(id) && tipo==imagen){
        concepto* c=mapaC.getPtrNum(id);
        c->crearElementoImagen(ubicacion,x,y);
        dibujarPresentacion(id);
    }
    //dibujarPresentacion(id);
}

void MainWindow::dibujarPresentacion(int num){
    concepto c=mapaC.getConceptoNum(num);
    elementoPresentacion* e;
    escena->clear();
    for(int i=1;i<=c.getNumElementos();i++){

        if(c.existeElemento(i)){
            e=c.getPtrElem(i);
            if(e!=NULL && e->getTipo()==texto){
                QGraphicsTextItem* elem=(QGraphicsTextItem*)e->getElem();
                QGraphicsTextItem* elem1=new QGraphicsTextItem(elem->toPlainText());
                elem1->setX(elem->x());
                elem1->setY(elem->y()*-1);
                escena->addItem(elem1);
            }
            else if(e!=NULL && e->getTipo()==imagen){
                QGraphicsPixmapItem* elem=(QGraphicsPixmapItem*)e->getElem();
                QGraphicsPixmapItem* elem1=new QGraphicsPixmapItem(elem->pixmap());
                elem1->setX(elem->x());
                elem1->setY(elem->y());
                escena->addItem(elem1);
            }
        }
    }
    this->centrarEscena();
}
void MainWindow::exportar(){
    this->dibujarMapa();
    QString ubicacion;
    QFileDialog cuadroArchivo;
    cuadroArchivo.setModal(true);
    cuadroArchivo.selectedFilter();
    ubicacion=cuadroArchivo.getSaveFileName();
    QPixmap pixMap = QPixmap::grabWidget(ui->graphicsView);
    pixMap.save(ubicacion);
}

int promedio(int a,int b){
    return (a+b)/2;
}
