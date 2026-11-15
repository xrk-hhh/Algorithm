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
//         int n, k;
//         cin>>n>>k;

//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         // dp[i]：以位置 i 结尾（即选中 i）的最小总和
//         // dp[i] = ai + (i-k-1<=j<=i-1)min(dp[j])
//         vector<ll> dp(n + 1);
//         // 转移需要求一段滑动窗口内的最小值，窗口大小为 k+1。
//         // 我们可以用一个单调递增队列（存下标，对应的 dp 值递增）来维护。
//         deque<int> dq;
//         dp[1] = a[1];
//         dq.push_back(1);
//         for (int i = 2; i <= n; i++)
//         {
//             // 移除超出窗口的索引
//             while(!dq.empty() && dq.front() < i - k - 1)
//             {
//                 dq.pop_front();
//             }

//             // 此时队首就是最优的 j
//             dp[i] = a[i] + dp[dq.front()];

//             // 维护单调递增
//             while(!dq.empty() && dp[dq.back()] >= dp[i])
//             {
//                 dq.pop_back();
//             }

//             dq.push_back(i);
//         }

//         cout<<dp[n]<<endl;
//     }

//     return 0;
// }