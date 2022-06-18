#ifndef ATTACKWIDGET_H
#define ATTACKWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <big_class.h>

namespace Ui {
class AttackWidget;
}

class AttackWidget : public QWidget
{
    Q_OBJECT

public:
    QPushButton * btn_target[4];

    explicit AttackWidget(QWidget *parent = nullptr);
    ~AttackWidget();

private:
    Ui::AttackWidget *ui;
};

#endif // ATTACKWIDGET_H
