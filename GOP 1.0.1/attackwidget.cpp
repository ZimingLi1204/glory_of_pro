#include "attackwidget.h"
#include "ui_attackwidget.h"

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

AttackWidget::~AttackWidget()
{
    delete ui;
}
