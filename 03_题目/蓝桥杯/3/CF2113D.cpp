// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<int> a(n + 1), b(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>b[i];
//         }

//         // b 的前缀最小值
//         vector<int> minb(n + 2);
//         minb[0] = 1e9;
//         for (int i = 1; i <= n; i++)
//         {
//             minb[i] = min(minb[i - 1], b[i]);
//         }

//         // a 的后缀最大值
//         vector<int> maxa(n + 2);
//         maxa[n + 1] = 0;
//         for (int i = n; i >= 1; i--)
//         {
//             maxa[i] = max(maxa[i + 1], a[i]);
//         }

//         int ans = 0;
//         // a 当前的最小值与次最小值
//         int mina1 = 1e9, mina2 = 1e9;
//         for (int i = 1; i <= n; i++)
//         {
//             if (a[i] < mina1)
//             {
//                 mina2 = mina1;
//                 mina1 = a[i];
//             }
//             else if (a[i] < mina2)
//             {
//                 mina2 = a[i];
//             }

//             // a 前 i 个的最小值   >=   b 前 n - i + 1 的最小值才能赢下 i 分
//             if (min(max(maxa[i + 1], mina1), mina2) < minb[n - i + 1])
//             {
//                 break;
//             }

//             ans = i;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }