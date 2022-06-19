class magic{
public:
    double lv; // 等级，wing特有
    double step; // 行动力，wing特有
    int type; // magic编号
    int price; // 价格
    magic(){
        lv = 0;
    }

};

class wing : public magic{
public:
    wing(double level):magic() {
        lv = level;
        type = 3;
        if (lv == 1) {
            price = 3;
            step = 0.5;
        }
        else if (lv == 2) {
            price = 5;
            step = 1;
        }
    }

};

class blood : public magic{
public:
    blood():magic(){
        type = 4;
        price = 1;
    }
};

class tp : public magic{
public:
    tp():magic(){
        type = 5;
        price = 1;
    }
};



