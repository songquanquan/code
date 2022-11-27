//
// Created by 29789 on 2022/11/27.
//

#include <iostream>
#include<vector>
#include <algorithm>
#include <string>
#include<ctime>

using namespace std;
string names[] =
        {
                "张三", "李四", "Jack", "Rose", "孙一洋", "Lucy", "Alice", "马云"
        };
string goods[] =
        {
                "鱼香肉丝", "东坡肉", "辣土豆丝", "红柿炒蛋", "椒炒肉",
                "辣豆腐", "干肉丝", "烧鲫鱼", "煸四季豆", "菜炒蛋", "黄瓜",
                "千张豆腐", "豆米萝卜干", "外婆菜", "清炒藕片", "辣子鸡丁",
                "宫保鸡丁", "红烧肉", "火锅肉", " 冬瓜汤", "小白菜炖豆腐",
                "西兰花", "豌豆尖", "丝瓜", "毛菜", "酸菜", "炒三鲜",
                "辣子鸡丁", "酱爆茄子", "西蓝花", "白切鸡",
        };


class Desk {
public:
    Desk(int x = 140, int y = 120, int z = 78) : length(x), width(y), height(z) {
        //cout << "Desk构建" << endl;
    }

    ~Desk() {
        // cout << "Desk析构" << endl;
    }

    void place(const string &g) {
        Goods.push_back(g);
        cout << g << "放置成功" << endl;
    }

    void looklook() {
        for (auto x: Goods) {
            cout << x << ' ';
        }
        if (Goods.empty()) cout << "没有东西在桌上";
        cout << endl;
    }

    void clearall() {
        if (Goods.empty()) cout << "没有东西在桌上";
        else Goods.clear();
    }

    vector<string> Goods;
private:
    int length;
    int width;
    int height;
};

class Stool {
public:
    Stool(int x = 40, int y = 40, int z = 40, string *p = nullptr) : length(x), width(y), height(z) {
        // cout << "Stool构建" << endl;
    }

    ~Stool() {
        //cout << "Stool析构" << endl;
    }

    void sitDown(int i) {
        name = names[i];
        cout << name << "坐下了" << endl;
    }

    void leave() {
        if (name == "no")cout << "nobody" << endl;
        else {
            cout << name << "离开了" << endl;
            name = "no";
        }
    }

    string name = "no";
private:
    int length;
    int width;
    int height;
};

class DiningRoom {
public:
    DiningRoom() {
        // cout << "DiningRoom构建" << endl;
    }

    ~DiningRoom() {
        //cout << "DiningRoom析构" << endl;
        delete desk;
        delete[] stool;
    }

    Desk *desk = new Desk;
    Stool *stool = new Stool[8];
};

void test02() {
    cout << "1.看看有什么菜" << endl;
    cout << "2.清空桌面" << endl;
    cout << "3.谁要离开" << endl;
}

void test03(DiningRoom &diningRoom) {
    int choose = -1;
    string name;
    while (cin >> choose) {
        test02();
        int i = -1;
        switch (choose) {
            case 1:
                diningRoom.desk->looklook();
                break;
            case 2:
                diningRoom.desk->clearall();
                break;
            case 3:
                cout << "输入名字" << endl;
                cin >> name;
                for (int j = 0; j < 8; j++) {
                    if (name == diningRoom.stool[j].name) {
                        i = j;
                        break;
                    }
                }
                if (i != -1)diningRoom.stool[i].leave();
                break;
            default:
                exit(0);
        }
    }
}


void test01(DiningRoom &diningRoom) {
    cout << "开始上菜:" << endl;
    char n = 1;
    cout << "输入0结束上菜,按任意键上菜" << endl;
    n = getchar();
    while (n != 48) {
        diningRoom.desk->place(goods[rand() % 31]);
        n = getchar();
    }
}

int main() {
    srand((unsigned int) time(nullptr));
    DiningRoom diningRoom;
    for (int i = 0; i < 8; i++) {
        diningRoom.stool[i].sitDown(i);
    }
    test01(diningRoom);
    //  cout << diningRoom.stool;
    test02();
    test03(diningRoom);
    return 0;
}