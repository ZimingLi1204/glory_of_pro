/********************************************************************************
** Form generated from reading UI file 'tpwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TPWIDGET_H
#define UI_TPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TpWidget
{
public:

    void setupUi(QWidget *TpWidget)
    {
        if (TpWidget->objectName().isEmpty())
            TpWidget->setObjectName(QString::fromUtf8("TpWidget"));
        TpWidget->resize(400, 300);

        retranslateUi(TpWidget);

        QMetaObject::connectSlotsByName(TpWidget);
    } // setupUi

    void retranslateUi(QWidget *TpWidget)
    {
        TpWidget->setWindowTitle(QCoreApplication::translate("TpWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TpWidget: public Ui_TpWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TPWIDGET_H
