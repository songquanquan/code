//
// Created by 29789 on 2022/11/15.
//IP еп╤о
#include<iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string a;
    while (cin >> a) {
        vector<int> sts;
        string over = "Y";
        sts.push_back(-1);
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '.') {
                sts.push_back(i);
            }
        }
        sts.push_back(a.length());

        for (int i = 0; i < sts.size()-1 ; i++) {
            string ma;
            for (int j = sts[i] + 1; j < sts[i + 1]; j++) {
                ma += a[j];
            }
            int num;
            stringstream str;
            str << ma;
            str >> num;
            if (num >0 && num < 255) {}
            else {
                over ="N";
                break;
            }
        }
        cout << over << endl;
    }
}