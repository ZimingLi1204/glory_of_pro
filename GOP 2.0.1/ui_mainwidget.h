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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *player_num;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *newGameBtn;
    QPushButton *readGameBtn;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *rulesIntro;
    QPushButton *exitGame;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->resize(800, 600);
        widget = new QWidget(mainWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(230, 300, 302, 225));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(142, 67));
        label->setMaximumSize(QSize(142, 67));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        player_num = new QSpinBox(widget);
        player_num->setObjectName(QString::fromUtf8("player_num"));
        player_num->setMinimumSize(QSize(90, 30));
        player_num->setMaximumSize(QSize(90, 30));
        player_num->setFont(font);
        player_num->setWrapping(true);
        player_num->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

        horizontalLayout->addWidget(player_num);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        newGameBtn = new QPushButton(widget);
        newGameBtn->setObjectName(QString::fromUtf8("newGameBtn"));
        newGameBtn->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(newGameBtn->sizePolicy().hasHeightForWidth());
        newGameBtn->setSizePolicy(sizePolicy1);
        newGameBtn->setMinimumSize(QSize(142, 67));
        newGameBtn->setMaximumSize(QSize(142, 67));
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        newGameBtn->setFont(font1);
        newGameBtn->setIconSize(QSize(12, 12));

        horizontalLayout_2->addWidget(newGameBtn);

        readGameBtn = new QPushButton(widget);
        readGameBtn->setObjectName(QString::fromUtf8("readGameBtn"));
        readGameBtn->setMinimumSize(QSize(142, 67));
        readGameBtn->setMaximumSize(QSize(142, 67));
        QFont font2;
        font2.setPointSize(25);
        font2.setBold(true);
        readGameBtn->setFont(font2);

        horizontalLayout_2->addWidget(readGameBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rulesIntro = new QPushButton(widget);
        rulesIntro->setObjectName(QString::fromUtf8("rulesIntro"));
        sizePolicy.setHeightForWidth(rulesIntro->sizePolicy().hasHeightForWidth());
        rulesIntro->setSizePolicy(sizePolicy);
        rulesIntro->setMinimumSize(QSize(142, 67));
        rulesIntro->setMaximumSize(QSize(142, 67));
        rulesIntro->setFont(font2);

        horizontalLayout_3->addWidget(rulesIntro);

        exitGame = new QPushButton(widget);
        exitGame->setObjectName(QString::fromUtf8("exitGame"));
        exitGame->setMinimumSize(QSize(142, 67));
        exitGame->setMaximumSize(QSize(142, 67));
        exitGame->setFont(font2);

        horizontalLayout_3->addWidget(exitGame);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(mainWidget);

        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QCoreApplication::translate("mainWidget", "mainWidget", nullptr));
        label->setText(QCoreApplication::translate("mainWidget", "\344\272\272\346\225\260\351\200\211\346\213\251", nullptr));
        newGameBtn->setText(QString());
        readGameBtn->setText(QString());
        rulesIntro->setText(QString());
        exitGame->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
