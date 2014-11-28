/********************************************************************************
** Form generated from reading UI file 'unirconceptosventana.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNIRCONCEPTOSVENTANA_H
#define UI_UNIRCONCEPTOSVENTANA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_unirConceptosVentana
{
public:
    QGridLayout *gridLayout_3;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QSpinBox *spinBox_2;
    QLabel *label_6;
    QLabel *texto2;
    QLabel *label_7;
    QLabel *y2;
    QLabel *label_8;
    QLabel *x2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLabel *label;
    QLabel *texto1;
    QLabel *label_2;
    QLabel *x1;
    QLabel *label_3;
    QLabel *y1;
    QPushButton *pushButton;

    void setupUi(QDialog *unirConceptosVentana)
    {
        if (unirConceptosVentana->objectName().isEmpty())
            unirConceptosVentana->setObjectName(QString::fromUtf8("unirConceptosVentana"));
        unirConceptosVentana->setWindowModality(Qt::ApplicationModal);
        unirConceptosVentana->setEnabled(true);
        unirConceptosVentana->resize(500, 200);
        unirConceptosVentana->setMinimumSize(QSize(500, 200));
        unirConceptosVentana->setMaximumSize(QSize(500, 200));
        gridLayout_3 = new QGridLayout(unirConceptosVentana);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        buttonBox = new QDialogButtonBox(unirConceptosVentana);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 2, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(unirConceptosVentana);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        spinBox_2 = new QSpinBox(unirConceptosVentana);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(68);

        gridLayout_2->addWidget(spinBox_2, 0, 1, 1, 1);

        label_6 = new QLabel(unirConceptosVentana);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        texto2 = new QLabel(unirConceptosVentana);
        texto2->setObjectName(QString::fromUtf8("texto2"));

        gridLayout_2->addWidget(texto2, 1, 1, 1, 1);

        label_7 = new QLabel(unirConceptosVentana);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        y2 = new QLabel(unirConceptosVentana);
        y2->setObjectName(QString::fromUtf8("y2"));

        gridLayout_2->addWidget(y2, 3, 1, 1, 1);

        label_8 = new QLabel(unirConceptosVentana);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        x2 = new QLabel(unirConceptosVentana);
        x2->setObjectName(QString::fromUtf8("x2"));

        gridLayout_2->addWidget(x2, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(unirConceptosVentana);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        spinBox = new QSpinBox(unirConceptosVentana);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(68);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        label = new QLabel(unirConceptosVentana);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        texto1 = new QLabel(unirConceptosVentana);
        texto1->setObjectName(QString::fromUtf8("texto1"));

        gridLayout->addWidget(texto1, 1, 1, 1, 1);

        label_2 = new QLabel(unirConceptosVentana);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        x1 = new QLabel(unirConceptosVentana);
        x1->setObjectName(QString::fromUtf8("x1"));

        gridLayout->addWidget(x1, 2, 1, 1, 1);

        label_3 = new QLabel(unirConceptosVentana);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        y1 = new QLabel(unirConceptosVentana);
        y1->setObjectName(QString::fromUtf8("y1"));

        gridLayout->addWidget(y1, 3, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        pushButton = new QPushButton(unirConceptosVentana);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(unirConceptosVentana);
        QObject::connect(buttonBox, SIGNAL(accepted()), unirConceptosVentana, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), unirConceptosVentana, SLOT(reject()));

        QMetaObject::connectSlotsByName(unirConceptosVentana);
    } // setupUi

    void retranslateUi(QDialog *unirConceptosVentana)
    {
        unirConceptosVentana->setWindowTitle(QApplication::translate("unirConceptosVentana", "unir conceptos", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("unirConceptosVentana", "Id concepto", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("unirConceptosVentana", "concepto", 0, QApplication::UnicodeUTF8));
        texto2->setText(QApplication::translate("unirConceptosVentana", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("unirConceptosVentana", "posici\303\263n en x", 0, QApplication::UnicodeUTF8));
        y2->setText(QApplication::translate("unirConceptosVentana", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("unirConceptosVentana", "posici\303\263n en y", 0, QApplication::UnicodeUTF8));
        x2->setText(QApplication::translate("unirConceptosVentana", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("unirConceptosVentana", "Id concepto", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("unirConceptosVentana", "concepto", 0, QApplication::UnicodeUTF8));
        texto1->setText(QApplication::translate("unirConceptosVentana", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("unirConceptosVentana", "posici\303\263n en x", 0, QApplication::UnicodeUTF8));
        x1->setText(QApplication::translate("unirConceptosVentana", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("unirConceptosVentana", "posici\303\263n en y", 0, QApplication::UnicodeUTF8));
        y1->setText(QApplication::translate("unirConceptosVentana", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("unirConceptosVentana", "eliminar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class unirConceptosVentana: public Ui_unirConceptosVentana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNIRCONCEPTOSVENTANA_H
