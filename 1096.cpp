//
// Created by 29789 on 2022/11/14.
//扫雷
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int m, n, number = 1;
    while (cin >> m >> n && m != 0 && n != 0) {
        char **sts = new char *[m];
        int **s = new int *[m];
        for (int i = 0; i < m; i++) {
            sts[i] = new char[n];
            s[i] = new int[n];
            for (int j = 0; j < n; j++) {
                cin >> sts[i][j];
                s[i][j] = 0;
                if (sts[i][j] == '*')s[i][j] = -1;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == -1) {
                    for (int a = i - 1; a <= i + 1; a++) {
                        for (int b = j - 1; b <= j + 1; b++) {
                            if (a >= 0 && b >= 0 && a < m && b < n && s[a][b] != -1) {
                                s[a][b] += 1;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)cout << "Field #" << number++ << ":\n";
                if (s[i][j] == -1)cout << sts[i][j];
                else cout << s[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

