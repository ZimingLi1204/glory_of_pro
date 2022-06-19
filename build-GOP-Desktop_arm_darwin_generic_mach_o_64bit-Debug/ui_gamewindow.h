/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <mousepos.h>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QGroupBox *playerInfo;
    QGroupBox *playerInfo_0;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *hp_0;
    QLabel *lv_fist_0;
    QLabel *lv_sword_0;
    QLabel *lv_gun_0;
    QLabel *money_0;
    QLabel *lv_wing_0;
    QLabel *num_tp_0;
    QLabel *home_0;
    QGroupBox *playerInfo_1;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *hp_1;
    QLabel *lv_fist_1;
    QLabel *lv_sword_1;
    QLabel *lv_gun_1;
    QLabel *money_1;
    QLabel *lv_wing_1;
    QLabel *num_tp_1;
    QLabel *home_1;
    QGroupBox *playerInfo_2;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *hp_2;
    QLabel *lv_fist_2;
    QLabel *lv_sword_2;
    QLabel *lv_gun_2;
    QLabel *money_2;
    QLabel *lv_wing_2;
    QLabel *num_tp_2;
    QLabel *home_2;
    QGroupBox *playerInfo_3;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *hp_3;
    QLabel *lv_fist_3;
    QLabel *lv_sword_3;
    QLabel *lv_gun_3;
    QLabel *money_3;
    QLabel *lv_wing_3;
    QLabel *num_tp_3;
    QLabel *home_3;
    QGroupBox *gameInfo;
    QTextBrowser *textBrowser;
    QGroupBox *actionGroup;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *currPlayer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QPushButton *move;
    QPushButton *mine;
    QPushButton *buy;
    QPushButton *heal;
    QPushButton *tp;
    QPushButton *attack;
    QStackedWidget *map;
    QWidget *main;
    QWidget *move_interface;
    QPushButton *move_leave;
    QWidget *buy_interface;
    MousePos *Mouse;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *buyPlayer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QLabel *curMoney;
    QSpacerItem *horizontalSpacer_4;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *shop_leave;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(800, 600);
        playerInfo = new QGroupBox(GameWindow);
        playerInfo->setObjectName(QString::fromUtf8("playerInfo"));
        playerInfo->setGeometry(QRect(0, 0, 800, 150));
        playerInfo_0 = new QGroupBox(playerInfo);
        playerInfo_0->setObjectName(QString::fromUtf8("playerInfo_0"));
        playerInfo_0->setGeometry(QRect(3, 15, 200, 130));
        label_1 = new QLabel(playerInfo_0);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(10, 20, 81, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setPointSize(12);
        label_1->setFont(font);
        label_2 = new QLabel(playerInfo_0);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 45, 81, 30));
        label_2->setFont(font);
        label_3 = new QLabel(playerInfo_0);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 71, 30));
        label_3->setFont(font);
        label_4 = new QLabel(playerInfo_0);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 95, 71, 30));
        label_4->setFont(font);
        label_5 = new QLabel(playerInfo_0);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 20, 81, 30));
        label_5->setFont(font);
        label_6 = new QLabel(playerInfo_0);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(110, 45, 91, 30));
        label_6->setFont(font);
        label_7 = new QLabel(playerInfo_0);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(110, 70, 81, 30));
        label_7->setFont(font);
        label_8 = new QLabel(playerInfo_0);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(110, 95, 51, 30));
        label_8->setFont(font);
        hp_0 = new QLabel(playerInfo_0);
        hp_0->setObjectName(QString::fromUtf8("hp_0"));
        hp_0->setGeometry(QRect(60, 20, 50, 30));
        hp_0->setFont(font);
        lv_fist_0 = new QLabel(playerInfo_0);
        lv_fist_0->setObjectName(QString::fromUtf8("lv_fist_0"));
        lv_fist_0->setGeometry(QRect(80, 45, 50, 30));
        lv_fist_0->setFont(font);
        lv_sword_0 = new QLabel(playerInfo_0);
        lv_sword_0->setObjectName(QString::fromUtf8("lv_sword_0"));
        lv_sword_0->setGeometry(QRect(62, 70, 50, 30));
        lv_sword_0->setFont(font);
        lv_gun_0 = new QLabel(playerInfo_0);
        lv_gun_0->setObjectName(QString::fromUtf8("lv_gun_0"));
        lv_gun_0->setGeometry(QRect(62, 95, 50, 30));
        lv_gun_0->setFont(font);
        money_0 = new QLabel(playerInfo_0);
        money_0->setObjectName(QString::fromUtf8("money_0"));
        money_0->setGeometry(QRect(160, 20, 50, 30));
        money_0->setFont(font);
        lv_wing_0 = new QLabel(playerInfo_0);
        lv_wing_0->setObjectName(QString::fromUtf8("lv_wing_0"));
        lv_wing_0->setGeometry(QRect(180, 45, 50, 30));
        lv_wing_0->setFont(font);
        num_tp_0 = new QLabel(playerInfo_0);
        num_tp_0->setObjectName(QString::fromUtf8("num_tp_0"));
        num_tp_0->setGeometry(QRect(190, 70, 50, 30));
        num_tp_0->setFont(font);
        home_0 = new QLabel(playerInfo_0);
        home_0->setObjectName(QString::fromUtf8("home_0"));
        home_0->setGeometry(QRect(135, 95, 71, 30));
        home_0->setFont(font);
        playerInfo_1 = new QGroupBox(playerInfo);
        playerInfo_1->setObjectName(QString::fromUtf8("playerInfo_1"));
        playerInfo_1->setGeometry(QRect(200, 15, 200, 130));
        label_9 = new QLabel(playerInfo_1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 20, 81, 30));
        label_9->setFont(font);
        label_10 = new QLabel(playerInfo_1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 45, 81, 30));
        label_10->setFont(font);
        label_11 = new QLabel(playerInfo_1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 70, 71, 30));
        label_11->setFont(font);
        label_12 = new QLabel(playerInfo_1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 95, 71, 30));
        label_12->setFont(font);
        label_13 = new QLabel(playerInfo_1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(110, 20, 81, 30));
        label_13->setFont(font);
        label_14 = new QLabel(playerInfo_1);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(110, 45, 91, 30));
        label_14->setFont(font);
        label_15 = new QLabel(playerInfo_1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(110, 70, 81, 30));
        label_15->setFont(font);
        label_16 = new QLabel(playerInfo_1);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(110, 95, 51, 30));
        label_16->setFont(font);
        hp_1 = new QLabel(playerInfo_1);
        hp_1->setObjectName(QString::fromUtf8("hp_1"));
        hp_1->setGeometry(QRect(60, 20, 50, 30));
        hp_1->setFont(font);
        lv_fist_1 = new QLabel(playerInfo_1);
        lv_fist_1->setObjectName(QString::fromUtf8("lv_fist_1"));
        lv_fist_1->setGeometry(QRect(80, 45, 50, 30));
        lv_fist_1->setFont(font);
        lv_sword_1 = new QLabel(playerInfo_1);
        lv_sword_1->setObjectName(QString::fromUtf8("lv_sword_1"));
        lv_sword_1->setGeometry(QRect(62, 70, 50, 30));
        lv_sword_1->setFont(font);
        lv_gun_1 = new QLabel(playerInfo_1);
        lv_gun_1->setObjectName(QString::fromUtf8("lv_gun_1"));
        lv_gun_1->setGeometry(QRect(62, 95, 50, 30));
        lv_gun_1->setFont(font);
        money_1 = new QLabel(playerInfo_1);
        money_1->setObjectName(QString::fromUtf8("money_1"));
        money_1->setGeometry(QRect(160, 20, 50, 30));
        money_1->setFont(font);
        lv_wing_1 = new QLabel(playerInfo_1);
        lv_wing_1->setObjectName(QString::fromUtf8("lv_wing_1"));
        lv_wing_1->setGeometry(QRect(180, 45, 50, 30));
        lv_wing_1->setFont(font);
        num_tp_1 = new QLabel(playerInfo_1);
        num_tp_1->setObjectName(QString::fromUtf8("num_tp_1"));
        num_tp_1->setGeometry(QRect(190, 70, 50, 30));
        num_tp_1->setFont(font);
        home_1 = new QLabel(playerInfo_1);
        home_1->setObjectName(QString::fromUtf8("home_1"));
        home_1->setGeometry(QRect(135, 95, 71, 30));
        home_1->setFont(font);
        playerInfo_2 = new QGroupBox(playerInfo);
        playerInfo_2->setObjectName(QString::fromUtf8("playerInfo_2"));
        playerInfo_2->setGeometry(QRect(400, 15, 200, 130));
        label_17 = new QLabel(playerInfo_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 20, 81, 30));
        label_17->setFont(font);
        label_18 = new QLabel(playerInfo_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 45, 81, 30));
        label_18->setFont(font);
        label_19 = new QLabel(playerInfo_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 70, 71, 30));
        label_19->setFont(font);
        label_20 = new QLabel(playerInfo_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 95, 71, 30));
        label_20->setFont(font);
        label_21 = new QLabel(playerInfo_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(110, 20, 81, 30));
        label_21->setFont(font);
        label_22 = new QLabel(playerInfo_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(110, 45, 91, 30));
        label_22->setFont(font);
        label_23 = new QLabel(playerInfo_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(110, 70, 81, 30));
        label_23->setFont(font);
        label_24 = new QLabel(playerInfo_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(110, 95, 51, 30));
        label_24->setFont(font);
        hp_2 = new QLabel(playerInfo_2);
        hp_2->setObjectName(QString::fromUtf8("hp_2"));
        hp_2->setGeometry(QRect(60, 20, 50, 30));
        hp_2->setFont(font);
        lv_fist_2 = new QLabel(playerInfo_2);
        lv_fist_2->setObjectName(QString::fromUtf8("lv_fist_2"));
        lv_fist_2->setGeometry(QRect(80, 45, 50, 30));
        lv_fist_2->setFont(font);
        lv_sword_2 = new QLabel(playerInfo_2);
        lv_sword_2->setObjectName(QString::fromUtf8("lv_sword_2"));
        lv_sword_2->setGeometry(QRect(62, 70, 50, 30));
        lv_sword_2->setFont(font);
        lv_gun_2 = new QLabel(playerInfo_2);
        lv_gun_2->setObjectName(QString::fromUtf8("lv_gun_2"));
        lv_gun_2->setGeometry(QRect(62, 95, 50, 30));
        lv_gun_2->setFont(font);
        money_2 = new QLabel(playerInfo_2);
        money_2->setObjectName(QString::fromUtf8("money_2"));
        money_2->setGeometry(QRect(160, 20, 50, 30));
        money_2->setFont(font);
        lv_wing_2 = new QLabel(playerInfo_2);
        lv_wing_2->setObjectName(QString::fromUtf8("lv_wing_2"));
        lv_wing_2->setGeometry(QRect(180, 45, 50, 30));
        lv_wing_2->setFont(font);
        num_tp_2 = new QLabel(playerInfo_2);
        num_tp_2->setObjectName(QString::fromUtf8("num_tp_2"));
        num_tp_2->setGeometry(QRect(190, 70, 50, 30));
        num_tp_2->setFont(font);
        home_2 = new QLabel(playerInfo_2);
        home_2->setObjectName(QString::fromUtf8("home_2"));
        home_2->setGeometry(QRect(135, 95, 71, 30));
        home_2->setFont(font);
        playerInfo_3 = new QGroupBox(playerInfo);
        playerInfo_3->setObjectName(QString::fromUtf8("playerInfo_3"));
        playerInfo_3->setGeometry(QRect(600, 15, 200, 130));
        label_25 = new QLabel(playerInfo_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 20, 81, 30));
        label_25->setFont(font);
        label_26 = new QLabel(playerInfo_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 45, 81, 30));
        label_26->setFont(font);
        label_27 = new QLabel(playerInfo_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 70, 71, 30));
        label_27->setFont(font);
        label_28 = new QLabel(playerInfo_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 95, 71, 30));
        label_28->setFont(font);
        label_29 = new QLabel(playerInfo_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(110, 20, 81, 30));
        label_29->setFont(font);
        label_30 = new QLabel(playerInfo_3);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(110, 45, 91, 30));
        label_30->setFont(font);
        label_31 = new QLabel(playerInfo_3);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(110, 70, 81, 30));
        label_31->setFont(font);
        label_32 = new QLabel(playerInfo_3);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(110, 95, 51, 30));
        label_32->setFont(font);
        hp_3 = new QLabel(playerInfo_3);
        hp_3->setObjectName(QString::fromUtf8("hp_3"));
        hp_3->setGeometry(QRect(60, 20, 50, 30));
        hp_3->setFont(font);
        lv_fist_3 = new QLabel(playerInfo_3);
        lv_fist_3->setObjectName(QString::fromUtf8("lv_fist_3"));
        lv_fist_3->setGeometry(QRect(80, 45, 50, 30));
        lv_fist_3->setFont(font);
        lv_sword_3 = new QLabel(playerInfo_3);
        lv_sword_3->setObjectName(QString::fromUtf8("lv_sword_3"));
        lv_sword_3->setGeometry(QRect(62, 70, 50, 30));
        lv_sword_3->setFont(font);
        lv_gun_3 = new QLabel(playerInfo_3);
        lv_gun_3->setObjectName(QString::fromUtf8("lv_gun_3"));
        lv_gun_3->setGeometry(QRect(62, 95, 50, 30));
        lv_gun_3->setFont(font);
        money_3 = new QLabel(playerInfo_3);
        money_3->setObjectName(QString::fromUtf8("money_3"));
        money_3->setGeometry(QRect(160, 20, 50, 30));
        money_3->setFont(font);
        lv_wing_3 = new QLabel(playerInfo_3);
        lv_wing_3->setObjectName(QString::fromUtf8("lv_wing_3"));
        lv_wing_3->setGeometry(QRect(180, 45, 50, 30));
        lv_wing_3->setFont(font);
        num_tp_3 = new QLabel(playerInfo_3);
        num_tp_3->setObjectName(QString::fromUtf8("num_tp_3"));
        num_tp_3->setGeometry(QRect(190, 70, 50, 30));
        num_tp_3->setFont(font);
        home_3 = new QLabel(playerInfo_3);
        home_3->setObjectName(QString::fromUtf8("home_3"));
        home_3->setGeometry(QRect(135, 95, 71, 30));
        home_3->setFont(font);
        gameInfo = new QGroupBox(GameWindow);
        gameInfo->setObjectName(QString::fromUtf8("gameInfo"));
        gameInfo->setGeometry(QRect(450, 150, 350, 150));
        textBrowser = new QTextBrowser(gameInfo);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 20, 351, 131));
        textBrowser->setAutoFillBackground(true);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Raised);
        actionGroup = new QGroupBox(GameWindow);
        actionGroup->setObjectName(QString::fromUtf8("actionGroup"));
        actionGroup->setGeometry(QRect(450, 300, 350, 300));
        groupBox = new QGroupBox(actionGroup);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 351, 51));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        currPlayer = new QLabel(groupBox);
        currPlayer->setObjectName(QString::fromUtf8("currPlayer"));
        currPlayer->setFont(font1);

        horizontalLayout->addWidget(currPlayer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        groupBox_2 = new QGroupBox(actionGroup);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(-3, 58, 351, 241));
        move = new QPushButton(groupBox_2);
        move->setObjectName(QString::fromUtf8("move"));
        move->setGeometry(QRect(80, 20, 80, 29));
        QFont font2;
        font2.setPointSize(18);
        move->setFont(font2);
        mine = new QPushButton(groupBox_2);
        mine->setObjectName(QString::fromUtf8("mine"));
        mine->setGeometry(QRect(80, 90, 80, 29));
        mine->setFont(font2);
        buy = new QPushButton(groupBox_2);
        buy->setObjectName(QString::fromUtf8("buy"));
        buy->setGeometry(QRect(80, 160, 80, 29));
        buy->setFont(font2);
        heal = new QPushButton(groupBox_2);
        heal->setObjectName(QString::fromUtf8("heal"));
        heal->setGeometry(QRect(220, 90, 80, 29));
        heal->setFont(font2);
        tp = new QPushButton(groupBox_2);
        tp->setObjectName(QString::fromUtf8("tp"));
        tp->setGeometry(QRect(220, 160, 80, 29));
        tp->setFont(font2);
        attack = new QPushButton(groupBox_2);
        attack->setObjectName(QString::fromUtf8("attack"));
        attack->setGeometry(QRect(220, 20, 80, 29));
        attack->setFont(font2);
        map = new QStackedWidget(GameWindow);
        map->setObjectName(QString::fromUtf8("map"));
        map->setGeometry(QRect(0, 150, 450, 450));
        main = new QWidget();
        main->setObjectName(QString::fromUtf8("main"));
        map->addWidget(main);
        move_interface = new QWidget();
        move_interface->setObjectName(QString::fromUtf8("move_interface"));
        move_leave = new QPushButton(move_interface);
        move_leave->setObjectName(QString::fromUtf8("move_leave"));
        move_leave->setGeometry(QRect(340, 410, 100, 32));
        map->addWidget(move_interface);
        buy_interface = new QWidget();
        buy_interface->setObjectName(QString::fromUtf8("buy_interface"));
        Mouse = new MousePos(buy_interface);
        Mouse->setObjectName(QString::fromUtf8("Mouse"));
        Mouse->setGeometry(QRect(0, 0, 450, 450));
        layoutWidget = new QWidget(buy_interface);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 411, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        buyPlayer = new QLabel(layoutWidget);
        buyPlayer->setObjectName(QString::fromUtf8("buyPlayer"));

        horizontalLayout_2->addWidget(buyPlayer);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        curMoney = new QLabel(layoutWidget);
        curMoney->setObjectName(QString::fromUtf8("curMoney"));

        horizontalLayout_2->addWidget(curMoney);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        layoutWidget1 = new QWidget(buy_interface);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(19, 390, 411, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        shop_leave = new QPushButton(layoutWidget1);
        shop_leave->setObjectName(QString::fromUtf8("shop_leave"));

        horizontalLayout_3->addWidget(shop_leave);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        map->addWidget(buy_interface);

        retranslateUi(GameWindow);

        map->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QWidget *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "Form", nullptr));
        playerInfo->setTitle(QCoreApplication::translate("GameWindow", "\347\216\251\345\256\266\344\277\241\346\201\257", nullptr));
        playerInfo_0->setTitle(QCoreApplication::translate("GameWindow", "\347\216\251\345\256\2660", nullptr));
        label_1->setText(QCoreApplication::translate("GameWindow", "\350\241\200\351\207\217\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("GameWindow", "\346\213\263\345\244\264\357\274\232lv", nullptr));
        label_3->setText(QCoreApplication::translate("GameWindow", "\345\210\200\357\274\232lv", nullptr));
        label_4->setText(QCoreApplication::translate("GameWindow", "\346\236\252\357\274\232lv", nullptr));
        label_5->setText(QCoreApplication::translate("GameWindow", "\351\207\221\345\270\201\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("GameWindow", "\347\277\205\350\206\200\357\274\232lv", nullptr));
        label_7->setText(QCoreApplication::translate("GameWindow", "\345\233\236\345\237\216\345\215\267\350\275\264\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("GameWindow", "\345\256\266\357\274\232", nullptr));
        hp_0->setText(QCoreApplication::translate("GameWindow", "0/5", nullptr));
        lv_fist_0->setText(QCoreApplication::translate("GameWindow", "0.5", nullptr));
        lv_sword_0->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        lv_gun_0->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        money_0->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        lv_wing_0->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        num_tp_0->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        home_0->setText(QCoreApplication::translate("GameWindow", "ABCD", nullptr));
        playerInfo_1->setTitle(QCoreApplication::translate("GameWindow", "\347\216\251\345\256\2661", nullptr));
        label_9->setText(QCoreApplication::translate("GameWindow", "\350\241\200\351\207\217\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("GameWindow", "\346\213\263\345\244\264\357\274\232lv", nullptr));
        label_11->setText(QCoreApplication::translate("GameWindow", "\345\210\200\357\274\232lv", nullptr));
        label_12->setText(QCoreApplication::translate("GameWindow", "\346\236\252\357\274\232lv", nullptr));
        label_13->setText(QCoreApplication::translate("GameWindow", "\351\207\221\345\270\201\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("GameWindow", "\347\277\205\350\206\200\357\274\232lv", nullptr));
        label_15->setText(QCoreApplication::translate("GameWindow", "\345\233\236\345\237\216\345\215\267\350\275\264\357\274\232", nullptr));
        label_16->setText(QCoreApplication::translate("GameWindow", "\345\256\266\357\274\232", nullptr));
        hp_1->setText(QCoreApplication::translate("GameWindow", "0/5", nullptr));
        lv_fist_1->setText(QCoreApplication::translate("GameWindow", "0.5", nullptr));
        lv_sword_1->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        lv_gun_1->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        money_1->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        lv_wing_1->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        num_tp_1->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        home_1->setText(QCoreApplication::translate("GameWindow", "ABCD", nullptr));
        playerInfo_2->setTitle(QCoreApplication::translate("GameWindow", "\347\216\251\345\256\2662", nullptr));
        label_17->setText(QCoreApplication::translate("GameWindow", "\350\241\200\351\207\217\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("GameWindow", "\346\213\263\345\244\264\357\274\232lv", nullptr));
        label_19->setText(QCoreApplication::translate("GameWindow", "\345\210\200\357\274\232lv", nullptr));
        label_20->setText(QCoreApplication::translate("GameWindow", "\346\236\252\357\274\232lv", nullptr));
        label_21->setText(QCoreApplication::translate("GameWindow", "\351\207\221\345\270\201\357\274\232", nullptr));
        label_22->setText(QCoreApplication::translate("GameWindow", "\347\277\205\350\206\200\357\274\232lv", nullptr));
        label_23->setText(QCoreApplication::translate("GameWindow", "\345\233\236\345\237\216\345\215\267\350\275\264\357\274\232", nullptr));
        label_24->setText(QCoreApplication::translate("GameWindow", "\345\256\266\357\274\232", nullptr));
        hp_2->setText(QCoreApplication::translate("GameWindow", "0/5", nullptr));
        lv_fist_2->setText(QCoreApplication::translate("GameWindow", "0.5", nullptr));
        lv_sword_2->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        lv_gun_2->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        money_2->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        lv_wing_2->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        num_tp_2->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        home_2->setText(QCoreApplication::translate("GameWindow", "ABCD", nullptr));
        playerInfo_3->setTitle(QCoreApplication::translate("GameWindow", "\347\216\251\345\256\2663", nullptr));
        label_25->setText(QCoreApplication::translate("GameWindow", "\350\241\200\351\207\217\357\274\232", nullptr));
        label_26->setText(QCoreApplication::translate("GameWindow", "\346\213\263\345\244\264\357\274\232lv", nullptr));
        label_27->setText(QCoreApplication::translate("GameWindow", "\345\210\200\357\274\232lv", nullptr));
        label_28->setText(QCoreApplication::translate("GameWindow", "\346\236\252\357\274\232lv", nullptr));
        label_29->setText(QCoreApplication::translate("GameWindow", "\351\207\221\345\270\201\357\274\232", nullptr));
        label_30->setText(QCoreApplication::translate("GameWindow", "\347\277\205\350\206\200\357\274\232lv", nullptr));
        label_31->setText(QCoreApplication::translate("GameWindow", "\345\233\236\345\237\216\345\215\267\350\275\264\357\274\232", nullptr));
        label_32->setText(QCoreApplication::translate("GameWindow", "\345\256\266\357\274\232", nullptr));
        hp_3->setText(QCoreApplication::translate("GameWindow", "0/5", nullptr));
        lv_fist_3->setText(QCoreApplication::translate("GameWindow", "0.5", nullptr));
        lv_sword_3->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        lv_gun_3->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        money_3->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        lv_wing_3->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        num_tp_3->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        home_3->setText(QCoreApplication::translate("GameWindow", "ABCD", nullptr));
        gameInfo->setTitle(QCoreApplication::translate("GameWindow", "\345\257\271\345\261\200\344\277\241\346\201\257", nullptr));
        actionGroup->setTitle(QCoreApplication::translate("GameWindow", "\346\223\215\344\275\234\345\217\260", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("GameWindow", "\345\275\223\345\211\215\347\216\251\345\256\266\357\274\232", nullptr));
        currPlayer->setText(QCoreApplication::translate("GameWindow", "\345\215\242\346\234\254\344\274\237", nullptr));
        groupBox_2->setTitle(QString());
        move->setText(QCoreApplication::translate("GameWindow", "\347\247\273\345\212\250", nullptr));
        mine->setText(QCoreApplication::translate("GameWindow", "\346\214\226\347\237\277", nullptr));
        buy->setText(QCoreApplication::translate("GameWindow", "\350\264\255\347\211\251", nullptr));
        heal->setText(QCoreApplication::translate("GameWindow", "\346\262\273\347\226\227", nullptr));
        tp->setText(QCoreApplication::translate("GameWindow", "\345\233\236\345\237\216", nullptr));
        attack->setText(QCoreApplication::translate("GameWindow", "\346\224\273\345\207\273", nullptr));
        move_leave->setText(QCoreApplication::translate("GameWindow", "\347\246\273\345\274\200", nullptr));
        Mouse->setText(QString());
        buyPlayer->setText(QCoreApplication::translate("GameWindow", "TextLabel", nullptr));
        curMoney->setText(QCoreApplication::translate("GameWindow", "TextLabel", nullptr));
        shop_leave->setText(QCoreApplication::translate("GameWindow", "\347\246\273\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
