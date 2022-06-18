#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "gamewindow.h"

#include <QDebug>



mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainWidget)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);

    //人数选择
    ui->player_num->setRange(2, 4);
    gameWindow = new GameWindow;
    //连接“开始游戏”按钮
    connect(ui->newGameBtn, &QPushButton::clicked, [=](){
        qDebug() << "开始游戏\n";
        this->hide();
        gameWindow->show();
        gameWindow->GameWindow::setPlayerNum(ui->player_num->value());
        gameWindow->startANewRoll();
        gameWindow->updatePlayerInfo();
    });

    //连接“读取存档”按钮
    connect(ui->readGameBtn, &QPushButton::clicked, [=](){
        qDebug() << "读取存档";

    });

    //连接“规则介绍”按钮
    connect(ui->rulesIntro, &QPushButton::clicked, [=](){
        qDebug() << "打开规则介绍";

    });

    //连接“退出游戏”按钮
    connect(ui->exitGame, &QPushButton::clicked, this, &QPushButton::close);

}

int mainWidget::playerNUM() {
    return ui->player_num->value();
}

mainWidget::~mainWidget()
{
    delete ui;
}

