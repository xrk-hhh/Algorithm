// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int m, n;
// int ans;

// void dfs(int last, int sum, int cnt)
// {
//     // 分出部分超过 n
//     if (cnt > n)
//     {
//         return;
//     }

//     // 分完
//     if (sum == m)
//     {
//         ans++;
//         return;
//     }

//     // 保证序列中数字升序
//     for (int i = last; i <= m - sum; i++)
//     {
//         dfs(i, sum + i, cnt + 1);
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         // 多组数据，每组需重置 ans 为 0
//         ans = 0;
//         cin>>m>>n;

//         dfs(1, 0, 0);

//         cout<<ans<<endl;
//     }

//     return 0;
// }