#include<bits/stdc++.h>
using namespace std;

int n,m,qx,qy,zx,zy;//起点和终点坐标 
int arr[20][20];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int rec[1000][1000]; //存放路径
int cnt;

//因为要把所有可能的路径搞出来，所以需要k来说是第几条路径 
void dfs(int x,int y,int k)
{
	rec[k][0] = x;
	rec[k][1] = y;
	//判断是否到终点
	if(x == zx && y==zy)
	{
		cnt++;
		for(int i=1;i<k;i++)
		{
			printf("(%d,%d)->",rec[i][0],rec[i][1]);	
		}
		printf("(%d,%d)\n",rec[k][0],rec[k][1]);
		return;
	}  
	//把路走完
	for(int i=0;i<4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 1 && nx <=n && ny>=1 &&ny<=m && arr[nx][ny]==1)	
		{
			arr[nx][ny]=0;
			dfs(nx,ny,k+1);
			arr[nx][ny]=1;//全部走完取消标记 
		}
	} 
} 

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>arr[i][j];	
		} 
	}
	cin >> qx >> qy >> zx >> zy;
	arr[qx][qy]=0;//把起始点标记为走过
	dfs(qx,qy,1);
	if(cnt == 0) cout << -1; 
}


