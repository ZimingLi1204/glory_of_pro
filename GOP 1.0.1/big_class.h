#ifndef BIG_CLASS_H_
#define BIG_CLASS_H_

#include<iostream>
#include<fstream>
#include<cmath>
#include"magic.cpp"
#include"weapon.cpp"
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<QDebug>
using namespace std;
//extern map<string, int> equip_type;
//extern map<string, int> arrange;
class player;
class board;
class building;
const string tap = "       ";
const int price[10][10] = {
        {0},
        {0, 1, 2, 3, 1, 1},
        {0, 3, 4, 5, 0, 0},
        {0, 5, 6},
};
const string type_weapon[3] = {
    "fist", "sword", "gun"
};

const string playerName[4] = {"玩家0", "玩家1", "玩家2", "玩家3"};
const string type_magic[3] = {
    "wing", "blood", "tp"
};
const int mask [10][10] = {
    {0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0},
};
const string name[10][10] = {
    {" ",},
    {" "," ", " ", "ss0", " ", " "},
    {" ", " ", "ho0", "mi0", "ho3", " "},
    {" ","ss1", "mi1", "bs ", "mi3", "ss3"},
    {" "," ", "ho1", "mi2", "ho2", " "},
    {" "," ", " ", "ss2", " ", " "},
};

const string name_all[10][10] = {
    {" ",},
    {" "," ", " ", "ss", " ", " "},
    {" ", " ", "ho", "mi", "ho", " "},
    {" ","ss", "mi", "bs", "mi", "ss"},
    {" "," ", "ho", "mi", "ho", " "},
    {" "," ", " ", "ss", " ", " "},
};

class building{
public:
    int pos[2]; //竖着数是x坐标, 横着是y坐标
    building(int x, int y){
        pos[0] = x; pos[1] = y;
    }
    building(){}
};
class shop : public building{
public:
    int size;
    shop(int x, int y, int s) : building(x, y) , size(s){}
    shop() {}
    virtual void showprice(player & p){}
};
class home : public building{
public:
    int master;
    home(int x, int y, int ma = -1) : building(x, y) {master = ma;}
    home() {}

};
class mine : public building{
public:
    mine(int x, int y) :building(x, y) {}
    mine() {}
};

class player{
public:
    int id; // 玩家编号
    int pos[2]; // 玩家位置
    double step; // 玩家行动力上限 初始为1
    int money; // 玩家金钱
    int hp; // 玩家血量，初始为4
    int hpFloor; // 玩家血量上限 初始为5，每击杀一名玩家，血量上限加1，血量加1
    bool isAlive; // 玩家是否存活，存活为true
    vector<weapon> wp;
    vector<magic> mg;
    player(){
        wp.push_back(fist());
        step = 1;
        money = 0;
        hp = 4;
        hpFloor = 5;
        isAlive = 1;
    };

    // use a tp
    void use_tp() {
        for (vector<magic>::iterator t = mg.begin(); t != mg.end(); t++) {
            if (t->type == 5) {
                mg.erase(t);
                break;
            }
        }
    }

    void print_status(int all){
        cout << "player " << (char)('A' + id) << " staying at " << pos[0] << " " << pos[1] << ", " << name[pos[0]][pos[1]] << " has " << money << " coins and " << hp << " hp " << endl;
        if (all){
            cout << "weapon : ";
            for (int i = 1; i <= 2; i++){
                if (checkLevel(i))
                    cout << type_weapon[i] << " level " << checkLevel(i) << ", ";
            }
            cout << " magic : ";
             for (int i = 3; i <= 5; i++){
                if (checkLevel(i) && i == 3)
                    cout << type_magic[i - 3] << " level " << checkLevel(i) << ", ";
                if (checkLevel(i) && i == 5)
                    cout << type_magic[i - 3] << " own " << check_tp_num() << ", ";
            }
            cout << endl;
        }
    }

    // 检查玩家type装备的最高lv，返回lv
    double checkLevel(int type) {
        // 检查 sword/gun
        if (type < 3 && type >= 1) {
            for (vector<weapon>::iterator t = wp.begin(); t != wp.end(); t++) {
                if (t->type == type && t->lv == 3)
                    return 3;
            }
            for (vector<weapon>::iterator t = wp.begin(); t != wp.end(); t++) {
                if (t->type == type && t->lv == 2)
                    return 2;
            }
            for (vector<weapon>::iterator t = wp.begin(); t != wp.end(); t++) {
                if (t->type == type && t->lv == 1)
                    return 1;
            }
            return 0;
        }
        // 检查 fist
        else if (type == 0)
            return 0.5;
        // 检查 wing
        else if (type == 3) {
            for (vector<magic>::iterator t = mg.begin(); t != mg.end(); t++) {
                if (t->lv == 2)
                    return 2;
            }
            for (vector<magic>::iterator t = mg.begin(); t != mg.end(); t++) {
                if (t->lv == 1)
                    return 1;
            }
            return 0;
        }
        // 检查tp 有就返回数量，无就返回0
        else if (type == 5) {
            int num_tp = 0;
            for (vector<magic>::iterator t = mg.begin(); t != mg.end(); t++) {
                if (t->type == 5)
                    return 1;
            }
            return 0;
        }
        return 0;
    }

    int check_tp_num()//检查tp数量
    {
        int num_tp = 0;
        for (vector<magic>::iterator t = mg.begin(); t != mg.end(); t++) {
            if (t->type == 5)
                num_tp++;
        }
        return num_tp;
    }

    // 玩家在商店购物  该购买行为默认合法
    //     fist    sword    gun    wing     blood     tp
    //type  0        1       2       3        4        5
    bool buy(int type, int level, int shopsize, int num = 1) {//购买类型, 等级, 店铺类型, 购买数量
        int t = 0;
        if (type <= 3)
            t = checkLevel(type);
        if (t > 0)
            money += price[t][type] * num;
        money -= (price[level][type] * num + shopsize);
        if (money >= 0) {
            if (type == 1)
                wp.push_back(sword(level));
            else if (type == 2)
                wp.push_back(gun(level));
            else if (type == 3) {
                mg.push_back(wing(level));
                step += 0.5 * (level - t);
            }
            else if (type == 4) {
                if (hp+num <= hpFloor)
                    hp += num;
                else
                    hp = hpFloor;
            }
            else if (type == 5) {        // 购买tp
                for (int i = 1; i <= num; i++)
                    mg.push_back(tp());
            }
            return true;
        }
        else {
            money += (price[level][type] * num + shopsize);
            money -= price[t][type] * num;
            return false;
        }

    }

    // 攻击判定，攻击成功时返回true，默认攻击合法
    bool attackJudge(const player & target, const weapon & arm) {
        int attackerNum = Dice(1).result; // 攻击者点数
        int targetNum = Dice(1).result;  // 被攻击者点数
        qDebug() << attackerNum << " " << targetNum << "\n";
        //Ui::GameWindow::on_lineEdit_textChanged();
        return attackerNum * arm.lv >= targetNum;
    }

    void attack(player & target, const weapon & arm) {
        // 攻击成功
        if (attackJudge(target, arm)) {
            // fist attack
            if (arm.type == 0)
                fist().attack(target.hp);
            // sword attack
            else if (arm.type == 1) {
                sword(arm.lv).attack(target.hp);
            }
            // gun attack
            else if (arm.type == 2) {
                gun(arm.lv).attack(target.hp);
            }
            qDebug() << (char)('A' + id) << " attacked " << (char)('A' + target.id) << "\n";
            //ui.on_lineEdit_textChanged();
            // 死人判定
            if (target.hp <= 0) {
                qDebug() << "player " << (char) ('A' + target.id) << " gg\n";
                target.isAlive = false;
                // 获得击杀奖励
                hpFloor++;
                hp++;
            }
        }
        //攻击失败
        else {
            qDebug() << (char)('A' + id) << " attack failed\n";
        }
    }

    double dis(const player p){
        return sqrt((p.pos[0] - pos[0]) * (p.pos[0] - pos[0]) + (p.pos[1] - pos[1]) * (p.pos[1] - pos[1]));
    }

};

class bigshop : public shop{
public:
    bigshop(int x, int y, int s = 2) : shop(x, y, s){}
    bigshop() {size = 2;}
    void showprice(player & p){
        cout << "                sword    gun    wing    blood    tp " << endl;
        string sout;
        for (int i = 1; i <= 3; i++){
            sout = sout + "level" + (char)(i + '0') + " cost";
            for (int j = 1; j <= 5; j++){
                sout += tap;
                if (price[i][j] == 0)
                    sout += 'N';
                else if (j <= 3){
                    int lv = p.checkLevel(j);
                    if (lv >= i)
                        sout += 'N';
                    else
                        sout += (char)(price[i][j] - price[lv][j] + '0');
                }
                else
                {
                    sout += (char)(price[i][j] + '0');
                }
            }
            sout += '\n';
        }
        cout << sout;
    }
};
class smallshop : public shop{
public:
    smallshop(int x, int y, int s = 1) : shop(x, y, s){}
    smallshop() {size = 1;}
    void showprice(player & p){
        cout << "                sword    gun    wing    blood    tp " << endl;
        string sout;
        for (int i = 1; i <= 3; i++){
            sout = sout + "level" + (char)(i + '0') + " cost";
            for (int j = 1; j <= 5; j++){
                sout += tap;
                if (price[i][j] == 0)
                    sout += 'N';
                else if (j <= 3){
                    int lv = p.checkLevel(j);
                    if (lv >= i)
                        sout += 'N';
                    else
                        sout += (char)(price[i][j] - price[lv][j] + '0') + (lv == 0);

                }
                else
                {
                    sout += (char)(price[i][j] + '0' + 1);
                }
            }
            sout += '\n';
        }
        cout << sout;
    }
};


class board
{
public:
    player pl[4];
    bigshop bs;
    smallshop ss[4];
    home hm[4];
    mine mi[4];
    int player_num;
    // 轮次数
    int round;

    // 初始化
    board(int player) :bs (3, 3){
//        equip_type.insert(make_pair("fist", 0));
//        equip_type.insert(make_pair("sword", 1));
//        equip_type.insert(make_pair("gun", 2));
//        equip_type.insert(make_pair("wing", 3));
//        equip_type.insert(make_pair("blood", 4));
//        equip_type.insert(make_pair("tp", 5));
        player_num = player;
        if(player_num == 2) {
            hm[0].master = 0;
            hm[1].master = -1;
            hm[2].master = 1;
            hm[3].master = -1;
        }
        else {
            for (int i = 0; i < player_num; i++) {
                if (player_num == 3) {
                    hm[3].master = -1;
                 }
                hm[i].master = i;
            }
        }
        for (int i = 0; i < player_num; i++) {
            pl[i].id = i;
        }
        if (player_num == 4 || player_num == 3)
        {
            pl[0].pos[0] = 2; pl[0].pos[1] = 2; // A
            pl[1].pos[0] = 4; pl[1].pos[1] = 2; // B
            pl[2].pos[0] =4; pl[2].pos[1] = 4; // C
            if (player_num == 4)
                pl[3].pos[0] = 2; pl[3].pos[1] = 4; // D
        }
        else if (player_num == 2)
        {
            pl[0].pos[0] = 2; pl[0].pos[1] = 2; // A
            pl[1].pos[0] = 4; pl[1].pos[1] = 4; // C
        }

        ss[0].pos[0] = 1; ss[0].pos[1] = 3;
        ss[1].pos[0] = 3; ss[1].pos[1] = 1;
        ss[2].pos[0] = 5; ss[2].pos[1] = 3;
        ss[3].pos[0] = 3; ss[3].pos[1] = 5;

        hm[0].pos[0] = 2; hm[0].pos[1] = 2;
        hm[1].pos[0] = 4; hm[1].pos[1] = 2;
        hm[2].pos[0] = 4; hm[2].pos[1] = 4;
        hm[3].pos[0] = 2; hm[3].pos[1] = 4;

        mi[0].pos[0] = 2; mi[0].pos[1] = 3;
        mi[1].pos[0] = 3; mi[1].pos[1] = 2;
        mi[2].pos[0] = 4; mi[2].pos[1] = 3;
        mi[3].pos[0] = 3; mi[3].pos[1] = 4;

        bs.pos[0] = 3; bs.pos[1] = 3;
        round = 0;
    }

    // 打印地图
    void print()
    {
        round++;
        int i, j;
        cout << "############################ " << endl;
        cout << "          ROUND " << round << endl;
        cout << "    1    2    3    4    5" << endl;
        for (i = 1; i <= 5; i++)
        {
            cout << i << " ";
            for (j = 1; j <= 5; j++){
                if (mask[i][j] == 1)
                    cout << " " << name[i][j] << " ";
                else
                    cout << "     ";
            }
            cout << endl;
            cout << endl;
        }
        cout << "----------------------------" << endl;
        for (i = 0; i < player_num; i++){
            if (pl[i].isAlive)
                pl[i].print_status(1);
        }

    }
    void saveboard()
    {
        ofstream fout("board.txt");
        fout << player_num << " " << round << " ";
        for (int j = 0; j < 4; j++)
            fout << hm[j].master  << " ";
        for (int j = 0; j < player_num; j++){
            player & p1 = pl[j];
            fout << (int)p1.isAlive << " ";
            if ((int)p1.isAlive)
            {
                fout << p1.pos[0] << " " << p1.pos[1] << " " << p1.money << " " << p1.hp << " " << p1.step << " " << p1.hpFloor << " "; //顺序读入
                fout << p1.wp.size() << " ";
                //cout << p1.wp.size() << endl;
                for(int k = 0; k < p1.wp.size(); k++)
                    fout << p1.wp[k].type << " " << p1.wp[k].lv << " ";
                fout << p1.mg.size() << " ";
                for (int k = 0; k < p1.mg.size(); k++)
                    fout << p1.mg[k].type << " " << p1.mg[k].lv << " ";
            }
        }
    }

    void readboard(ifstream & fin)
    {
        fin >> round;
        //读取数据初始化
        for (int i = 0; i < 4; i++)
            fin >> hm[i].master;
        for (int i = 0; i < player_num; i++)
        {
            bool alive;
            fin >> alive;
            pl[i].isAlive = alive;
            if (alive)
            {
                player & p = pl[i];
                fin >> p.pos[0] >> p.pos[1] >> p.money >> p.hp >> p.step >> p.hpFloor; //顺序读入
                cout << (char)('A' + i) << " :";
                //weapon
                int weapon_num;
                fin >> weapon_num;
                double level;
                int type;
                for (int j = 0; j < weapon_num; j++)
                {
                    fin >> type >> level;
                    if (type == 1)
                        p.wp.push_back(sword(level));
                    else if (type == 2)
                        p.wp.push_back(gun(level));
                }
                //magic
                int magic_num;
                fin >> magic_num;
                for (int j = 0; j < magic_num; j++)
                {
                    fin >> type >> level;
                    if (type == 3)
                        p.mg.push_back(wing(level));
                    else
                        p.mg.push_back(tp());
                }
            }//if alive
        }//readplayer
    }//readboard
};

#endif // BIG_CLASS_H
