#include "movewidget.h"
#include "ui_movewidget.h"



MoveWidget::MoveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoveWidget)
{
    ui->setupUi(this);
}

MoveWidget::~MoveWidget()
{
    delete ui;
}
