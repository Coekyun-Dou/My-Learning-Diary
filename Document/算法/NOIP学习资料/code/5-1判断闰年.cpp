#include<bits/stdc++.h>
using namespace std;
int main()
{
	int year;
	cin >> year;
	bool x = year%4==0 && year%100!=0 || year%400==0;
	cout << x << endl;
	return 0;
}
