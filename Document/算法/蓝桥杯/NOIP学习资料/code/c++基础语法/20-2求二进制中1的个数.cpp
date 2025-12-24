#include<bits/stdc++.h>
using namespace std;

int count(unsigned int x)//用unsigned防止>>陷阱
{
    int n=0;
    while(x)
    {
    	if(x&1) n++;
        x >>= 1;//去掉最后的1，等同与x=x>>1;
	}
    return n;
}

int main()
{
	int a;
	cin >> a;
	cout << count(a) << endl;
	return 0;
}
