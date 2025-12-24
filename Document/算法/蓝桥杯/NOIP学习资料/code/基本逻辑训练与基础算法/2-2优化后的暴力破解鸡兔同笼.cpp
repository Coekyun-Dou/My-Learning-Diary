#include<bits/stdc++.h>
using namespace std;
int main()
{
	int head,foot;
	cin >> head >> foot;
	bool t = false;
	for(int i=0;i<=head;i++)
	{
    	int j = head - i;
    	if(i*2 + j*4 == foot)
    	{
        	t = true;
        	cout << i << "," << j <<endl;
		}
	}
	if(!t) cout << "нч╫Б" << endl;
	return 0;
}
