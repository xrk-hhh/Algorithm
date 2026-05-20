// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, q;
// vector<int> ct;

// bool check(int s, int v)
// {
//     // 常采用左闭右开的形式 [l, r)
//     int l = 0, r = n;
//     // 寻找第一个满足 ct[i] > s的 i
//     // 也可直接使用 l = lower_bound(ct.begin(), ct.end(), s) - ct.begin()
//     while (l < r)
//     {
//         int mid = (l + r) >> 1;
//         if (s < ct[mid])
//         {
//             r = mid;
//         }
//         else
//         {
//             l = mid + 1;
//         }
//     }
    
//     // 看看满足 ct[i] > s 的 i 的个数是否大于等于 v
//     return (n - 1 - l + 1) >= v;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n>>q;
//         ct.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>ct[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             int t;
//             cin>>t;
//             ct[i] -= t;
//         }

//         sort(ct.begin(), ct.end());

//         while (q--)
//         {
//             int v, s;
//             cin>>v>>s;

//             if (check(s, v))
//             {
//                 cout<<"YES"<<endl;
//             }
//             else
//             {
//                 cout<<"NO"<<endl;
//             }
//         }
//     }

//     return 0;
// }