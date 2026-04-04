#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,tot,x,y,m,n;
	int arr[110][110];
	cin >> m >> n;
	memset(arr,0,sizeof(arr));
	x=0;y=n-1;
	arr[x][y]=1;
	tot = 1;
	while(tot<m*n) //顺时针写数字
	{
		while(x+1<m && !arr[x+1][y]) arr[++x][y]=++tot;//右方一列从上到下
		while(y-1>=0 && !arr[x][y-1]) arr[x][--y]=++tot;//下方一行从右往左
		while(x-1>=0 && !arr[x-1][y]) arr[--x][y]=++tot;//左方一列从下往上
		while(y+1<=n && !arr[x][y+1]) arr[x][++y]=++tot;//上方一行从左往右 
	 } 
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%5d",arr[i][j]);
		}
		cout << endl;
	}
	//cout << endl;
	return 0;
	
} 
