#include<bits/stdc++.h>
using namespace std;
int main()
{
	int head,foot;
	cin >> head >> foot;
	bool t = false;
	for(int i=0;i<head;i++)//鸡的数量
	{
    	for(int j=0;j<head;j++)//兔的数量
    	{
        	if(i+j == head && i*2+j*4 ==foot)
        	{
            	t = true;
            	cout << i << "," << j << endl;
        	}
    	}
	}
	if(!t) cout << "无解" << endl;
	return 0;
} 
