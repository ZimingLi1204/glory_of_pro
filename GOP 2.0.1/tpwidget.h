#ifndef TPWIDGET_H
#define TPWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class TpWidget;
}

class TpWidget : public QWidget
{
    Q_OBJECT

public:
    // 选择tp目标
    QPushButton * btn_hm[4];

    explicit TpWidget(QWidget *parent = nullptr);
    ~TpWidget();

private:
    Ui::TpWidget *ui;
};

#endif // TPWIDGET_H
