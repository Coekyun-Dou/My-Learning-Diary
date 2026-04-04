#include<bits/stdc++.h>
using namespace std;

bool check(int x)
{
	while(x>0)
	{
		if(x%10==2 || x%10==0 ||x%10==1 || x%10==9)
		{
			return true;
		}
		x/=10;
	}
	return false; 
}

int main()
{
	int n,sum=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		if(check(i))
		{
			sum += i;
		}
	}
	cout << sum;
	return 0;
}
