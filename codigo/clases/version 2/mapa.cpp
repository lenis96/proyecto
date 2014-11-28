#include "mapa.h"
mapa::mapa()
{
    Error=false;
    numConceptos=0;
}
mapa::mapa(QString ubicacionArchivo){
    QFile archivo(ubicacionArchivo);
    if(archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&archivo);
        qDebug("abrio archivo");
        QString texto;
        texto.append(in.readAll());
        archivo.flush();
        archivo.close();
        QXmlStreamReader lector(texto);
        while(!lector.atEnd() && !lector.hasError()){
            if(lector.isStartElement()){
                QString tipo=lector.name().toString();
                if(tipo=="numConceptos"){
                    numConceptos=lector.readElementText().toInt();
                }
                else if(tipo=="concepto"){
                    concepto c;
                    bool conceptoTerminado=false;
                    while(!conceptoTerminado && !lector.hasError()){
                        if(lector.isStartElement()){
                            QString atributo=lector.name().toString();
                            if(atributo=="texto"){
                                c.textConcepto=lector.readElementText().toStdString();
                            }
                            else if(atributo=="posX"){
                                c.posX=lector.readElementText().toInt();
                            }
                            else if(atributo=="posY"){
                                c.posY=lector.readElementText().toInt();
                            }
                            else if(atributo=="numConcepto"){
                                c.numConcepto=lector.readElementText().toInt();
                                conceptoTerminado=true;
                                this->cargarConcepto(c);
                            }
                        }
                        lector.readNext();
                    }
                }
                else if(tipo=="pareja"){
                    qDebug()<<"inicio pareja";
                    int c1;
                    int c2;
                    bool parejaTerminada=false;
                    while(!parejaTerminada && !lector.hasError()){
                        if(lector.isStartElement()){
                            QString atributo=lector.name().toString();
                            if(atributo=="par1"){
                                c1=lector.readElementText().toInt();
                            }
                            else if(atributo=="par2"){
                                c2=lector.readElementText().toInt();
                                parejaTerminada=true;
                                this->agregarUnion(c1,c2);
                            }
                        }
                    lector.readNext();
                    }
                }
            }
            lector.readNext();
        }
        Error=false;
    }
    else{
        Error=true;
    }
}

void mapa::agregarConcepto(concepto concep){
    numConceptos++;
    listaConceptos.push_back(concepto(concep.getTexto(),concep.getPosX(),concep.getPosY(),numConceptos));
}
bool mapa::tieneError() const{return Error;}
void mapa::agregarUnion(concepto c1,concepto c2){
    if(!existeUnion(c1,c2)){
        //QPair<concepto,concepto> a(c1,c2);
        listaParejas.append(QPair <concepto,concepto>(c1,c2));
        //listaParejas.append(QPair(c1,c2));
    }
}
void mapa::agregarUnion(int n1,int n2){
    if(!existeUnion(this->getConceptoNum(n1),this->getConceptoNum(n2))){
        //QPair<concepto,concepto> a(this->conceptoPos(n1),this->conceptoPos(n2));
        listaParejas.append(QPair<concepto,concepto>(this->getConceptoNum(n1),this->getConceptoNum((n2))));
    }
}
int mapa::getNumConceptos() const{return numConceptos;}

mapa::~mapa(){
    listaConceptos.clear();
    listaParejas.clear();
    numConceptos=0;
}
void mapa::imprimirConceptos()const{
    QListIterator <concepto> i(listaConceptos);
    i.toFront();
    while(i.hasNext()){
        imprimirConcepto(i.peekNext());
        i.next();
    }
}
void mapa::imprimirUniones()const{
    QListIterator <QPair<concepto,concepto> > i(listaParejas);
    i.toFront();
    while(i.hasNext()){
        std::cout<<i.peekNext().first.getNumConcepto()<<"<--->"<<i.peekNext().second.getNumConcepto()<<"\n";
        i.next();
    }
}
concepto mapa::getConceptoNum(int num)const{
    QListIterator <concepto> i(listaConceptos);
    i.toFront();
    //iteradorConceptos=listaConceptos.begin();
    while(i.hasNext() && i.peekNext().getNumConcepto()!=num){//iteradorConceptos->getNumConcepto()!=num){
        i.next();
    }

    if(i.peekNext().getNumConcepto()==num){
        return i.peekNext();
    }
    else{
        return concepto ("nulo",0,0);
    }
}
bool mapa::existeUnion(concepto c1,concepto c2) const{
    QListIterator <QPair<concepto,concepto> > i(listaParejas);
    i.toFront();
    while(i.hasNext()){
        if((i.peekNext().first.getNumConcepto()==c1.getNumConcepto() && i.peekNext().second.getNumConcepto()==c2.getNumConcepto())||(i.peekNext().first.getNumConcepto()==c2.getNumConcepto() && i.peekNext().second.getNumConcepto()==c1.getNumConcepto())){
            return true;
        }
        i.next();
    }
    return false;
    //return listaParejas.contains(a)||listaParejas.contains(b);//existeUnion(c1.getNumConcepto(),c2.getNumConcepto());
}
/*
bool mapa::existeUnion(int num1,int num2){
    iteradorParejas=listaParejas.begin();
    while(iteradorParejas!=listaParejas.end()){
        if(((iteradorParejas->getPareja1()==num1 && iteradorParejas->getPareja2()==num2)||(iteradorParejas->getPareja1()==num2 && iteradorParejas->getPareja2()==num1))){
            return true;
        }
        iteradorParejas++;
    }
    return false;
}*/
bool mapa::existeConcepto(concepto co) const{//validate concepto nulo //imprimir Parejas
    return existeConcepto(co.getNumConcepto());
}
bool mapa::existeConcepto(int num) const{
    QListIterator <concepto> i(listaConceptos);
    i.toFront();
    while(i.hasNext()){
        if(i.peekNext().getNumConcepto()==num){
            return true;
        }

        i.next();

    }
    return false;
}
void mapa::guardar(QString ubicacionArchivo) const{
    QFile archivo(ubicacionArchivo);
    QString texto;
    QXmlStreamWriter escritor(&texto);
    QListIterator <concepto> i(listaConceptos);
    QListIterator <QPair<concepto,concepto> > j(listaParejas);
    escritor.setAutoFormatting(true);
    escritor.writeStartDocument();
    escritor.writeStartElement("mapa");
    escritor.writeTextElement("numConceptos",QString::number(this->numConceptos));
    escritor.writeStartElement("conceptos");
    i.toFront();
    while(i.hasNext()){
        escritor.writeStartElement("concepto");
        escritor.writeTextElement("texto",QString::fromStdString(i.peekNext().getTexto()));
        escritor.writeTextElement("posX",QString::number(i.peekNext().getPosX()));
        escritor.writeTextElement("posY",QString::number(i.peekNext().getPosY()));
        escritor.writeTextElement("numConcepto",QString::number(i.peekNext().getNumConcepto()));
        escritor.writeEndElement();
        i.next();
    }
    escritor.writeEndElement();
    j.toFront();
    escritor.writeStartElement("parejas");
    while(j.hasNext()){
        escritor.writeStartElement("pareja");
        escritor.writeTextElement("par1",QString::number(j.peekNext().first.getNumConcepto()));
        escritor.writeTextElement("par2",QString::number(j.peekNext().second.getNumConcepto()));
        escritor.writeEndElement();
        j.next();
    }
    escritor.writeEndElement();
    escritor.writeEndElement();
    escritor.writeEndDocument();
    if(!archivo.open(QFile::WriteOnly|QFile::Text)){
        qDebug()<<"no se pudo abrir el archivo"<<endl;
    }
    QTextStream out(&archivo);
    out<<texto;
    archivo.flush();
    archivo.close();
}
void mapa::eliminarConcepto(concepto c){
    QMutableListIterator <concepto> i (listaConceptos);
    QMutableListIterator <QPair <concepto,concepto> > j(listaParejas);
    j.toFront();
    while(j.hasNext()){
        if(j.peekNext().first.getNumConcepto()==c.getNumConcepto() || j.peekNext().second.getNumConcepto()==c.getNumConcepto()){
            j.next();
            j.remove();
        }
        else{
            j.next();
        }
    }
    i.toFront();
    while(i.hasNext()){
        if(i.peekNext().getNumConcepto()==c.getNumConcepto()){
            i.next();
            i.remove();
            qDebug()<<"va a borrar";
        }
        else{
            i.next();
        }
    }
}
void mapa::cargarConcepto(concepto c){
    listaConceptos.push_back(c);
}

void mapa::eliminarUnion(concepto c1, concepto c2){
    QMutableListIterator <QPair<concepto,concepto> > i(listaParejas);
    i.toFront();
    while(i.hasNext()){
        if((i.peekNext().first.getNumConcepto()==c1.getNumConcepto() && i.peekNext().second.getNumConcepto()==c2.getNumConcepto()) || (i.peekNext().first.getNumConcepto()==c2.getNumConcepto() && i.peekNext().second.getNumConcepto()==c1.getNumConcepto())){
            i.next();
            i.remove();
        }
        else{
            i.next();
        }
    }
}
