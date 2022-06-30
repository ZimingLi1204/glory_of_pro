/********************************************************************************
** Form generated from reading UI file 'endgamewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDGAMEWIDGET_H
#define UI_ENDGAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndGameWidget
{
public:

    void setupUi(QWidget *EndGameWidget)
    {
        if (EndGameWidget->objectName().isEmpty())
            EndGameWidget->setObjectName(QString::fromUtf8("EndGameWidget"));
        EndGameWidget->resize(400, 300);

        retranslateUi(EndGameWidget);

        QMetaObject::connectSlotsByName(EndGameWidget);
    } // setupUi

    void retranslateUi(QWidget *EndGameWidget)
    {
        EndGameWidget->setWindowTitle(QCoreApplication::translate("EndGameWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndGameWidget: public Ui_EndGameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAMEWIDGET_H
