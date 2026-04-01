#include<bits/stdc++.h>
using namespace std;

//判断日期是否合法
bool isValid(int year,int month,int day)
{
	if(month <1 || month >12) return false;
	int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//月份天数组成的数组
	//判断闰年
	if((year%4==0&&year%100!=0)||(year%400==0)) days[2]=29; 
	if(day<1 || day>days[month]) return false;
 } 
 
 int main()
 {
 	int n;
 	scanf("%d",&n);
 	int startyear = n/10000; //把第一个年份搞出来 
 	bool found1 = false;//是否找到第一个回文
 	//开始构造回文日期，假设枚举的年份i=2021 
	for(int i = startyear;i<9999;i++)
	{
		int year=i; //当前年份是2021 
		int t=1; //用于辅助翻转的临时变量 
		int rev = 0;//存储反转后的4位数 
		/* --- 第一步：翻转年份 --- 
    	第一次循环: t=2021, rev = 0*10 + 1 = 1,    t = 202
    	第二次循环: t=202,  rev = 1*10 + 2 = 12,   t = 20
   	 	第三次循环: t=20,   rev = 12*10 + 0 = 120, t = 2
    	第四次循环: t=2,    rev = 120*10 + 2 = 1202, t = 0 (结束)*/
		while(t) 
		{
			rev = rev *10 + t%10;
			t/=10;
		}
		
		/* --- 第二步：提取月份和日期 --- */
    	// 翻转后的 rev = 1202
		int month = rev/100; //得到前两位12月 
		int day = rev%100; //得到后两位02日 
		
		/* --- 第三步：生成完整的 8 位数日期 --- */
    	// 2021 * 10000 + 1202 = 20211202
		int fulldate = year*10000 + rev;
		
		// 排除掉不大于输入日期的情况（比如输入是 20211202，我们要找下一个）
		if (fulldate <= n) continue;
		
		/* --- 第四步：检查这个“拼凑”出来的日期是否合法 --- */
    	// 如果年份翻转后是 2022 -> 2202，month=22，这在 isValid 函数中会被拦截
		if (isValid(year, month, day)) {
            // 1. 寻找第一个回文日期
            if (!found1) {
                printf("%d\n",fulldate);
                found1 = true;
            }

            // 2. 寻找第一个 ABABBABA 型
            // 结构：A=s[0]=s[2]=s[5]=s[7], B=s[1]=s[3]=s[4]=s[6]
            string s = to_string(fulldate);//将构造出来的日期转成字符串 
            if (s[0] == s[2] && s[0] == s[5] && s[0] == s[7] && // 所有 A 的位置相等
                s[1] == s[3] && s[1] == s[4] && s[1] == s[6] &&// 所有 B 的位置相等
                s[0] != s[1]) {   // A 和 B 不能是同一个数字
                
                printf("%d\n", fulldate);
                break; // 找到了 ABABBABA，由于年份是递增的，这一定是最近的
            }
        }
    }
 	
  } 
