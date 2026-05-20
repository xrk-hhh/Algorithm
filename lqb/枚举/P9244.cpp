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
//         int k;
//         cin>>k;

//         string s;
//         char c1, c2;
//         cin>>s>>c1>>c2;

//         int n = s.size();

//         // c2个数前缀和
//         vector<int> pre(n, 0);
//         pre[0] = (s[0] == c2);
//         for (int i = 1; i < n; i++)
//         {
//             pre[i] = pre[i - 1] + (s[i] == c2);
//         }

//         ll ans = 0;
//         // 字符串长度大于等于 k
//         for (int i = 0; i < n - k + 1; i++)
//         {
//             if (s[i] == c1)
//             {
//                 ans += pre[n - 1] - pre[i + k - 2];
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }