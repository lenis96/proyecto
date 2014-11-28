/********************************************************************************
** Form generated from reading UI file 'nuevoconceptoventana.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVOCONCEPTOVENTANA_H
#define UI_NUEVOCONCEPTOVENTANA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_nuevoConceptoVentana
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *nuevoConceptoVentana)
    {
        if (nuevoConceptoVentana->objectName().isEmpty())
            nuevoConceptoVentana->setObjectName(QString::fromUtf8("nuevoConceptoVentana"));
        nuevoConceptoVentana->resize(400, 300);
        nuevoConceptoVentana->setMinimumSize(QSize(400, 300));
        nuevoConceptoVentana->setMaximumSize(QSize(400, 300));
        nuevoConceptoVentana->setModal(true);
        gridLayout = new QGridLayout(nuevoConceptoVentana);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(nuevoConceptoVentana);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(nuevoConceptoVentana);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(nuevoConceptoVentana);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox_2 = new QSpinBox(nuevoConceptoVentana);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMinimum(-5000);
        spinBox_2->setMaximum(5000);

        gridLayout->addWidget(spinBox_2, 1, 1, 1, 1);

        label_3 = new QLabel(nuevoConceptoVentana);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spinBox = new QSpinBox(nuevoConceptoVentana);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(-5000);
        spinBox->setMaximum(5000);

        gridLayout->addWidget(spinBox, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(nuevoConceptoVentana);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);


        retranslateUi(nuevoConceptoVentana);
        QObject::connect(buttonBox, SIGNAL(accepted()), nuevoConceptoVentana, SLOT(close()));
        QObject::connect(buttonBox, SIGNAL(rejected()), nuevoConceptoVentana, SLOT(close()));

        QMetaObject::connectSlotsByName(nuevoConceptoVentana);
    } // setupUi

    void retranslateUi(QDialog *nuevoConceptoVentana)
    {
        nuevoConceptoVentana->setWindowTitle(QApplication::translate("nuevoConceptoVentana", "Nuevo Concepto", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("nuevoConceptoVentana", "Nuevo concepto", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("nuevoConceptoVentana", "posici\303\263n en x", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("nuevoConceptoVentana", "posici\303\263n en y", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class nuevoConceptoVentana: public Ui_nuevoConceptoVentana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVOCONCEPTOVENTANA_H
