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
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndGameWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *EndGameWidget)
    {
        if (EndGameWidget->objectName().isEmpty())
            EndGameWidget->setObjectName(QString::fromUtf8("EndGameWidget"));
        EndGameWidget->resize(400, 300);
        label = new QLabel(EndGameWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(50, 50, 300, 200));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(EndGameWidget);

        QMetaObject::connectSlotsByName(EndGameWidget);
    } // setupUi

    void retranslateUi(QWidget *EndGameWidget)
    {
        EndGameWidget->setWindowTitle(QCoreApplication::translate("EndGameWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("EndGameWidget", "\346\201\255\345\226\234\357\274\201\344\275\240\350\216\267\345\276\227\344\272\206\350\203\234\345\210\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndGameWidget: public Ui_EndGameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAMEWIDGET_H
