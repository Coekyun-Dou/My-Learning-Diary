#include<bits/stdc++.h>
using namespace std;
int main() {
    // 基础设置
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;

    queue<char> q1, q2;
    long long cnt1 = 0, cnt2 = 0;

    // 1. 先把糖果全部“装弹”进入队列
    for (char c : s1) q1.push(c);
    for (char c : s2) q2.push(c);

    // 2. 开始对拼，直到其中一人没糖
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
