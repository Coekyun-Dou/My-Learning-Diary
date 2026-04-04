#include <bits/stdc++.h>

using namespace std;

string decode() {
    string res = "";
    char c;
    // 每次从输入流读取一个字符
    while (cin >> c) {
        if (c == '[') {
            int k;
            cin >> k;             // 魔法发生在这里：自动提取多位数字，读完指针自动停在后续字母上
            string t = decode();  // 向下递归，获取括号内的字符串 X
            while (k--) res += t; // 将 X 重复 k 次并拼接
        } 
        else if (c == ']') {
            return res;           // 遇到右括号，说明当前层的 [DX] 解析完毕，向上返回
        } 
        else {
            res += c;             // 普通字母直接拼接
        }
    }
    return res;
}

int main() {
    cout << decode() << endl;
    return 0;
}
