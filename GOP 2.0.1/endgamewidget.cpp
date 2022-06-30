#include "endgamewidget.h"
#include "ui_endgamewidget.h"

EndGameWidget::EndGameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndGameWidget)
{
    ui->setupUi(this);

    //setFixedSize(400, 300);
    setWindowTitle("游戏结束");
    ui->label->setText("恭喜！你获得了胜利");

}

EndGameWidget::~EndGameWidget()
{
    delete ui;
}
