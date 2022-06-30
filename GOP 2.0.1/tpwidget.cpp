#include "tpwidget.h"
#include "ui_tpwidget.h"

TpWidget::TpWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TpWidget)
{
    ui->setupUi(this);

    this->setFixedSize(200,120);

    for (int i = 0; i < 4; i++) {
        btn_hm[i] = new QPushButton(this);
        btn_hm[i]->resize(100, 60);
    }
    btn_hm[0]->move(0, 0);
    btn_hm[0]->setText("A");
    btn_hm[1]->move(0, 60);
    btn_hm[1]->setText("B");
    btn_hm[2]->move(100, 60);
    btn_hm[2]->setText("C");
    btn_hm[3]->move(100, 0);
    btn_hm[3]->setText("D");

}

TpWidget::~TpWidget()
{
    delete ui;
}
