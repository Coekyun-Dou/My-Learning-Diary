#include <bits/stdc++.h>
using namespace std;
const int N = 55;
#define pii pair<int, int>
#define ft first
#define sd second
int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}; // 方向数组，用于表示8个方向的横坐标变化
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1}; // 方向数组，用于表示8个方向的纵坐标变化
char g[N][N]; // 存储地图信息的二维数组
int t[N][N], st[N][N]; // 标记数组，用于标记已访问过的点
int n, m, res = 0; // n和m分别表示地图的行数和列数，res用于记录满足条件的连通块数目

// BFS函数，用于搜索一个连通块
void bfs(int i, int j) {
    queue<pii> q; // 定义一个队列，用于存储待访问的点
    q.push({i, j}); // 将起始点加入队列
    while (!q.empty()) { // 当队列不为空时循环
	 int x = q.front().ft, y = q.front().sd; // 取出队首元素的坐标
	        q.pop(); // 弹出队首元素
	        if (t[x][y]) continue; // 如果该点已经访问过，则跳过
	        t[x][y] = true; // 标记该点为已访问
	        for (int i = 0; i < 4; i++) { // 遍历该点的上下左右四个方向
	            int xx = x + dx[i], yy = y + dy[i]; // 计算下一个点的坐标
	            if (t[xx][yy] || xx < 1 || xx > n || yy < 1 || yy > m || g[xx][yy] == '0') continue; // 如果下一个点已经访问过、越界或者是海洋，则跳过
	            q.push({xx, yy}); // 将下一个点加入队列
	        }
	    }
	}
// 检查函数，用于检查一个连通块是否与边界相连
int check(int i, int j) {
    queue<pii> q; // 定义一个队列，用于存储待访问的点
    q.push({i, j}); // 将起始点加入队列
    while (!q.empty()) { // 当队列不为空时循环
        int x = q.front().ft, y = q.front().sd; // 取出队首元素的坐标
        q.pop(); // 弹出队首元素
        if (st[x][y]) continue; // 如果该点已经访问过，则跳过
        st[x][y] = true; // 标记该点为已访问
        if (x == 1 || x == n || y == 1 || y == m) return true; 
// 如果该点在边界上，则返回true
        for (int i = 0; i < 8; i++) { // 遍历该点的八个方向
            int xx = x + dx[i], yy = y + dy[i]; // 计算下一个点的坐标
            if (st[xx][yy] || g[xx][yy] == '1') continue; // 如果下一个点已经访问过或者是陆地，则跳过
            q.push({xx, yy}); // 将下一个点加入队列
        }
    }
    return false; // 如果没有与边界相连的点，则返回false
}


// 主函数，用于读入数据并调用处理函数
void solve() {
    memset(t, 0, sizeof t); // 初始化标记数组
    res = 0; // 初始化结果变量
    cin >> n >> m; // 读入地图的行数和列数
    for (int i = 1; i <= n; i++) // 循环读入地图信息
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    for (int i = 1; i <= n; i++) // 遍历地图
        for (int j = 1; j <= m; j++)
            if (!t[i][j] && g[i][j] == '1') { // 如果当前点未访问过且是陆地
                bfs(i, j); // 对当前连通块进行BFS搜索
                memset(st, 0, sizeof st); // 初始化边界标记数组
                if (check(i, j)) res++; // 检查当前连通块是否与边界相连，并更新结果
            }
    cout << res << endl; // 输出结果
}
int main() {
    int T;
    cin >> T; // 读入测试用例数量
    while (T--) solve(); // 循环处理每个测试用例
    return 0;
}
