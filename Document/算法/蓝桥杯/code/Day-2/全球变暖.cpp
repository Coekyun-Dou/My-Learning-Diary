#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char mp[N][N];
int n;
int flag = 0;
int vis[N][N];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void dfs(int x,int y){
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if (mp[nx][ny] == '.') continue;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        if (mp[nx - 1][ny] == '#' && mp[nx + 1][ny] == '#' && mp[nx][ny - 1] == '#' && mp[nx][ny + 1] == '#'){
            flag = 1;
        }
        dfs(nx,ny);
    }
    return;
}
int main(){
    int sum = 0;
    int cnt = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mp[i][j];
        }
    }
    for (int i = 0; i <= n + 1; ++i){
        for (int j = 0; j <= n + 1; ++j){
            if (!mp[i][j]) mp[i][j] = '#';
        }
    }    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (mp[i][j] == '#' && !vis[i][j]){
                dfs(i,j);
                sum++;
                if (flag == 1){
                    cnt++;
                    flag = 0;
                }
            }
        }
    }
    printf("%d\n",sum - cnt);
    return 0;
}
