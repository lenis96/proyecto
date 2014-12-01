#include "mapa.h"
mapa::mapa()
{
    Error=false;
    numConceptos=0;
}
mapa::mapa(QString ubicacionArchivo){
    abrir(ubicacionArchivo);
}

void mapa::abrir(QString ubicacionArchivo){
    this->~mapa();
    QFile archivo(ubicacionArchivo);
    if(archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&archivo);
        QString text;
        text.append(in.readAll());
        archivo.flush();
        archivo.close();
        QXmlStreamReader lector(text);
        while(!lector.atEnd() && !lector.hasError()){
            if(lector.isStartElement()){
                QString tipo=lector.name().toString();
                if(tipo=="numConceptos"){
                    numConceptos=lector.readElementText().toInt();
                }
                else if(tipo=="concepto"){
                    concepto c;
                    bool conceptoTerminado=false;
                    QString tipo,cadena;
                    int x,y,id;
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

                            }
                            else if(atributo=="numElementos"){
                                c.numElemtos=lector.readElementText().toInt();
                                if(c.numElemtos==0){
                                    conceptoTerminado=true;
                                    this->cargarConcepto(c);
                                }
                            }
                            else if(atributo=="tipo"){
                                tipo=QString::fromStdString(lector.readElementText().toStdString());
                            }
                            else if(atributo=="cadena"){
                                cadena=QString::fromStdString(lector.readElementText().toStdString());
                            }
                            else if(atributo=="x"){
                                x=lector.readElementText().toInt();
                            }
                            else if(atributo=="y"){
                                y=lector.readElementText().toInt();
                            }
                            else if(atributo=="id"){
                                id=lector.readElementText().toInt();
                                if(tipo=="texto"){
                                    c.elementos.append(elementoPresentacion(texto,cadena,x,y,id));
                                }
                                else if(tipo=="imagen"){
                                    c.elementos.append(elementoPresentacion(imagen,cadena,x,y,id));
                                }
                            }
                            else if(atributo=="finConcepto"){
                                conceptoTerminado=true;
                                this->cargarConcepto(c);
                            }/*
                            if(lector.isEndElement()){
                                qDebug()<<lector.name().toString();
                                if(lector.name().toString()=="concepto"){
                                    qDebug()<<"hola";

                                }
                            }*/

                        }
                        lector.readNext();
                    }
                }
                else if(tipo=="pareja"){
                    int n[2]={0,0};
                    bool parejaTerminada=false;
                    while(!parejaTerminada && !lector.hasError()){
                        if(lector.isStartElement()){
                            QString atributo=lector.name().toString();
                            if(atributo=="par1"){
                                n[0]=lector.readElementText().toInt();
                            }
                            else if(atributo=="par2"){
                                n[1]=lector.readElementText().toInt();
                                parejaTerminada=true;
                                this->agregarUnion(n[0],n[1]);
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
    if(!existeUnion(c1,c2) && c1.getNumConcepto()!=c2.getNumConcepto()){
        //QPair<concepto,concepto> a(c1,c2);
        listaParejas.append(QPair <concepto*,concepto*>(&c1,&c2));
        //listaParejas.append(QPair(c1,c2));
    }
}
concepto* mapa::getPtrNum(int num){
    QMutableListIterator <concepto> i(listaConceptos);
    i.toFront();
    //iteradorConceptos=listaConceptos.begin();
    while(i.hasNext() && i.peekNext().getNumConcepto()!=num){//iteradorConceptos->getNumConcepto()!=num){
        i.next();
    }

    if(i.peekNext().getNumConcepto()==num){
        return &i.peekNext();
    }
    else{
        return NULL;
    }
}
void mapa::agregarUnion(int n1,int n2){
        //QPair<concepto,concepto> a(this->conceptoPos(n1),this->conceptoPos(n2));
    listaParejas.append(QPair<concepto*,concepto*>(this->getPtrNum(n1),this->getPtrNum(n2)));
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
    QListIterator <QPair<concepto*,concepto*> > i(listaParejas);
    i.toFront();
    while(i.hasNext()){
        std::cout<<i.peekNext().first->getNumConcepto()<<"<--->"<<i.peekNext().second->getNumConcepto()<<"\n";
        i.next();
    }
}


concepto mapa::getConceptoNum(int num)const{
    QListIterator <concepto> i(listaConceptos);
    i.toFront();
    //iteradorConceptos=listaConceptos.begin();
    while(i.hasNext()){//iteradorConceptos->getNumConcepto()!=num){
        if(i.peekNext().getNumConcepto()==num){
            return i.peekNext();
        }
        i.next();
    }
/*
    if(i.hasNext() && i.peekNext().getNumConcepto()==num ){
        return i.peekNext();
    }*/
        return concepto ("nulo",0,0);
}
void mapa::setConcepto(int num,concepto c){
    QMutableListIterator <concepto> i(listaConceptos);
    i.toFront();
    while(i.hasNext() && i.peekNext().getNumConcepto()!=num){
        i.next();
    }
    if(i.peekNext().getNumConcepto()==num){
        i.peekNext()=c;
        i.peekNext().setNumConcepto(num);
    }
}

bool mapa::existeUnion(concepto c1,concepto c2) const{
    if(existeConcepto(c1) && existeConcepto(c2)){
        QListIterator <QPair<concepto*,concepto*> > i(listaParejas);
        i.toFront();
        while(i.hasNext()){
            if((i.peekNext().first->getNumConcepto()==c1.getNumConcepto() && i.peekNext().second->getNumConcepto()==c2.getNumConcepto())||(i.peekNext().first->getNumConcepto()==c2.getNumConcepto() && i.peekNext().second->getNumConcepto()==c1.getNumConcepto())){
                return true;
            }
            i.next();
        }
        return false;
        //return listaParejas.contains(a)||listaParejas.contains(b);//existeUnion(c1.getNumConcepto(),c2.getNumConcepto());
    }
    else{
        return false;
    }
}
bool mapa::existeUnion(int n1,int n2)const{
    return existeUnion(this->getConceptoNum(n1),this->getConceptoNum(n2));
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
void mapa::guardar(QString ubicacionArchivo) {
    QFile archivo(ubicacionArchivo);
    QString text;
    QXmlStreamWriter escritor(&text);
    QMutableListIterator <concepto> i(listaConceptos);
    QListIterator <QPair<concepto*,concepto*> > j(listaParejas);
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
        escritor.writeTextElement("numElementos",QString::number(i.peekNext().getNumElementos()));
        for(int j=1;j<=i.peekNext().getNumElementos();j++){
            if(i.peekNext().existeElemento(j)){
                elementoPresentacion e=i.peekNext().getElemNum(j);
                escritor.writeStartElement("elemento");
                if(e.getTipo()==texto){
                    escritor.writeTextElement("tipo","texto");
                }
                else if(e.getTipo()==imagen){
                    escritor.writeTextElement("tipo","imagen");
                }
                escritor.writeTextElement("cadena",e.getCadena());
                escritor.writeTextElement("x",QString::number(e.getX()));
                escritor.writeTextElement("y",QString::number(e.getY()));
                escritor.writeTextElement("id",QString::number(e.getId()));
                escritor.writeEndElement();
            }

        }
        escritor.writeTextElement("finConcepto","fin concepto");
        escritor.writeEndElement();
        i.next();
    }
    escritor.writeEndElement();
    j.toFront();
    escritor.writeStartElement("parejas");
    while(j.hasNext()){
        escritor.writeStartElement("pareja");
        escritor.writeTextElement("par1",QString::number(j.peekNext().first->getNumConcepto()));
        escritor.writeTextElement("par2",QString::number(j.peekNext().second->getNumConcepto()));
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
    out<<text;
    archivo.flush();
    archivo.close();
}
void mapa::eliminarConcepto(concepto c){
    QMutableListIterator <concepto> i (listaConceptos);
    QMutableListIterator <QPair <concepto*,concepto*> > j(listaParejas);
    j.toFront();
    while(j.hasNext()){
        if(j.peekNext().first->getNumConcepto()==c.getNumConcepto() || j.peekNext().second->getNumConcepto()==c.getNumConcepto()){
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
            break;
        }
        else{
            i.next();
        }
    }
}
void mapa::eliminarConcepto(int num){
    concepto c(getConceptoNum(num));
    eliminarConcepto(c);
}

void mapa::cargarConcepto(concepto c){
    listaConceptos.push_back(c);
}

void mapa::eliminarUnion(concepto c1, concepto c2){
    QMutableListIterator <QPair<concepto*,concepto*> > i(listaParejas);
    i.toFront();
    while(i.hasNext()){
        if((i.peekNext().first->getNumConcepto()==c1.getNumConcepto() && i.peekNext().second->getNumConcepto()==c2.getNumConcepto()) || (i.peekNext().first->getNumConcepto()==c2.getNumConcepto() && i.peekNext().second->getNumConcepto()==c1.getNumConcepto())){
            i.next();
            i.remove();
        }
        else{
            i.next();
        }
    }
}
void mapa::eliminarUnion(int n1,int n2){
    concepto c1(this->getConceptoNum(n1));
    concepto c2(this->getConceptoNum(n2));
    this->eliminarUnion(c1,c2);
}
