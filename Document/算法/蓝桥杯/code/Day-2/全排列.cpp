#include<bits/stdc++.h>
using namespace std;

int n;
int arr[14];
bool f[10];//看看有哪些数用过

void print()
{
	for(int i=1;i<n;i++)
	{
		cout << arr[i] << " ";	
	}
	cout << arr[n] << endl;
} 

void dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(f[i] == false)//没被用过
		{
			arr[x]=i;
			f[i]=true;
			if(x==n) print();
			else dfs(x+1);
			f[i] = false;//dfs完释放标志	
		} 
	}
}

int main()
{
	cin>>n;
	dfs(1);
	return 0; 
}
