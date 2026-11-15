// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// // 最大重量范围
// const int MAXV = 1e5;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<int> cnt(MAXV + 1, 0);
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin>>x;

//             cnt[x]++;
//         }

//         // 利用计数排序（桶排序）生成有序序列到 q1
//         queue<ll> q1, q2;
//         for (int v = 0; v <= MAXV; v++)
//         {
//             for (int k = 0; k < cnt[v]; k++)
//             {
//                 q1.push(v);
//             }
//         }

//         ll ans = 0;
//         for (int i = 1; i < n; i++)
//         {
//             ll x, y;
//             // 从两个队列的队首选最小的两个
//             if (q2.empty() || (!q1.empty() && q1.front() < q2.front()))
//             {
//                 x = q1.front();
//                 q1.pop();
//             }
//             else
//             {
//                 x = q2.front();
//                 q2.pop();
//             }

//             if (q2.empty() || (!q1.empty() && q1.front() < q2.front()))
//             {
//                 y = q1.front();
//                 q1.pop();
//             }
//             else
//             {
//                 y = q2.front();
//                 q2.pop();
//             }

//             ll sum = x + y;
//             ans += sum;
//             q2.push(sum);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }