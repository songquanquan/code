//
// Created by 29789 on 2022/11/18.
//
#include <iostream>
#include<vector>
#include <algorithm>
#include <string>


using namespace std;

//»ØÎÄÊý
int main() {
    int n, choose;
    cin >> n;
    vector<int> sts;
    if (n % 2 != 0) choose = 5;
    else choose = 6;
    switch (choose) {
        case 5:
            for (int s = 9; s > 0; s -= 2) {
                int co = (n - s) / 2;
                for (int i = 0; i < 10; i++) {
                    if (co - i < 10) {
                        int k = i * 10000 + (co - i) * 1000 + s * 100 + (co - i) * 10 + i;
                        sts.push_back(k);
                    }
                }
            }
            break;
        case 6:
            for (int s = 8; s >= 0; s -= 2) {
                int co = (n - s) / 2;
                for (int i = 0; i < 10; i++) {
                    if (co - i < 10) {
                        int k = i * 10000 + (co - i) * 1000 + s * 100 + (co - i) * 10 + i;
                        sts.push_back(k);
                    }
                }
            }
            for (int s = 0; s < 10; s++) {
                int co = n / 2 - s;
                for (int i = 0; i < 10; i++) {
                    if (co - i < 10) {
                        int k = s * 100000 + i * 10000 + (co - i) * 1000 + (co - i) * 100 + i * 10 + s;
                        sts.push_back(k);
                    }
                }
            }
            break;
        default:
            exit(0);
    }
    if (!sts.empty()) {
        sort(sts.begin(), sts.end());
        for (auto x: sts) {
            cout << x << endl;
        }
    } else cout << "-1";
    return 0;
}