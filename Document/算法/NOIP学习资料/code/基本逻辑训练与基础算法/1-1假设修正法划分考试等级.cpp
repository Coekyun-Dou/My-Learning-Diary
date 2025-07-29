#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    string s = "不及格";//假设所有人都是不及格，把串的数值复制到数组
    if(a >= 60) s="及格";
    if(a >= 70) s="中等";
    if(a >= 80) s="良好";
    if(a >= 90) s="优秀";
    cout << s;
    return 0;
}
