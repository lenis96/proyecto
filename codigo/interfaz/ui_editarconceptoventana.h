/********************************************************************************
** Form generated from reading UI file 'editarconceptoventana.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITARCONCEPTOVENTANA_H
#define UI_EDITARCONCEPTOVENTANA_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editarConceptoVentana
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox;
    QDialogButtonBox *buttonBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *editarConceptoVentana)
    {
        if (editarConceptoVentana->objectName().isEmpty())
            editarConceptoVentana->setObjectName(QString::fromUtf8("editarConceptoVentana"));
        editarConceptoVentana->setEnabled(true);
        editarConceptoVentana->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editarConceptoVentana->sizePolicy().hasHeightForWidth());
        editarConceptoVentana->setSizePolicy(sizePolicy);
        editarConceptoVentana->setMinimumSize(QSize(400, 300));
        editarConceptoVentana->setMaximumSize(QSize(400, 300));
        editarConceptoVentana->setModal(true);
        layoutWidget = new QWidget(editarConceptoVentana);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 20, 371, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_3 = new QSpinBox(layoutWidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMaximum(68);

        gridLayout->addWidget(spinBox_3, 1, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMinimum(-5000);
        spinBox_2->setMaximum(5000);

        gridLayout->addWidget(spinBox_2, 3, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(-5000);
        spinBox->setMaximum(5000);

        gridLayout->addWidget(spinBox, 4, 1, 1, 1);

        buttonBox_2 = new QDialogButtonBox(layoutWidget);
        buttonBox_2->setObjectName(QString::fromUtf8("buttonBox_2"));
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox_2, 7, 0, 1, 2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 8, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 8, 0, 1, 1);


        retranslateUi(editarConceptoVentana);
        QObject::connect(buttonBox_2, SIGNAL(accepted()), editarConceptoVentana, SLOT(close()));
        QObject::connect(buttonBox_2, SIGNAL(rejected()), editarConceptoVentana, SLOT(close()));

        QMetaObject::connectSlotsByName(editarConceptoVentana);
    } // setupUi

    void retranslateUi(QDialog *editarConceptoVentana)
    {
        editarConceptoVentana->setWindowTitle(QApplication::translate("editarConceptoVentana", "Editar Concepto", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("editarConceptoVentana", "concepto", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("editarConceptoVentana", "posici\303\263n en x", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("editarConceptoVentana", "posici\303\263n en y", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("editarConceptoVentana", "Id concepto", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("editarConceptoVentana", "Aplicar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("editarConceptoVentana", "eliminar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class editarConceptoVentana: public Ui_editarConceptoVentana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITARCONCEPTOVENTANA_H
