#include<bits/stdc++.h>
using namespace std;

//判断一个数字是否包含2或4 
bool check(int x)
{
	while(x>0)
	{
		if(x%10==2 || x%10==4)
		{
			return true;
		}
		x/=10;
	}
	return false;
}

int main()
{
	long result=0;
	//用三重循环计算符合条件的组合数
	for(int i=1;i<2019;i++)
	{
		for(int j=1;j<2019;j++)
		{
			for(int k=1;k<2019;k++)
			{
				if(i+j+k==2019)
				{
					//排除重复的组合
					if(i!=j && i!=k && j!=k) 
					{
						//判断是否满足
						if(!check(i) && !check(j) && !check(k))
						{
							result ++;
						 } 
					}
				}
			}
		}
	 } 
	 //结果除以6是因为每个组合会被计算6次（因为排列组合） 
	 cout << result/6 << endl;
	 return 0;
		
} 
