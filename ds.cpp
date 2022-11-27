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
                "����", "����", "Jack", "Rose", "��һ��", "Lucy", "Alice", "����"
        };
string goods[] =
        {
                "������˿", "������", "������˿", "��������", "������",
                "������", "����˿", "������", "���ļ���", "�˳���", "�ƹ�",
                "ǧ�Ŷ���", "�����ܲ���", "���Ų�", "�峴źƬ", "���Ӽ���",
                "��������", "������", "�����", " ������", "С�ײ�������",
                "������", "�㶹��", "˿��", "ë��", "���", "������",
                "���Ӽ���", "��������", "������", "���м�",
        };


class Desk {
public:
    Desk(int x = 140, int y = 120, int z = 78) : length(x), width(y), height(z) {
        //cout << "Desk����" << endl;
    }

    ~Desk() {
        // cout << "Desk����" << endl;
    }

    void place(const string &g) {
        Goods.push_back(g);
        cout << g << "���óɹ�" << endl;
    }

    void looklook() {
        for (auto x: Goods) {
            cout << x << ' ';
        }
        if (Goods.empty()) cout << "û�ж���������";
        cout << endl;
    }

    void clearall() {
        if (Goods.empty()) cout << "û�ж���������";
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
        // cout << "Stool����" << endl;
    }

    ~Stool() {
        //cout << "Stool����" << endl;
    }

    void sitDown(int i) {
        name = names[i];
        cout << name << "������" << endl;
    }

    void leave() {
        if (name == "no")cout << "nobody" << endl;
        else {
            cout << name << "�뿪��" << endl;
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
        // cout << "DiningRoom����" << endl;
    }

    ~DiningRoom() {
        //cout << "DiningRoom����" << endl;
        delete desk;
        delete[] stool;
    }

    Desk *desk = new Desk;
    Stool *stool = new Stool[8];
};

void test02() {
    cout << "1.������ʲô��" << endl;
    cout << "2.�������" << endl;
    cout << "3.˭Ҫ�뿪" << endl;
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
                cout << "��������" << endl;
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
    cout << "��ʼ�ϲ�:" << endl;
    char n = 1;
    cout << "����0�����ϲ�,��������ϲ�" << endl;
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