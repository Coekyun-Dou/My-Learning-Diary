#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,m,s;
	long long n;
	scanf("%lld",&n);
	n = n/1000 * 86400; //毫秒化秒 
	h = n/3600; //还有多少h 
	n = n%3600; //在这个小时还有多少秒
	m = n/60; //得到分钟数 
	s = n%60; //得到秒钟数
	printf("%02d:%02d:%02d",h,m,s); 
	
}
