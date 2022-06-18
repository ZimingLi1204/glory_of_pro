#ifndef MOUSEPOS_H
#define MOUSEPOS_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
class MousePos : public QLabel
{
    Q_OBJECT
public:
    explicit MousePos(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *ev);



signals:

};

#endif // MOUSEPOS_H
