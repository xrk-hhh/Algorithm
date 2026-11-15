// 原始稿：04_训练与工具/训练赛/laoda1/b.cpp
// 原文行号：54-66；恢复外层注释 1 层；保留方法内部注释。
#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
   long long cnt = 2 * 2026; // 4052
   // 计算 C(cnt, 3) = cnt*(cnt-1)*(cnt-2)/6
   long long c3 = cnt % MOD * ((cnt - 1) % MOD) % MOD * ((cnt - 2) % MOD) % MOD;
   c3 = c3 * 166666668 % MOD; // 6 的逆元
   long long ans = c3 * 2 % MOD;
   cout << ans << endl;
   return 0;
}
