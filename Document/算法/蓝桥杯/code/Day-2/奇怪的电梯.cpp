#include<bits/stdc++.h>
using namespace std;
int x[205],step[205]={0}; 
int n,a,b;// 输入的数值范围n，起点a，终点b
queue<int> q; 

void bfs()
{
	//queue<int> q;	
	q.push(a);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		if(t == b)
		{
			cout << step[b];
			return;
		}
		if(t - x[t] >=1 && !step[t-x[t]])// 如果向下跳不越界且下一个位置未被访问过
		{
			q.push(t-x[t]);//下一个位置加入队列
			step[t-x[t]]=step[t]+1;  // 更新下一个位置的步数
		}
		if(t+x[t] <= n && !step[t+x[t]])  // 如果向上跳不越界且下一个位置未被访问过
		{
			q.push(t+x[t]);
			step[t+x[t]] = step[t] + 1;  // 更新下一个位置的步数
		}
		
	}
	cout<< -1;//无法到达终点 
}

int main()
{
	cin >> n >> a >> b;
	for(int i=1;i<=n;i++)
	{
		cin >> x[i];
	}
	bfs();
}
