//
// Created by 29789 on 2022/11/14.
//The 3n+1 problem

#include <iostream>

using namespace std;


int main() {
    int m, n;
    while (cin >> m >> n) {
        int a, b, best = 0;
        a = min(m, n);
        b = max(m, n);
        cout << m << " " << n << " ";
        for (int i = a; i < b; i++) {
            int x = i, e = 1;
            while (x != 1) {
                if (x % 2 != 0)x = 3 * x + 1;
                else x /= 2;
                e++;
            }
            if (e > best)best = e;
        }
        cout << best << endl;
    }
}