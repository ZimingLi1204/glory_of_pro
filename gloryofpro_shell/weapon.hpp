#include <time.h>
#include <stdlib.h>
#include<string>
using namespace std;

class Dice //投6面骰子
{
public:
    int num; // 投掷数量
    int result; // 投掷结果
    Dice(int n) : num(n) {
        result = 0;
        for (int i = 1; i <= num; i++) {
            result += rand()%6 + 1;
        }
    }
};

class weapon{
public:
    int type; // 武器编号 fist 0; sword 1; gun 2
    double lv; // 装备等级
    int atk; // 最大攻击力
    int price; // 装备价格
    int range; // 射程，近战为0
    weapon(double level) {
        lv = level;
    }
};

class fist: public weapon{
public:
    fist():weapon(0.5) {
        type = 0;
        atk = 1;
        range = 0;
    }

    void attack(int & targetHp) {
        targetHp -= atk;
    }
};

class sword : public weapon {
public:
    sword(double level):weapon(level){
        range = 0;
        type = 1;
        if (level == 1) {
            atk = 1;
            price = 1;
        }
        else if (level == 2) {
            atk = 2;
            price = 3;
        }
        else if (level == 3) {
            atk = 3;
            price = 5;
        }
    }

    void attack(int & targetHp) {
        if (lv == 1)
            targetHp -= atk;
        else if (lv == 2) {
            // 75% 2伤害; 25% 1伤害
            if (Dice(2).result >= 10)
                targetHp -= atk;
            else
                targetHp -= 1;
        }
        else if (lv == 3) {
            // 75% 3伤害; 25% 1伤害
            if (Dice(2).result >= 10) {
                targetHp -= atk;
            }
            else {
                targetHp -= 1;
            }
        }
    }

};

class gun : public weapon{
public:
    gun(double level):weapon(level) {
        type = 2;
        if (level == 3) {
            atk = 3;
            price = 6;
            range = 3;
        }
        else if (level == 2) {
            atk = 2;
            price = 4;
            range = 2;
        }
        else if (level == 1) {
            atk = 1;
            price = 2;
            range = 1;
        }
    }

    void attack(int & targetHp) {
        if (lv == 1) {
            // 50% 1伤害; 50% 0伤害
            if (Dice(1).result >= 4)
                targetHp -= atk;
        }
        else if (lv == 2) {
            // 50% 2伤害; 25% 1伤害; 25% 0伤害
            int t = Dice(2).result;
            if (t >= 7)
                targetHp -= atk;
            else if (t >= 4)
                targetHp -= 1;
        }
        else if (lv == 3) {
            // 50% 3伤害; 25% 2伤害; 25% 0伤害
            int t = Dice(2).result;
            if (t >= 7)
                targetHp -= atk;
            else if (t >= 4)
                targetHp -= 2;
        }
    }

};


