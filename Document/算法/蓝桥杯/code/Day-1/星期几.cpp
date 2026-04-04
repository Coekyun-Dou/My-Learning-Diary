#include<bits/stdc++.h>
using namespace std;
int main()
{
	int currentday=6;
	int ans=1; 
	for(int i=1;i<=22;i++)
	{
		ans = (ans%7)*20%7;
	}
	int nextday = (currentday + ans -1)%7 +1;
	cout << nextday;
 } 
