#include "rule.h"
#include "ui_rule.h"

Rule::Rule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rule)
{
    ui->setupUi(this);

    this->setFixedSize(600, 400);
    ui->textBrowser->setFixedSize(600, 400);
    this->setWindowTitle("规则介绍");
}

Rule::~Rule()
{
    delete ui;
}
