#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	queue<char>q1,q2;
	long long cnt1=0,cnt2=0;
	for(int i=0;i<s1.size();i++)
	{
		q1.push(s1[i]);
	}
	for(int i=0;i<s2.size();i++)
	{
		q2.push(s2[i]); 
	}
	while (!q1.empty() && !q2.empty()) {
        char blue = q1.front(); // 查看队首，先不弹出
        char red = q2.front();

        if (blue == red) { // 平局
            cnt1++; cnt2++;
            q1.pop(); // 两人都消耗掉这颗糖
            q2.pop();
        } 
        else if ((blue == 'R' && red == 'G') || 
                 (blue == 'G' && red == 'B') || 
                 (blue == 'B' && red == 'R')) { // 小蓝赢
            cnt1++;    // 赢家吃掉一颗
            q2.pop();  // 输家（小红）弹出队首
            // 注意：这里 q1 不 pop，意味着下次循环 blue 还是这颗糖
        } 
        else { // 小红赢
            cnt2++;
            q1.pop();  // 输家（小蓝）弹出队首
            // 注意：这里 q2 不 pop
        }
    }

    // 3. 游戏结束，吃掉自己队列里剩下的
    while (!q1.empty()) {
        cnt1++;
        q1.pop();
    }
    while (!q2.empty()) {
        cnt2++;
        q2.pop();
    }

    cout << cnt1 << "\n" << cnt2 << endl;

    return 0;
}
