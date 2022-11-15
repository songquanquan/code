//
// Created by 29789 on 2022/11/14.
//DNA
#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int m = 0; m < n; m++) {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < b; i++) {
       if (i==0){
           cout << "X";
           for (int p = 0; p < a - 2; p++) { cout << " "; }
           cout << "X" << endl;
       }
            for (int j = 0; j < a-1; j++) {
                for (int k = 0; k < a; k++) {
                    if (k == j+1  || k == a - j -2)cout << "X";
                    else cout << " ";
                }
                cout << endl;
            }
        }
        cout<<endl;
    }
}