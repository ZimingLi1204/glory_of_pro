#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "gamewindow.h"
//#include "big_class.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWidget; }
QT_END_NAMESPACE

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

    //新建游戏界面
    GameWindow * gameWindow = NULL;
    int playerNUM();


//private:
    Ui::mainWidget *ui;
};
#endif // MAINWIDGET_H
