#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "movewidget.h"
#include "tpwidget.h"
#include "endgamewidget.h"
#include "attackwidget.h"
#include "mousepos.h"
#include "movewidget.h"
#include <QPaintEvent>
#include "big_class.h"
#include <QPushButton>
#include <QLabel>
#include <string>
#include <QTextBrowser>

const int coordinate[5] = {0, 100, 200, 300, 400};

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:

    int currPlayer; // 当前行动的玩家编号
    int currPlayerNum[4]; // 本回合可以行动的玩家编号
    board bd;
    QPushButton * moveto[6][6];
    QPushButton * buylist[6];
    QLabel * player_image[4];
    QLabel * player_move_image[4];
    QLabel * player_buy_image[4];
    bool buy_happen = false;
    AttackWidget * attackWidget = NULL;
    MoveWidget * moveWidget = NULL;
    TpWidget * tpWidget = NULL;
    EndGameWidget * endGameWidget = NULL;
    explicit GameWindow(QWidget *parent = nullptr);
    //GameWindow(int numQWQ,QWidget *parent = nullptr);
    ~GameWindow();

    void setPlayerNum(int numQWQ);

    // 开始一个新的回合，决定行动资格
    void startANewRoll();

    //让下一个玩家行动
    void switchToNextPlayer();

    // 判定是否所有人都已经行动，若是，开始新回合
    bool judgeToEndRoll();

    //更新玩家信息
    void updatePlayerInfo();

    // 挖矿的槽函数
    void mineSlot();

    // 治疗的槽函数
    void healSlot();

    // 传送的槽函数
    void tpSlot();
    void tpTo_hm_0();
    void tpTo_hm_1();
    void tpTo_hm_2();
    void tpTo_hm_3();

    //设定背景的函数
    void paintEvent(QPaintEvent *);

    //初始化move界面
    void initMove();

    //将不能到的地方隐藏
    void checkAvailablePos();

    //初始化buy界面
    void initBuy(int shopsize);

    //刷新board
    void refresh();

    //输出当前玩家的家的字符串
    string homeString(int checkedPlayer);

    //输出控制台
    static void write(QString str);
    static void logOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    void on_lineEdit_textChanged();



signals:
    //自定义信号，关闭游戏界面
    void GameWindowClose();
    void endGameSignal();


private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
