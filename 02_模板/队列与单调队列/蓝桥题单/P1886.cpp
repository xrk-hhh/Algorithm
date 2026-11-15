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

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         // 求最小值：递增序列
//         // 求最大值：递减序列
//         deque<int> dq1, dq2;
//         vector<int> res1, res2;
//         for (int i = 0; i < n; i++)
//         {
//             // 维护单调递增序列（队首最小）
//             while (!dq1.empty() && a[dq1.back()] >= a[i])
//             {
//                 dq1.pop_back();
//             }
//             dq1.push_back(i);
//             // 移除窗口外的元素
//             if (dq1.front() <= i - k)
//             {
//                 dq1.pop_front();
//             }
//             // 窗口形成后记录答案
//             if (i >= k - 1)
//             {
//                 res1.push_back(a[dq1.front()]);
//             }

//             // 递减
//             while (!dq2.empty() && a[dq2.back()] <= a[i])
//             {
//                 dq2.pop_back();
//             }
//             dq2.push_back(i);
//             if (dq2.front() <= i - k)
//             {
//                 dq2.pop_front();
//             }
//             if (i >= k - 1)
//             {
//                 res2.push_back(a[dq2.front()]);
//             }
//         }

//         for (int i = 0; i < res1.size(); i++)
//         {
//             cout<<res1[i]<<' ';
//         }
//         cout<<endl;
//         for (int i = 0; i < res2.size(); i++)
//         {
//             cout<<res2[i]<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }