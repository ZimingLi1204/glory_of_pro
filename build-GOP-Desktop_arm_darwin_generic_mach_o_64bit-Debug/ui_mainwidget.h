/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *newGameBtn;
    QPushButton *readGameBtn;
    QPushButton *rulesIntro;
    QPushButton *exitGame;
    QSpinBox *player_num;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->resize(800, 600);
        groupBox = new QGroupBox(mainWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(300, 56, 177, 351));
        groupBox->setFlat(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, -1, -1, -1);
        newGameBtn = new QPushButton(groupBox);
        newGameBtn->setObjectName(QString::fromUtf8("newGameBtn"));
        newGameBtn->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newGameBtn->sizePolicy().hasHeightForWidth());
        newGameBtn->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        newGameBtn->setFont(font);
        newGameBtn->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(newGameBtn);

        readGameBtn = new QPushButton(groupBox);
        readGameBtn->setObjectName(QString::fromUtf8("readGameBtn"));
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(true);
        readGameBtn->setFont(font1);

        verticalLayout->addWidget(readGameBtn);

        rulesIntro = new QPushButton(groupBox);
        rulesIntro->setObjectName(QString::fromUtf8("rulesIntro"));
        rulesIntro->setFont(font1);

        verticalLayout->addWidget(rulesIntro);

        exitGame = new QPushButton(groupBox);
        exitGame->setObjectName(QString::fromUtf8("exitGame"));
        exitGame->setFont(font1);

        verticalLayout->addWidget(exitGame);

        player_num = new QSpinBox(mainWidget);
        player_num->setObjectName(QString::fromUtf8("player_num"));
        player_num->setGeometry(QRect(480, 110, 51, 31));

        retranslateUi(mainWidget);

        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QCoreApplication::translate("mainWidget", "mainWidget", nullptr));
        groupBox->setTitle(QString());
        newGameBtn->setText(QCoreApplication::translate("mainWidget", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        readGameBtn->setText(QCoreApplication::translate("mainWidget", "\350\257\273\345\217\226\345\255\230\346\241\243", nullptr));
        rulesIntro->setText(QCoreApplication::translate("mainWidget", "\350\247\204\345\210\231\344\273\213\347\273\215", nullptr));
        exitGame->setText(QCoreApplication::translate("mainWidget", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
