#include "endgamewidget.h"
#include "ui_endgamewidget.h"
#include <QPainter>

EndGameWidget::EndGameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndGameWidget)
{
    ui->setupUi(this);

    //setFixedSize(400, 300);
    setWindowTitle("游戏结束");
    //ui->label->setText("恭喜！你获得了胜利");

}

void EndGameWidget::paintEvent(QPaintEvent *event)
{
    QPainter painterend(this);
    // 背景图片
    painterend.drawPixmap(0,0,400,300,QPixmap(":/map/ending.png"));
    // 窗口背景色
//    painter.setBrush(Qt::black);
//    painter.drawRect(this->rect());
}

EndGameWidget::~EndGameWidget()
{
    delete ui;
}
