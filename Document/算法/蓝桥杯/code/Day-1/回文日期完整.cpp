#include <iostream>
#include <cstdio>

using namespace std;

// 判断日期是否合法的函数
bool isValid(int year, int month, int day) {
    if (month < 1 || month > 12) return false;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 判断闰年
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) days[2] = 29;
    if (day < 1 || day > days[month]) return false;
    return true;
}

int main() {
    int n;
    // 如果你在控制台运行，请输入一个8位数字，如 20200202
    if (scanf("%d", &n) != 1) return 0;

    int startYear = n / 10000;
    bool found1 = false; // 是否已经找到了第一个回文日期

    // 从当前年份枚举到 9999
    for (int i = startYear; i <= 9999; i++) {
        // --- 构造回文部分 ---
        int year = i;
        int t = i;
        int rev = 0;
        // 翻转年份得到月和日 (比如 2021 -> 1202)
        while (t) {
            rev = rev * 10 + t % 10;
            t /= 10;
        }

        int month = rev / 100;
        int day = rev % 100;
        int fullDate = year * 10000 + rev;

        // 逻辑1：必须比输入的日期大，且必须是合法日期
        if (fullDate <= n || !isValid(year, month, day)) continue;

        // 逻辑2：输出第一个找到的回文日期
        if (!found1) {
            printf("%d\n", fullDate);
            found1 = true;
        }

        // 逻辑3：判断是否为 ABABBABA 型
        // 既然已经是回文了，我们只需要判断年份是否符合 ABAB 型
        // 比如年份是 2121，那么 A = 2, B = 1
        int a = year / 1000;      // 第1位
        int b = (year / 100) % 10; // 第2位
        int c = (year / 10) % 10;  // 第3位
        int d = year % 10;         // 第4位

        // 判断条件：第1位等于第3位，第2位等于第4位，且第1位不等于第2位
        if (a == c && b == d && a != b) {
            printf("%d\n", fullDate);
            break; // 找到 ABABBABA 后，任务完成，退出循环
        }
    }

    return 0;
}
