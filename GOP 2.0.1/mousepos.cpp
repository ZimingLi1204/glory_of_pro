#include "mousepos.h"
#include <QLabel>
#include <QDebug>
#include <QString>
#include <QMouseEvent>
MousePos::MousePos(QWidget *parent)
    : QLabel{parent}
{

}

void MousePos::mousePressEvent(QMouseEvent * ev) {
    QString str = QString("当前位置 x = %1， y = %2").arg(ev -> x()).arg(ev -> y());
    qDebug() << str;
}
