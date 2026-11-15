// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n;
// vector<int> s, b;
// int ans = 1e9;

// // 方法二：DFS深搜，核心依旧是 选/不选

// void dfs (int idx, int prod, int sum, int cnt)
// {
//     if (idx == n)
//     {
//         if (cnt > 0)
//         {
//             ans = min(ans, abs(prod - sum));
//         }
//         return;
//     }

//     // 选
//     dfs(idx + 1, prod, sum, cnt);

//     // 不选
//     dfs(idx + 1, prod * s[idx], sum + b[idx], cnt + 1);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//     //    int n;
//     //    cin>>n;

//     //    vector<int> s(n), b(n);
//     //    for (int i = 0; i < n; i++)
//     //    {
//     //         cin>>s[i]>>b[i];
//     //    }

//     // 方法一：枚举非空子集，通过位掩码来表示 选/不选
//     //    int ans = 1e9;
//     //    for (int mask = 1; mask < (1 << n); mask++)
//     //    {
//     //         int prod = 1, sum = 0;
//     //         for (int i = 0; i < n; i++)
//     //         {
//     //             if ((mask >> i) & 1)
//     //             {
//     //                 prod *= s[i];
//     //                 sum += b[i];
//     //             }
//     //         }
//     //         ans = min(ans, abs(prod - sum));
//     //    }

//     //    cout<<ans<<endl;

//         cin>>n;
//         s.resize(n);
//         b.resize(n);

//         for (int i = 0; i < n; i++)
//         {
//             cin>>s[i]>>b[i];
//         }

//         dfs(0, 1, 0, 0);

//         cout<<ans<<endl;
//     }

//     return 0;
// }