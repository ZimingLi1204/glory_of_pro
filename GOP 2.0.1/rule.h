#ifndef RULE_H
#define RULE_H

#include <QWidget>

namespace Ui {
class Rule;
}

class Rule : public QWidget
{
    Q_OBJECT

public:
    explicit Rule(QWidget *parent = nullptr);
    ~Rule();

private:
    Ui::Rule *ui;
};

#endif // RULE_H
