#include<bits/stdc++.h>  // 引入常用的头文件
using namespace std;
const int N = 1e5 + 10;  // 定义常量N，表示数组长度的上限
int a[N];  // 定义数组a，用于存储输入的数据
int n, q;  // 定义变量n表示数组长度，变量q表示查询次数
int main() {
    cin.tie(0);  // 解除cin与cout的绑定，提高输入输出效率
    cout.tie(0);
    
    cin >> n >> q;  // 输入数组长度和查询次数
    for (int i = 1; i <= n; i++) {
        cin >> a[i];  // 输入数组元素
    }
    
    while (q--) {
        int x;
        cin >> x;  // 输入查询的值x
        int l = 1, r = n;  // 初始化二分查找的左右边界
        int ans;  // 存储查询结果
        
        // 二分查找寻找第一个大于等于x的位置
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] >= x) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        // 如果找不到等于x的元素，输出"-1 -1"并继续下一次查询
        if (a[ans] != x) {
            cout << "-1 -1" << endl;
            continue;
        }
        
        cout << ans - 1 << ' ';  // 输出第一个等于x的位置的左边界
        
        l = 1, r = n;  // 重新初始化左右边界
        ans = 1;  // 重新初始化查询结果
        
        // 二分查找寻找最后一个小于等于x的位置
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        cout << ans - 1 << endl;  // 输出最后一个等于x的位置的右边界
    }
    return 0;
}

