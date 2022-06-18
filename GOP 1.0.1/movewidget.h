#ifndef MOVEWIDGET_H
#define MOVEWIDGET_H

#include <QWidget>

//#include "big_class.cpp"

namespace Ui {
class MoveWidget;
}

class MoveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MoveWidget(QWidget *parent = nullptr);
    ~MoveWidget();

private:
    Ui::MoveWidget *ui;
};

#endif // MOVEWIDGET_H
