/********************************************************************************
** Form generated from reading UI file 'attackwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTACKWIDGET_H
#define UI_ATTACKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttackWidget
{
public:

    void setupUi(QWidget *AttackWidget)
    {
        if (AttackWidget->objectName().isEmpty())
            AttackWidget->setObjectName(QString::fromUtf8("AttackWidget"));
        AttackWidget->resize(400, 300);

        retranslateUi(AttackWidget);

        QMetaObject::connectSlotsByName(AttackWidget);
    } // setupUi

    void retranslateUi(QWidget *AttackWidget)
    {
        AttackWidget->setWindowTitle(QCoreApplication::translate("AttackWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttackWidget: public Ui_AttackWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTACKWIDGET_H
