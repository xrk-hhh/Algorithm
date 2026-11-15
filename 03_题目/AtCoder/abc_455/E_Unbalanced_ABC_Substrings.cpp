// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         string s;
//         cin>>n>>s;

//         vector<int> preA(n + 1, 0), preB(n + 1, 0), preC(n + 1, 0);
//         for (int i = 1; i <= n; i++) 
//         {
//             preA[i] = preA[i - 1] + (s[i - 1] == 'A');
//             preB[i] = preB[i - 1] + (s[i - 1] == 'B');
//             preC[i] = preC[i - 1] + (s[i - 1] == 'C');
//         }

//         // 统计差值相等的对数（dAB 和 dAC同时相等时，dBC也相等）
//         unordered_map<int, ll> cntAB, cntAC, cntBC;
//         // 二维向量编码
//         unordered_map<ll, ll> cnt;
//         for (int i = 0; i <= n; i++) 
//         {
//             int dAB = preA[i] - preB[i];
//             int dAC = preA[i] - preC[i];
//             int dBC = preB[i] - preC[i];
//             cntAB[dAB]++;
//             cntAC[dAC]++;
//             cntBC[dBC]++;

//             // 编码二维向量，保证唯一
//             ll key = 1LL * dAB * (2 * n + 1) + dAC;
//             cnt[key]++;
//         }

//         ll tot = 1LL * n * (n + 1) >> 1;

//         // 对每个差值，若其出现次数为 c，则贡献 C(c, 2)
//         ll sumAB = 0, sumAC = 0, sumBC = 0, sum = 0;
//         for (auto& p : cntAB)
//         {
//             sumAB += p.second * (p.second - 1) >> 1;
//         }
//         for (auto& p : cntAC)
//         {
//             sumAC += p.second * (p.second - 1) >> 1;
//         }
//         for (auto& p : cntBC)
//         {
//             sumBC += p.second * (p.second - 1) >> 1;
//         }
//         for (auto& p : cnt)
//         {
//             sum += p.second * (p.second - 1) >> 1;
//         } 

//         // 容斥原理
//         ll ans = tot - (sumAB + sumAC + sumBC) + 2 * sum;

//         cout<<ans<<endl;
//     }

//     return 0;
// }