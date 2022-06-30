#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "gamewindow.h"
#include "rule.h"
#include <fstream>
#include <QString>
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

    // 规则说明文档

    //新建游戏界面
    GameWindow * gameWindow = NULL;
    Rule * rule = NULL;
    int playerNUM();


//private:
    Ui::mainWidget *ui;
};
#endif // MAINWIDGET_H
