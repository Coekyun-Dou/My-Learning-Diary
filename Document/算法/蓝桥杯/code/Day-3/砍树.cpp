#include<bits/stdc++.h>
using namespace std;

int a[100010]; 

int main()
{
	cin.tie(0);
	cout.tie(0);
	long long n,m,maxn = -1,u=0,x=0;//max用来存储最大值，u用来计算总和、x用来存储结果
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(maxn < a[i])
			maxn = a[i];
	}
	long long l = 0,r=maxn;
	while(l <= r)
	{
		u = 0;//每次循环重新初始化变量u 
		int mid = (l+r) >> 1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>mid)
			{
				u+=a[i]-mid;
			}
		}
		if(u>=m)
		{
			x = mid;
			l = mid + 1;
		}
		else
		{
			r = mid -1;
		}
	}
	cout << x;
	return 0;
	 
} 
