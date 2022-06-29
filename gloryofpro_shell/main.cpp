#include<iostream>
#include<cmath>
#include<set>
#include "big_class.hpp"
using namespace std;

bool board::cin_action(){
    int x, y, max_num = 0;
    int t[4] ={0};
    bool move[4] = {0};
    for(int i = 0; i < player_num; i++){
        if (pl[i].isAlive){
            t[i] = Dice(1).result;
            max_num = max(max_num, t[i]);
            cout << (char)('A' + i) << ":" << t[i] << " ";   
        }
    }
    cout << endl;
    for (int i = 0; i < player_num; i++){
        move[i] = (t[i] == max_num);
        if (move[i])
            cout << (char)('A' + i) << ",";   
    }
    cout << "can take action " << endl;
    cout << "input action" << endl;
    //move , buy, attack, recover, gohome, save_board
    for (int i = 0; i < player_num; i++){
        if (!move[i] || !pl[i].isAlive)
            continue;
        player & p = pl[i];
        cout << (char)('A' + i) << " :";
        //在qt里面输出状态最好改成一直出现, 不断更新的那种状态, 显示money, hp, weapon
        string action;
        cin >> action;
        if (action == "move"){
            while(1){
                cout << "move to: "; 
                cin >> x >> y;
                int dx = abs(x - p.pos[0]); int dy = abs(y - p.pos[1]);
                if (!mask[x][y]) //out of range
                    cout << "out of board"  << endl;
                else if (dx * dx + dy * dy > p.step * p.step){
                    cout << "out of range" << endl;
                }
                else 
                    break;
            }
            p.pos[0] = x;
            p.pos[1] = y;
            cout << (char)('A' + i) << " move to " <<  p.pos[0] << " " << p.pos[1] << ", " << name[p.pos[0]][p.pos[1]] << endl; 
            //判断home
            bool flag = 0; int home_num = 0;
            if (name_all[x][y] == "ho"){
                for (int j = 0; j < 4; j++){ // find which home
                    if (hm[j].pos[0] == x && hm[j].pos[1] == y){
                        home_num = j;
                        break;
                    }
                }
                home & hme = hm[home_num];
                if (hme.master != i){
                    for (int j = 0; j < 4; j++){//find if person in home
                        if (j == i)
                            continue;
                        if(pl[j].pos[0] == x && pl[j].pos[1] == y)
                            flag = true;
                    }
                    if (!flag){ //home 没人                
                        hme.master = i;
                        cout << (char)('A' + i) << " invade home" << home_num << endl; 
                    }
                }
            }//判断home
        }
        else if (action == "mine"){//mine
            if (name_all[p.pos[0]][p.pos[1]] != "mi"){
                cout << "you can't mine here" << endl;
                continue;
            }
            p.money++;
            cout << (char)('A' + i) << " mine at " <<  p.pos[0] << " " << p.pos[1] << ", " << name[p.pos[0]][p.pos[1]] << " and has " << p.money << " coins " << endl;
        }
        else if (action == "buy") {
            int shopsize;shop * s;
            if (name_all[p.pos[0]][p.pos[1]] != "ss" && name_all[p.pos[0]][p.pos[1]] != "bs"){
                cout << "you can't buy here" << endl;
                continue;
            }
            else if (name_all[p.pos[0]][p.pos[1]] == "ss")
                s = new smallshop();
            else if (name_all[p.pos[0]][p.pos[1]] == "bs")
                s = new bigshop();
            string buy; int lv;
            cout << (char)('A' + i) << " buy at " <<  p.pos[0] << " " << p.pos[1] << " in shop " << name[p.pos[0]][p.pos[1]] << endl;
            //展示商品
            s->showprice(p);
            cout << "buy what ? input item and level(except blood and tp), input 'nothing' to break" << endl;
            while (1){
                cin >> buy;
                if (buy == "nothing")
                    break;
                if (type[buy] <= 3)
                    cin >> lv;
                else
                    lv = 1;
                if (type.count(buy) == 0 || price[lv][type[buy]] == 0){
                    cout << "illegal input" << endl;
                    continue;
                }
                else if (p.checkLevel(type[buy]) > lv && type[buy] <= 3){
                    cout << "can't buy low level item(except tp)" << endl;
                    continue;
                }
                else if (p.checkLevel(type[buy]) == lv && type[buy] <= 3){
                    cout << "can't buy same item(except tp)" << endl;
                    continue;
                }
                else if (buy == "blood" && p.hp == p.hpFloor){
                    cout << "max hp, can't buy blood" << endl;
                    continue;
                }
                //要考虑已有物品的价值, 这里如果没有物品等级为0, 正好对应价格= 0
                else if (price[lv][type[buy]] + (2 - s->size) > p.money + price[(int)p.checkLevel(type[buy])][type[buy]]){
                        cout << "have no money" << endl;
                        continue;
                }
                p.buy (type[buy], lv, s);
                cout << (char)('A' + i) << " buy " << buy << " with level " << lv << " and has " << p.money << " coins";
                if (buy == "blood")
                    cout << " and recover to " << p.hp << " hp ";
                cout << endl; 
            }
        }
        else if (action == "attack"){
            char att;
            string wea;
            cout << "attack whom, use what weapon;";
            int failed_time = 0;
            while(1){ //失败次数过多不再尝试   
                if (failed_time > 3){
                    cout << "failed to many times" << endl;
                    break;
                }
                failed_time++;
                cin >> att >> wea;
                if (att - 'A' - i == 0){
                    cout << "can't attack yourself" << endl;
                }
                else if (att - 'A' > 3 || att - 'A' < 0){
                    cout << "no player names" << att << endl;
                } 
                else if (!pl[att - 'A'].isAlive){
                    cout << "target has already died" << endl;
                }
                else if (type.count(wea) == 0){
                    cout << "illegal weapon" << endl;
                }
                else if (p.checkLevel(type[wea]) == 0 || type[wea] > 2){
                    cout << "don't have this weapon" << endl;
                }
                else{// success attack
                    int lv = p.checkLevel(type[wea]);
                    player & tar = pl[att - 'A'];
                    vector<weapon>::iterator t;
                    for (t = p.wp.begin(); t != p.wp.end(); t++) {
                        if (t->type == type[wea] && t->lv == lv)
                            break;
                    }
                    if (p.dis(tar) > t->range)
                    {
                        cout << "out of range" << endl;
                        continue;
                    }
                    p.attack(tar, *t); 
                    cout << (char)('A' + i) << " has " << p.hp << " hp " << endl;
                    cout << att << " has " << tar.hp << " hp " << endl;
                    break;
                }
            }//attack循环
        }
        else if (action == "recover"){//recover
            if (name_all[p.pos[0]][p.pos[1]] != "ho"){
                cout << "you can't recover here" << endl;
                continue;
            }
            int home_num;
            for (int j = 0; j < 4; j++){ // find which home
                if (hm[j].pos[0] == p.pos[0]&& hm[j].pos[1] == p.pos[1]){
                    home_num = j;
                    break;
                }
            }
            if (hm[home_num].master != i){
                cout << "not your home, first invade it" << endl;
                continue;
            }
            else if (p.hp == p.hpFloor){
                cout << "max hp, can't recover anymore" << endl;
                continue;
            }
            p.hp++;
            cout << (char)('A' + i) << " recover at " <<  p.pos[0] << " " << p.pos[1] << ", " << name[p.pos[0]][p.pos[1]] << " and has " << p.hp << " hp " << endl;
        }
        else if (action == "gohome"){
            if ((int)p.checkLevel(5) == 0){
                cout << "You don't have tp " << endl;
                continue;
            }
            set<int> myhome; int num = 0;
            for (int j = 0; j < 4; j++){ // find which home
                if (hm[j].master == i){
                    myhome.insert(j);
                    num++;
                }
            }
            if (num == 0)
                cout << "you don't have any home" << endl;
            else{
                cout << "choose one home" << endl;
                for (set<int>::iterator t = myhome.begin(); t != myhome.end(); t++){
                    cout << "home" << *t << ", ";
                }
                cin >> num;
                if (myhome.find(num) != myhome.end()){
                    vector<magic>::iterator t;
                    for (t = p.mg.begin(); t != p.mg.end(); t++) {
                        if (t->type == 5)
                            break;
                    }
                    p.mg.erase(t);
                    cout << (char)('A' + i) << " moves to home" << num << endl; 
                    p.pos[0] = hm[num].pos[0]; p.pos[1] = hm[num].pos[1];
                }
                else
                    cout << "illegal move" << endl;
            }
        }
        else if (action == "save"){
            saveboard();
            cout << "quit or not. 0 for quit" << endl;
            int q;
            cin >> q;
            if (!q)
                return 1;
        }   
        else if (action == "quit")
            return 1;
        else
            cout << "waste one time" << endl;
    }
    return 0;
}

bool board:: judge_end(){
    int i, num = 0, last;
    for (i = 0; i < player_num; i++){
        if (pl[i].isAlive){
            num++;
            last = i;
        }
    }
    if (num == 0){
        cout << "everyone died, gameover" << endl;
        return true;
    }
    else if (num == 1){
        cout << (char)('A' + last) << " win, gameover" << endl;
        return true;
    }
    return false;
}

void play()
{
    int player_num;string s;
    BEGIN:
    cout << "new game / read game" << endl;
    cin >> s;
    board bd(4);
    if (s == "new"){
        cout << "输入玩家数量" << endl;
        cin >> player_num;//2, 3, 4
        bd = board(player_num);
    }
    else{
        ifstream fin("board.txt");
        if (!fin){
            cout << "没有存盘!" << endl;
            goto BEGIN;
        }
        fin >> player_num;
        bd = board (player_num);
        bd.readboard(fin);
    }
    while(1){
        bd.print();
        bool l1 = bd.cin_action();
        bool l2 = bd.judge_end();
        if (l1 || l2){
            cout << "再来一盘? (0退出)" << endl;
            int judge;
            cin >> judge;
            if (judge)
                goto BEGIN;
            else
                break;
        }
    }//每个round循环
}

int main(){
    srand((int)time(0));
    play();
    return 0;
}

