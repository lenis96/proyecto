/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo_Archivo;
    QAction *actionAbrir_Archivo;
    QAction *actionGuardar_Archivo;
    QAction *actionGuardar_Como;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QListView *listView;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 463);
        actionNuevo_Archivo = new QAction(MainWindow);
        actionNuevo_Archivo->setObjectName(QString::fromUtf8("actionNuevo_Archivo"));
        actionAbrir_Archivo = new QAction(MainWindow);
        actionAbrir_Archivo->setObjectName(QString::fromUtf8("actionAbrir_Archivo"));
        actionGuardar_Archivo = new QAction(MainWindow);
        actionGuardar_Archivo->setObjectName(QString::fromUtf8("actionGuardar_Archivo"));
        actionGuardar_Como = new QAction(MainWindow);
        actionGuardar_Como->setObjectName(QString::fromUtf8("actionGuardar_Como"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(500, 500));

        gridLayout_2->addWidget(graphicsView, 1, 0, 1, 1);

        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy1);
        listView->setMinimumSize(QSize(100, 0));

        gridLayout_2->addWidget(listView, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 960, 25));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionNuevo_Archivo);
        menuArchivo->addAction(actionAbrir_Archivo);
        menuArchivo->addAction(actionGuardar_Archivo);
        menuArchivo->addAction(actionGuardar_Como);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNuevo_Archivo->setText(QApplication::translate("MainWindow", "Nuevo Archivo", 0, QApplication::UnicodeUTF8));
        actionAbrir_Archivo->setText(QApplication::translate("MainWindow", "Abrir Archivo", 0, QApplication::UnicodeUTF8));
        actionGuardar_Archivo->setText(QApplication::translate("MainWindow", "Guardar Archivo", 0, QApplication::UnicodeUTF8));
        actionGuardar_Como->setText(QApplication::translate("MainWindow", "Guardar Como", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Nuevo Concepto", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Unir Conceptos", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Editar Concepto", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Iniciar Presentacion", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
