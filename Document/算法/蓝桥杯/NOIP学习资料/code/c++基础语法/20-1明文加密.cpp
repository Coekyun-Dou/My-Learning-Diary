#include<bits/stdc++.h>
using namespace std;
int main()
{
	char buf[100] = "hello,c++";
	const char* p = "@%@$@$@%@#$%#";
    int i;
	for(int i=0;i<10;i++)
    	buf[i] = buf[i] ^ p[i]; 
	cout << buf << endl; //加密后的 
	for(int i=0;i<10;i++)
   		buf[i] = buf[i] ^ p[i];
	cout << buf <<endl; //解密后的 
	return 0;
}
