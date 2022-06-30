#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "gamewindow.h"

#include <QDebug>
#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainWidget)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);
    this->setWindowTitle("开始界面");
    //ui -> label -> resize(142,67);
    ui -> label -> setPixmap(QPixmap(":/map/Buttons/choosebut.png"));
    ui -> label -> setScaledContents(true);
    ui -> exitGame -> setIcon(QIcon(":/map/Buttons/exitgamebut.png"));
    ui -> exitGame -> setIconSize(size());
    ui -> newGameBtn -> setIcon(QIcon(":/map/Buttons/startbut.png"));
    ui -> newGameBtn -> setIconSize(size());
    ui -> readGameBtn -> setIcon(QIcon(":/map/Buttons/readbut.png"));
    ui -> readGameBtn -> setIconSize(size());
    ui -> rulesIntro -> setIcon(QIcon(":/map/Buttons/introbut.png"));
    ui -> rulesIntro -> setIconSize(size());
    //人数选择
    ui->player_num->setRange(2, 4);
    gameWindow = new GameWindow;

    //连接“开始游戏”按钮
    connect(ui->newGameBtn, &QPushButton::clicked, [=](){
        qDebug() << "开始游戏\n";
        this->hide();
        gameWindow->show();
        gameWindow->bd = board(ui->player_num->value());
        //qDebug() << gameWindow->bd.player_num;
        gameWindow->GameWindow::setPlayerNum(ui->player_num->value());
        gameWindow->startANewRoll();
        gameWindow->updatePlayerInfo();
    });

    //连接“读取存档”按钮
    connect(ui->readGameBtn, &QPushButton::clicked, [=](){
        qDebug() << "读取存档";
        int tmpNum;
        ifstream fin("board.txt");
        fin >> tmpNum;
        gameWindow->bd.player_num = tmpNum;
        gameWindow->bd.readboard(fin);
        gameWindow->GameWindow::setPlayerNum(tmpNum);
        this->hide();
        gameWindow->show();
        gameWindow->startANewRoll();
        gameWindow->updatePlayerInfo();

    });

    connect(this->gameWindow, &GameWindow::openMainWidget, this, &QWidget::show);

    rule = new Rule();

    //连接“规则介绍”按钮
    connect(ui->rulesIntro, &QPushButton::clicked, [=](){
        //qDebug() << "打开规则介绍";
        rule->show();
    });

    //连接“退出游戏”按钮
    connect(ui->exitGame, &QPushButton::clicked, this, &QPushButton::close);

}

void mainWidget::paintEvent(QPaintEvent *event)
{
    QPainter paintermain(this);
    // 背景图片
    paintermain.drawPixmap(0,0,800,600,QPixmap(":/map/mainpic.png"));
    paintermain.drawPixmap(388,300,142,67,QPixmap(":/map/Buttons/blank.png"));
    // 窗口背景色
//    painter.setBrush(Qt::black);
//    painter.drawRect(this->rect());
}

int mainWidget::playerNUM() {
    return ui->player_num->value();
}

mainWidget::~mainWidget()
{
    delete ui;
}
