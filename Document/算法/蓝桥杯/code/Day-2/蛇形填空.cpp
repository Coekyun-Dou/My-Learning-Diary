#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m=20,n=20,num=0;
	int cnt = m + n - 1;//确定哪一斜排
	for(int i=1;i < cnt;i++)
	{
		num+=i;
	 } 
	  // 确定那一排是从上往斜下填还是从下往斜上填
    if (cnt % 2 == 0) {
        // 偶数是从右上往下填
        int row = 1;
        while (row <= m) {
            num++;
            row++;
        }
    } else {
        int row = cnt;
        while (row >= m) {
            num++;
            row--;
        }
    }
    cout << num << endl;
    return 0;
}
