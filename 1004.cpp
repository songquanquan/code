//
// Created by 29789 on 2022/11/14.
//ĸţ�ݹ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
int main() {
    vector<int>s;
    int sts[55]={0,1,2,3};
    for(int i=4;i<55;i++)
    {
        sts[i]=sts[i-1]+sts[i-3];
    }
    //����2 ��ʱ
    int n=1;
    while (cin >> n && n != 0)  //���� n ��ֵ���� n ������0������룬�����˳�
    {
        cout << sts[n] << endl;
    }
    return 0;
//    int i=1;
//    while(true)
//    {
//        cin>>i;
//        if(i==0)break;
//        s.push_back(i);
//    }
//    auto max= max_element(s.begin(),s.end());
//    int *ss=new int[*max];
//    for(int j=0;j<s.size();j++)
//    {
//        ss[j]=sts[s[j]];
//    }
//    for( int k=0;k<s.size();k++)
//    {
//        cout<<ss[k]<<endl;
//    }
//
//    return 0;
}
