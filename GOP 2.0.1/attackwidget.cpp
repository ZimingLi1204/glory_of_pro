#include "attackwidget.h"
#include "ui_attackwidget.h"
#include <QPainter>
AttackWidget::AttackWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttackWidget)
{
    ui->setupUi(this);

    setFixedSize(200, 120);
    setWindowTitle("攻击界面");

    for (int i = 0; i < 4; i++) {
        btn_target[i] = new QPushButton(this);
        btn_target[i]->resize(100, 60);
        btn_target[i]->setText(QString::fromStdString(playerName[i]));
    }
    btn_target[0]->move(0, 0);
    btn_target[1]->move(0, 60);
    btn_target[2]->move(100, 60);
    btn_target[3]->move(100, 0);

}
void AttackWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // 背景图片
    //painter.drawPixmap(0,150,450,450,QPixmap(":/map/GOPmap.png"));
    painter.drawPixmap(25,5,50,50,QPixmap(":/character1/idle/char0.png"));
    painter.drawPixmap(25,65,50,50,QPixmap(":/character2/idle/char1.png"));
    painter.drawPixmap(125,65,50,50,QPixmap(":/character3/idle/char2.png"));
    painter.drawPixmap(125,5,50,50,QPixmap(":/character4/idle/char3.png"));
    // 窗口背景色
//    painter.setBrush(Qt::black);
//    painter.drawRect(this->rect());
}
AttackWidget::~AttackWidget()
{
    delete ui;
}
