#ifndef ENDGAMEWIDGET_H
#define ENDGAMEWIDGET_H

#include <QWidget>

namespace Ui {
class EndGameWidget;
}

class EndGameWidget : public QWidget
{
    Q_OBJECT

public:    
    explicit EndGameWidget(QWidget *parent = nullptr);
    ~EndGameWidget();

private:
    Ui::EndGameWidget *ui;
};

#endif // ENDGAMEWIDGET_H
