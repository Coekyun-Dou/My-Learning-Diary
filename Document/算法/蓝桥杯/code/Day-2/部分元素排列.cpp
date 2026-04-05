#include<bits/stdc++.h>
using namespace std;

int arr[20];
int ans[20]; 
int n,r;


void print(int m)
{
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}

//用来生成排列 
void dfs(int x,int pos)
{
	if(x == r+1)//已经选取r+1个元素 
	{
		print(r);
		return;
	}
	else
	{
		for(int i=pos+1;i<=n;i++)
		{
			ans[x]=arr[i];
			dfs(x+1,i);
		}
	}
}

int main()
{
	cin >> n >> r;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	sort(arr+1,arr+1+n);//对输入的元素值进行排序 
	dfs(1,0);
	return 0;
}
