#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,s = 0;
	cin >> n;
	for(long long a = 1;a * a * a <= n;a++) 
	{
		for(long long b = a;a * b * b <= n;b++) 
		{
			if(b <= n / (a * b)) 
			{
				//左边界必须小于右边界
				s += (n / (a * b) - b + 1);
			}	
		}
	}
	cout << s;
}
