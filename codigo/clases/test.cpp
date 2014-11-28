#include <QtTest>
#include <QtCore>
#include "concepto.h"
#include <iostream>
#include "mapa.h"

 
class testPrograma: public QObject
{
    Q_OBJECT
private slots:
    void testConceptoData();
    void testMapa();
    //void testMonth();
};
void testPrograma::testConceptoData(){
    concepto a("nose",2,1);
    QCOMPARE(a.getTexto(),std::string("nose"));
    QCOMPARE(a.getPosX(),2);
    QCOMPARE(a.getPosY(),1);
}
void testPrograma::testMapa(){
    mapa mapaC;
    mapaC.agregarConcepto(concepto("arbol1",4,5));
    //std::list<concepto> listaConceptos;
    mapaC.agregarConcepto(concepto("arbol2",4,5));
    mapaC.agregarConcepto(concepto("flor3",3,5));
    mapaC.agregarConcepto(concepto("rama4",4,5));
    mapaC.agregarConcepto(concepto("palma5",7,5));
    mapaC.agregarConcepto(concepto("pino6",6,8));
    mapaC.agregarUnion(mapaC.getConceptoNum(3),mapaC.getConceptoNum(2));
    mapaC.agregarUnion(mapaC.getConceptoNum(1),mapaC.getConceptoNum(2));
    mapaC.guardar("/home/lenis96/Escritorio/prueba.xml");
    QVERIFY(mapaC.existeConcepto(4));
    QVERIFY(!mapaC.existeConcepto(7));
    QCOMPARE(mapaC.getConceptoNum(3).getTexto(),std::string("flor3"));
    QVERIFY(mapaC.existeUnion(3,2));
    QVERIFY(mapaC.existeUnion(2,3));
    QVERIFY(!mapaC.existeUnion(1,3));
    QVERIFY(mapaC.existeUnion(mapaC.getConceptoNum(1),mapaC.getConceptoNum(2)));
    QVERIFY(mapaC.existeUnion(mapaC.getConceptoNum(2),mapaC.getConceptoNum(1)));
    mapaC.~mapa();
    mapa mapaD("/home/lenis96/Escritorio/prueba.xml");
    QVERIFY(!mapaD.tieneError());


}
 
/*void testConcepto::testValidity()
{
    // 11 March 1967
    QDate date( 1967, 3, 11 );
    QVERIFY( date.isValid() );
}
 
void testConcepto::testMonth()
{
    // 11 March 1967
    QDate date;
    date.setYMD( 1967, 3, 11 );
    QCOMPARE( date.month(), 3 );
    QCOMPARE( QDate::longMonthName(date.month()),
              QString("March") );
}*/
 
 
QTEST_MAIN(testPrograma)
#include "test.moc"
