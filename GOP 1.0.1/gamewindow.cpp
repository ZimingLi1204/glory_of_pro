#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>
#include <QPainter>
#include <QPushButton>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QDateTime>
#include <QTextBrowser>
QString text;
GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    bd(4),
    ui(new Ui::GameWindow)
{
    //initial settings
    ui->setupUi(this);
    //控制台
    qInstallMessageHandler(logOutput);
    ui->hp_0->setText("4/5");

    for(int i = 0; i < 4; ++i) {
        player_image[i] = new QLabel(ui -> main);
        player_buy_image[i] = new QLabel(ui -> buy_interface);
        player_buy_image[i] -> move(20, 100);
        player_buy_image[i] -> hide();
    }

    for(int i = 0; i < 4; ++i) {
        player_image[i] = new QLabel(ui -> main);
    }
    player_image[0] -> setPixmap(QPixmap(":/character1/idle/hero120001/idle/frame0central.png"));
    player_image[1] -> setPixmap(QPixmap(":/character2/idle/hero40004/idle/frame0central.png"));
    player_image[2] -> setPixmap(QPixmap(":/character3/idle/hero120008/idle/frame0central.png"));
    player_image[3] -> setPixmap(QPixmap(":/character4/idle/hero120009/idle/frame0central.png"));
    player_buy_image[0] -> setPixmap(QPixmap(":/character1/idle/hero120001/idle/frame0central.png"));
    player_buy_image[1] -> setPixmap(QPixmap(":/character2/idle/hero40004/idle/frame0central.png"));
    player_buy_image[2] -> setPixmap(QPixmap(":/character3/idle/hero120008/idle/frame0central.png"));
    player_buy_image[3] -> setPixmap(QPixmap(":/character4/idle/hero120009/idle/frame0central.png"));
    ui -> Mouse -> setPixmap(QPixmap(":/map/set_050.png"));
    ui -> Mouse -> setScaledContents(true);
    ui -> map -> setCurrentIndex(0);

    for (int i = 0; i < 6; ++i) {
        buylist[i] = new QPushButton(ui -> buy_interface);
        if (i == 0) buylist[i] -> hide();
        buylist[i] -> resize(200, 40);
        buylist[i] -> move(120, 60 + 50 * i);
        buylist[i] -> setIcon(QIcon(QString(":/buy/Shop/shop%01.png").arg(i)));
    }

    //按钮建立连接
    // move界面初始化
    initMove();
    connect(ui->move, &QPushButton::clicked,[=](){
        checkAvailablePos();
        ui -> buy -> setEnabled(false);
        ui -> mine -> setEnabled(false);
        ui -> heal -> setEnabled(false);
        ui -> attack -> setEnabled(false);
        ui -> tp -> setEnabled(false);
        ui -> move -> setEnabled(false);
        ui -> map -> setCurrentIndex(1);
        player_move_image[currPlayer] -> show();
    });
    connect(ui->move_leave, &QPushButton::clicked,[=](){
        ui -> map -> setCurrentIndex(0);
        ui -> buy -> setEnabled(true);
        ui -> mine -> setEnabled(true);
        ui -> heal -> setEnabled(true);
        ui -> attack -> setEnabled(true);
        ui -> tp -> setEnabled(true);
        ui -> move -> setEnabled(true);
        refresh();
    });
    //每个移动按钮对应槽函数
    for(int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            connect(moveto[i][j], &QPushButton::clicked, [=](){

                bd.pl[currPlayer].pos[0] = i;
                bd.pl[currPlayer].pos[1] = j;
                updatePlayerInfo();
                qDebug()<< (char) ('A' + currPlayer) << " moved to " << i << ' ' << j;
                on_lineEdit_textChanged();
                player_move_image[currPlayer] -> move(coordinate[bd.pl[currPlayer].pos[1] - 1], coordinate[bd.pl[currPlayer].pos[0] - 1]);
                player_image[currPlayer] -> move(coordinate[bd.pl[currPlayer].pos[1] - 1], coordinate[bd.pl[currPlayer].pos[0] - 1]);
                currPlayerNum[currPlayer] = 0;
                player_move_image[currPlayer] -> hide();
                if (judgeToEndRoll()) {
                    startANewRoll();
                }
                else {
                    switchToNextPlayer();
                }
                refresh();
                ui -> map -> setCurrentIndex(0);
            });
        }
    }


    // 挖矿 mine
    connect(ui->mine, &QPushButton::clicked, this, &GameWindow::mineSlot);

    // 购买界面
    connect(ui->buy, &QPushButton::clicked,[=](){

        if (name_all[bd.pl[currPlayer].pos[0]][bd.pl[currPlayer].pos[1]] != "ss" && name_all[bd.pl[currPlayer].pos[0]][bd.pl[currPlayer].pos[1]] != "bs") {
            QMessageBox * msgbox = new QMessageBox;
            msgbox->critical(this, "错误", "无法在此处购买");
        }
        else if (name_all[bd.pl[currPlayer].pos[0]][bd.pl[currPlayer].pos[1]] == "ss") {
            initBuy(1);
            ui -> map -> setCurrentIndex(2);
            ui -> buy -> setEnabled(false);
            ui -> mine -> setEnabled(false);
            ui -> heal -> setEnabled(false);
            ui -> attack -> setEnabled(false);
            ui -> tp -> setEnabled(false);
            ui -> move -> setEnabled(false);
        }
        else {
            initBuy(0);
            ui -> map -> setCurrentIndex(2);
            ui -> buy -> setEnabled(false);
            ui -> mine -> setEnabled(false);
            ui -> heal -> setEnabled(false);
            ui -> attack -> setEnabled(false);
            ui -> tp -> setEnabled(false);
            ui -> move -> setEnabled(false);
        }
    });
    //连接五个购买按钮
    for(int i = 1; i <= 5; ++i) {
        connect(buylist[i], &QPushButton::clicked, [=](){
            QStringList namelist;
            namelist << "力量之拳" << "驱魔大刀" << "烈火之枪" << "传送之翼" << "生命药水" << "回城卷轴";
            int lev = bd.pl[currPlayer].checkLevel(i);
            if (name_all[bd.pl[currPlayer].pos[0]][bd.pl[currPlayer].pos[1]] == "ss") {
                if (i <= 3) {
                    if (bd.pl[currPlayer].buy(i, lev+1,1)) {
                        buy_happen = true;
                        updatePlayerInfo();

                        qDebug()<< "玩家 " << currPlayer << "购买了" << namelist[i] << "等级为" << lev+1;
                        on_lineEdit_textChanged();
                    }
                    else {
                        QMessageBox * nomoney = new QMessageBox;
                        nomoney->critical(this, "错误", "没有足够的钱");
                    }
                }
                else {
                    if (bd.pl[currPlayer].buy(i, 1, 1)) {
                        buy_happen = true;
                        updatePlayerInfo();

                        qDebug()<< "玩家 " << currPlayer << "购买了" << namelist[i];
                        on_lineEdit_textChanged();
                    }
                    else {
                        QMessageBox * nomoney = new QMessageBox;
                        nomoney->critical(this, "错误", "没有足够的钱");
                    }
                }
                initBuy(1);
            }
            else {
                if (i <= 3) {
                    if (bd.pl[currPlayer].buy(i, lev+1,0)) {
                        buy_happen = true;
                        updatePlayerInfo();

                        qDebug()<< "玩家 " << currPlayer << "购买了" << namelist[i] << "等级为" << lev+1;
                        on_lineEdit_textChanged();
                    }
                    else {
                        QMessageBox * nomoney = new QMessageBox;
                        nomoney->critical(this, "错误", "没有足够的钱");

                    }
                }
                else {
                    if (bd.pl[currPlayer].buy(i, 1, 0)) {
                        buy_happen = true;
                        updatePlayerInfo();

                        qDebug()<< "玩家 " << currPlayer << "购买了" << namelist[i];
                        on_lineEdit_textChanged();
                    }
                    else {
                        QMessageBox * nomoney = new QMessageBox;
                        nomoney->critical(this, "错误", "没有足够的钱");
                    }
                }
                initBuy(0);
            }
        });
    }
    //离开购买界面
    connect(ui -> shop_leave, &QPushButton::clicked, [=](){
        if (buy_happen) {
            currPlayerNum[currPlayer] = 0;
            buy_happen = false;
            player_buy_image[currPlayer] -> hide();
            if (judgeToEndRoll()) {
                startANewRoll();
            }
            else {
                switchToNextPlayer();
            }
        }
        ui -> buy -> setEnabled(true);
        ui -> mine -> setEnabled(true);
        ui -> heal -> setEnabled(true);
        ui -> attack -> setEnabled(true);
        ui -> tp -> setEnabled(true);
        ui -> move -> setEnabled(true);
        player_buy_image[currPlayer] -> hide();
        ui -> map -> setCurrentIndex(0);
    });

    // 攻击 attack
    attackWidget = new AttackWidget;
    endGameWidget = new EndGameWidget;
    connect(this, &GameWindow::endGameSignal, endGameWidget, &GameWindow::show);
    connect(ui->attack, &QPushButton::clicked, [=](){
        attackWidget -> show();
        //bd.pl[currPlayer].wp.push_back(gun(2));
        //设定按钮是否enable
        for (int i = bd.player_num; i < 4; i++)
            attackWidget->btn_target[i]->setEnabled(false);
        for (int i = 0; i < bd.player_num; i++) {
            if (i == currPlayer) {
                attackWidget->btn_target[i]->setEnabled(false);
                continue;
            }
            if (!bd.pl[i].isAlive) {
                attackWidget->btn_target[i]->setEnabled(false);
                continue;
            }
            if (bd.pl[i].pos[0] == bd.pl[currPlayer].pos[0] && bd.pl[i].pos[1] == bd.pl[currPlayer].pos[1]) {
                attackWidget->btn_target[i]->setEnabled(true);
                continue;
            }
            if (bd.pl[i].pos[0] == bd.pl[currPlayer].pos[0] && abs(bd.pl[i].pos[1] - bd.pl[currPlayer].pos[1]) <= bd.pl[currPlayer].checkLevel(2)) {
                attackWidget->btn_target[i]->setEnabled(true);
                continue;
            }
            if (bd.pl[i].pos[1] == bd.pl[currPlayer].pos[1] && abs(bd.pl[i].pos[0] - bd.pl[currPlayer].pos[0]) <= bd.pl[currPlayer].checkLevel(2)) {
                attackWidget->btn_target[i]->setEnabled(true);
                continue;
            }
            attackWidget->btn_target[i]->setEnabled(false);
        }

    });
    for (int i = 0; i < bd.player_num; i++) {
        connect(attackWidget->btn_target[i], &QPushButton::clicked, [=]() {
            // 用近战武器打
            if (bd.pl[i].pos[0] == bd.pl[currPlayer].pos[0] && bd.pl[i].pos[1] == bd.pl[currPlayer].pos[1]) {
                // 用刀打
                if (bd.pl[currPlayer].checkLevel(1) > 0) {
                    bd.pl[currPlayer].attack(bd.pl[i], sword(bd.pl[currPlayer].checkLevel(1)));
                }
                // 用拳头打
                else {
                    bd.pl[currPlayer].attack(bd.pl[i], fist());
                }
            }

            // 用远程武器打
            else {
                bd.pl[currPlayer].attack(bd.pl[i], gun(bd.pl[currPlayer].checkLevel(2)));
            }
            attackWidget->close();
            currPlayerNum[currPlayer] = 0;
            updatePlayerInfo();

            // 结束游戏判定
            int survivor_num = 0; // 幸存者数量
            for (int i = 0; i < bd.player_num; i++) {
                if (bd.pl[i].isAlive)
                    survivor_num++;
                else {
                    player_image[i] -> hide();
                    player_move_image[i] -> hide();
                }
            }
            if (survivor_num == 1) {
                emit endGameSignal();
            }
            //换人行动或更新回合
            else {
                if (judgeToEndRoll()) {
                    startANewRoll();
                }
                else {
                    switchToNextPlayer();
                }
            }
        });
    }

    // 回血 heal
    connect(ui->heal, &QPushButton::clicked, this, &GameWindow::healSlot);

    // 回城 tp
    tpWidget = new TpWidget;
    connect(ui->tp, &QPushButton::clicked, this, &GameWindow::tpSlot);
    connect(tpWidget->btn_hm[0], &QPushButton::clicked, this, &GameWindow::tpTo_hm_0);
    connect(tpWidget->btn_hm[1], &QPushButton::clicked, this, &GameWindow::tpTo_hm_1);
    connect(tpWidget->btn_hm[2], &QPushButton::clicked, this, &GameWindow::tpTo_hm_2);
    connect(tpWidget->btn_hm[3], &QPushButton::clicked, this, &GameWindow::tpTo_hm_3);
}

//设定map背景
void GameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // 背景图片
    painter.drawPixmap(0,150,450,450,QPixmap(":/map/map450_450.png"));
    // 窗口背景色
//    painter.setBrush(Qt::black);
//    painter.drawRect(this->rect());
}

void GameWindow::initMove(){
    for(int i = 0; i <= 5; ++i) {
        for (int j = 0; j <= 5; ++j) {
            moveto[i][j] = new QPushButton(ui -> move_interface);
            moveto[i][j] -> resize(40, 40);
            moveto[i][j] -> autoFillBackground();
            moveto[i][j] -> setText(QString("移动"));
        }
    }
    refresh();
    moveto[1][3]->move(200, 20);
    for(int i = 1; i <= 5; ++i) {
        moveto[2][i]->move((i - 1) * 100, 90);
    }
    for (int i = 3; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            moveto[i][j]->move((j - 1)*100, (i - 1)*100);
        }
    }
    for(int i = 0; i < 4; ++i) {
        player_move_image[i] = new QLabel(ui -> move_interface);
        player_move_image[i] -> hide();
    }
    player_move_image[0] -> setPixmap(QPixmap(":/character1/idle/hero120001/idle/frame0central.png"));
    player_move_image[1] -> setPixmap(QPixmap(":/character2/idle/hero40004/idle/frame0central.png"));
    player_move_image[2] -> setPixmap(QPixmap(":/character3/idle/hero120008/idle/frame0central.png"));
    player_move_image[3] -> setPixmap(QPixmap(":/character4/idle/hero120009/idle/frame0central.png"));

};

void GameWindow::initBuy(int shopsize){
    QStringList namelist;
    namelist << "力量之拳" << "驱魔大刀" << "烈火之枪" << "传送之翼" << "生命药水" << "回城卷轴";
    player_buy_image[currPlayer] -> show();
    ui -> buyPlayer -> setText(QString("玩家 %01").arg(currPlayer));
    ui -> curMoney -> setText(QString("当前金币：%01").arg(bd.pl[currPlayer].money));
    for(int i = 1; i <= 5; ++i) {
        buylist[i] -> setEnabled(true);
    }
    for (int i = 1; i <= 3; ++i) {
        int lev = bd.pl[currPlayer].checkLevel(i);
        if (i != 3) {
            if (lev < 3)
                buylist[i] -> setText(QString(namelist[i]+" lv.%01  价格：%02 金币").arg(lev + 1).arg(price[lev + 1][i] - price[lev][i] + shopsize));
            else {
                buylist[i] -> setText(QString(namelist[i]+" lv.%01  价格：%02 金币").arg(lev).arg(0));
                buylist[i] -> setEnabled(false);
            }
        }
        else {
            if (lev < 2)
                buylist[i] -> setText(QString(namelist[i]+" lv.%01  价格：%02 金币").arg(lev + 1).arg(price[lev + 1][i] - price[lev][i] + shopsize));
            else {
                buylist[i] -> setText(QString(namelist[i]+" lv.%01  价格：%02 金币").arg(lev).arg(0));
                buylist[i] -> setEnabled(false);
            }
        }
    }
    buylist[4] -> setText(QString(namelist[4]+"         价格：%01 金币").arg(1 + shopsize));
    buylist[5] -> setText(QString(namelist[5]+"         价格：%01 金币").arg(1 + shopsize));
}

//将无法移动到的位置按钮隐藏
void GameWindow::checkAvailablePos() {
    moveto[bd.pl[currPlayer].pos[0]][bd.pl[currPlayer].pos[1]] -> hide();
    for(int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            int dx = abs(i - bd.pl[currPlayer].pos[0]);
            int dy = abs(j - bd.pl[currPlayer].pos[1]);
            if (dx * dx + dy * dy > bd.pl[currPlayer].step * bd.pl[currPlayer].step) {
                moveto[i][j] -> hide();
            }
        }
    }
};

//刷新board
void GameWindow::refresh() {
    for(int i = 0; i <= 5; ++i) {
        for (int j = 0; j <= 5; ++j) {
            moveto[i][j] -> show();
        }
    }
    for (int i = 0; i <= 5; ++i) {
        moveto[0][i] -> hide();
        moveto[i][0] -> hide();
    }
    for (int i = 1; i <= 5; ++i) {
        if (i != 3) {
            moveto[1][i]->hide();
        }
    }
    for (int i = 1; i <= 5; ++i) {
        if (i != 3) {
            moveto[5][i]->hide();
        }
    }
    moveto[2][1]->hide();
    moveto[2][5]->hide();
    moveto[4][1]->hide();
    moveto[4][5]->hide();
}

void GameWindow::setPlayerNum(int numQWQ) {
    bd = board(numQWQ);
    qDebug()<< "共有" << bd.player_num << "人进行游玩";
    on_lineEdit_textChanged();
    switch(bd.player_num) {
        case 2: player_image[2] -> hide();
                player_image[3] -> hide();
                player_image[0] -> move(coordinate[1], coordinate[1]);
                player_image[1] -> move(coordinate[3], coordinate[3]);
                player_move_image[0] -> move(coordinate[1], coordinate[1]);
                player_move_image[1] -> move(coordinate[3], coordinate[3]);
                break;
        case 3: player_image[3] -> hide();
                player_image[0] -> move(coordinate[1], coordinate[1]);
                player_image[1] -> move(coordinate[1], coordinate[3]);
                player_image[2] -> move(coordinate[3], coordinate[3]);
                player_move_image[0] -> move(coordinate[1], coordinate[1]);
                player_move_image[1] -> move(coordinate[1], coordinate[3]);
                player_move_image[2] -> move(coordinate[3], coordinate[3]);
                break;
        default:player_image[0] -> move(coordinate[1], coordinate[1]);
                player_image[1] -> move(coordinate[1], coordinate[3]);
                player_image[2] -> move(coordinate[3], coordinate[3]);
                player_image[3] -> move(coordinate[3], coordinate[1]);
                player_move_image[0] -> move(coordinate[1], coordinate[1]);
                player_move_image[1] -> move(coordinate[1], coordinate[3]);
                player_move_image[2] -> move(coordinate[3], coordinate[3]);
                player_move_image[3] -> move(coordinate[3], coordinate[1]);
                break;
    }
}

void GameWindow::switchToNextPlayer() {
    for (int i = 0; i < bd.player_num; i++) {
        if (currPlayerNum[i] == 1) {
            currPlayer = i;
            ui->currPlayer->setText(QString::fromStdString(playerName[currPlayer]));
            qDebug()<< "我的回合，抽卡！";
            on_lineEdit_textChanged();
            ui -> buy -> setEnabled(true);
            ui -> mine -> setEnabled(true);
            ui -> heal -> setEnabled(true);
            ui -> attack -> setEnabled(true);
            ui -> tp -> setEnabled(true);
            ui -> move -> setEnabled(true);
            return;
        }
    }
}

bool GameWindow::judgeToEndRoll() {
    for (int i = 0; i < bd.player_num; i++) {
        if (currPlayerNum[i] == 1)
            return false;
    }
    return true;
}

void GameWindow::mineSlot() {
    //qDebug()<< "mineSlot called";
    //on_lineEdit_textChanged();
    // 当前不在mine
    if (name_all[bd.pl[currPlayer].pos[0]][bd.pl[currPlayer].pos[1]] != "mi") {
        qDebug()<< "you can't mine here";
        on_lineEdit_textChanged();
    }
    //当前位于mine
    else {
        bd.pl[currPlayer].money++;
        currPlayerNum[currPlayer] = 0;
        qDebug()<< "you get 1 coin";
        on_lineEdit_textChanged();
        updatePlayerInfo();
        // 判断是否结束当前回合
        if (judgeToEndRoll()) {
            startANewRoll();
        }
        else {
            switchToNextPlayer();
        }
    }
}

void GameWindow::healSlot() {
    //qDebug()<< "healSlot called";
    //on_lineEdit_textChanged();
    //当前不在家
    if (name_all[bd.pl[currPlayer].pos[0]][bd.pl[currPlayer].pos[1]] != "ho") {
        qDebug()<< "you can't heal here";
        on_lineEdit_textChanged();
    }
    else {
        if (bd.pl[currPlayer].pos[0] == 2 && bd.pl[currPlayer].pos[1] == 2 && bd.hm[0].master != currPlayer) {
            qDebug()<< "you can't heal here";
            on_lineEdit_textChanged();
            return;
        }
        if (bd.pl[currPlayer].pos[0] == 4 && bd.pl[currPlayer].pos[1] == 2 && bd.hm[1].master != currPlayer) {
            qDebug()<< "you can't heal here";
            on_lineEdit_textChanged();
            return;
        }
        if (bd.pl[currPlayer].pos[0] == 4 && bd.pl[currPlayer].pos[1] == 4 && bd.hm[2].master != currPlayer) {
            qDebug()<< "you can't heal here";
            on_lineEdit_textChanged();
            return;
        }
        if (bd.pl[currPlayer].pos[0] == 2 && bd.pl[currPlayer].pos[1] == 4 && bd.hm[3].master != currPlayer) {
            qDebug()<< "you can't heal here";
            on_lineEdit_textChanged();
            return;
        }

        // 当前在家，可以治疗
        if (bd.pl[currPlayer].hp < bd.pl[currPlayer].hpFloor) {
            bd.pl[currPlayer].hp++;
            updatePlayerInfo();
            currPlayerNum[currPlayer] = 0;
            qDebug()<< "you get 1 blood";
            on_lineEdit_textChanged();
            // 判断是否结束当前回合
            if (judgeToEndRoll()) {
                startANewRoll();
            }
            else {
                switchToNextPlayer();
            }
        }
        else {
            qDebug()<< "you have too much hp!";
            on_lineEdit_textChanged();
        }
    }
}

void GameWindow::tpSlot() {
    //qDebug()<< "tpSlot called";
    //on_lineEdit_textChanged();
    if (bd.pl[currPlayer].check_tp_num() == 0) {
        qDebug()<< "you have no tp";
        on_lineEdit_textChanged();
        return;
    }
    if (bd.hm[0].master != currPlayer && bd.hm[1].master != currPlayer && bd.hm[2].master != currPlayer && bd.hm[3].master != currPlayer) {
        qDebug()<< "you have no home...";
        on_lineEdit_textChanged();
        return;
    }
    // you can use tp
    tpWidget->show();
    //qDebug()<< "open tpWidget";
    //on_lineEdit_textChanged();
    for (int i = 0; i < 4; i++) {
        if (bd.hm[i].master != currPlayer)
            tpWidget->btn_hm[i]->setEnabled(false);
        else
            tpWidget->btn_hm[i]->setEnabled(true);
    }

}

void GameWindow::tpTo_hm_0() {
    qDebug()<< "tp to home 0";
    on_lineEdit_textChanged();
    player_move_image[currPlayer] -> move(coordinate[1], coordinate[1]);
    player_image[currPlayer] -> move(coordinate[1], coordinate[1]);
    bd.pl[currPlayer].pos[0] = 2;
    bd.pl[currPlayer].pos[1] = 2;
    currPlayerNum[currPlayer] = 0;
    bd.pl[currPlayer].use_tp();
    updatePlayerInfo();
    tpWidget->close();
    if (judgeToEndRoll()) {
        startANewRoll();
    }
    else {
        switchToNextPlayer();
    }
}
void GameWindow::tpTo_hm_1() {
    qDebug()<< "tp to home 1";
    on_lineEdit_textChanged();
    player_move_image[currPlayer] -> move(coordinate[1], coordinate[3]);
    player_image[currPlayer] -> move(coordinate[1], coordinate[3]);
    bd.pl[currPlayer].pos[0] = 4;
    bd.pl[currPlayer].pos[1] = 2;
    currPlayerNum[currPlayer] = 0;
    bd.pl[currPlayer].use_tp();
    updatePlayerInfo();
    tpWidget->close();
    if (judgeToEndRoll()) {
        startANewRoll();
    }
    else {
        switchToNextPlayer();
    }
}
void GameWindow::tpTo_hm_2() {
    qDebug()<< "tp to home 2";
    on_lineEdit_textChanged();
    player_move_image[currPlayer] -> move(coordinate[3], coordinate[3]);
    player_image[currPlayer] -> move(coordinate[3], coordinate[3]);
    bd.pl[currPlayer].pos[0] = 4;
    bd.pl[currPlayer].pos[1] = 4;
    currPlayerNum[currPlayer] = 0;
    bd.pl[currPlayer].use_tp();
    updatePlayerInfo();
    tpWidget->close();
    if (judgeToEndRoll()) {
        startANewRoll();
    }
    else {
        switchToNextPlayer();
    }
}
void GameWindow::tpTo_hm_3() {
    qDebug()<< "tp to home 3";
    on_lineEdit_textChanged();
    player_move_image[currPlayer] -> move(coordinate[3], coordinate[1]);
    player_image[currPlayer] -> move(coordinate[3], coordinate[1]);
    bd.pl[currPlayer].pos[0] = 2;
    bd.pl[currPlayer].pos[1] = 4;
    currPlayerNum[currPlayer] = 0;
    bd.pl[currPlayer].use_tp();
    updatePlayerInfo();
    tpWidget->close();
    if (judgeToEndRoll()) {
        startANewRoll();
    }
    else {
        switchToNextPlayer();
    }
}

void GameWindow::startANewRoll() {

    qDebug()<< "新的回合！";
    on_lineEdit_textChanged();
    int max_num = 0; // 最大的骰子号
    int t[4];
    bool move[4] = {0}; // 可以行动的玩家编号
    ui -> buy -> setEnabled(true);
    ui -> mine -> setEnabled(true);
    ui -> heal -> setEnabled(true);
    ui -> attack -> setEnabled(true);
    ui -> tp -> setEnabled(true);
    ui -> move -> setEnabled(true);
    // 决定行动玩家编号
    for (int i = 0; i < bd.player_num; i++){
        if (bd.pl[i].isAlive){
            t[i] = Dice(1).result;
            max_num = max(max_num, t[i]);
            qDebug()<< (char)('A' + i) << ":" << t[i] << " ";
            on_lineEdit_textChanged();
        }
    }
    for (int i = 0; i < bd.player_num; i++){
        move[i] = (t[i] == max_num);
        if (move[i] && bd.pl[i].isAlive) {
            qDebug()<< (char)('A' + i) << ",";
            on_lineEdit_textChanged();
            currPlayerNum[i] = 1;
        }
        else {
            currPlayerNum[i] = 0;
        }
    }
    for (int i = 0; i < bd.player_num; i++) {
        if (currPlayerNum[i] == 1) {
            currPlayer = i;
            break;
        }
    }
    qDebug()<< "can take action ";
    on_lineEdit_textChanged();
    ui->currPlayer->setText(QString::fromStdString(playerName[currPlayer]));
    //ui->textBrowser->setText("偷着乐对不队？");
    //ui->textBrowser->setText("啊对对队！");
}

string GameWindow::homeString(int checkedPlayer) {
    string s = "";
    for (int i = 0; i < 4; i++) {
        if (bd.hm[i].master == checkedPlayer) {
            s += 'A'+i;
        }
    }
    return s;
}

void GameWindow::updatePlayerInfo() {
    //player0
    ui->hp_0->setText(QString::number(bd.pl[0].hp));
    ui->lv_fist_0->setText("0.5");
    ui->lv_sword_0->setText(QString::number(bd.pl[0].checkLevel(1)));
    ui->lv_gun_0->setText(QString::number(bd.pl[0].checkLevel(2)));
    ui->lv_wing_0->setText(QString::number(bd.pl[0].checkLevel(3)));
    ui->num_tp_0->setText(QString::number(bd.pl[0].check_tp_num()));
    ui->money_0->setText(QString::number(bd.pl[0].money));
    ui->home_0->setText(QString::fromStdString(homeString(0)));
    //player1
    ui->hp_1->setText(QString::number(bd.pl[1].hp));
    ui->lv_fist_1->setText("0.5");
    ui->lv_sword_1->setText(QString::number(bd.pl[1].checkLevel(1)));
    ui->lv_gun_1->setText(QString::number(bd.pl[1].checkLevel(2)));
    ui->lv_wing_1->setText(QString::number(bd.pl[1].checkLevel(3)));
    ui->num_tp_1->setText(QString::number(bd.pl[1].check_tp_num()));
    ui->money_1->setText(QString::number(bd.pl[1].money));
    ui->home_1->setText(QString::fromStdString(homeString(1)));
    //player2
    if (bd.player_num >= 3) {
        ui->hp_2->setText(QString::number(bd.pl[2].hp));
        ui->lv_fist_2->setText("0.5");
        ui->lv_sword_2->setText(QString::number(bd.pl[2].checkLevel(1)));
        ui->lv_gun_2->setText(QString::number(bd.pl[2].checkLevel(2)));
        ui->lv_wing_2->setText(QString::number(bd.pl[2].checkLevel(3)));
        ui->num_tp_2->setText(QString::number(bd.pl[2].check_tp_num()));
        ui->money_2->setText(QString::number(bd.pl[2].money));
        ui->home_2->setText(QString::fromStdString(homeString(2)));
    }
    //player3
    if (bd.player_num == 4) {
        ui->hp_3->setText(QString::number(bd.pl[3].hp));
        ui->lv_fist_3->setText("0.5");
        ui->lv_sword_3->setText(QString::number(bd.pl[3].checkLevel(1)));
        ui->lv_gun_3->setText(QString::number(bd.pl[3].checkLevel(2)));
        ui->lv_wing_3->setText(QString::number(bd.pl[3].checkLevel(3)));
        ui->num_tp_3->setText(QString::number(bd.pl[3].check_tp_num()));
        ui->money_3->setText(QString::number(bd.pl[3].money));
        ui->home_3->setText(QString::fromStdString(homeString(3)));
    }

}


GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_lineEdit_textChanged()
{
    //qDebug() << arg1;
    ui->textBrowser->setText(text);
    text.append("\n");
    ui -> textBrowser -> moveCursor(QTextCursor::End);
}


void GameWindow::write(QString str)
{
    text = str;
}

void GameWindow::logOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    //QString text;
    //text.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " ");
    /*switch(type)
    {
        case QtDebugMsg:
            text.append("Debug:");
            break;

        case QtWarningMsg:
            text.append("Warning:");
            break;

        case QtCriticalMsg:
            text.append("Critical:");
            break;

        case QtFatalMsg:
            text.append("Fatal:");
    }*/

    text.append(msg);
    write(text);
}
