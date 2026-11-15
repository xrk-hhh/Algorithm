// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const ll INF = 1e18;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, a, b, c;
//         cin>>n>>a>>b>>c;
//         vector<ll> s(n + 1), pre(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>s[i];
//             pre[i] = pre[i - 1] + s[i];
//         }

//         // 前缀 B 最小值
//         vector<ll> minn(n + 1);
//         minn[0] = INF;
//         int ans = 0;

//         // pre[R] - pre[L-1] > abR - acL
//         // 即 pre[R] - abR > pre[L-1] - acL
//         // 即 A[R] > B[L]
//         for (int i = 1; i <= n; i++)
//         {
//             // B[L] = pre[L-1] - a*c*L
//             ll B = pre[i - 1] - 1LL * a * c * i;
//             minn[i] = min(minn[i - 1], B);

//             // A[R] = pre[R] - a*b*R
//             ll A = pre[i] - 1LL * a * b * i;
//             int l = 0, r = i + 1;
//             // 在 minn[0...i]中二分找第一个 < A 的位置（因为 minn 单调不增）
//             while (l < r)
//             {
//                 int mid = (l + r) >> 1;
//                 if (minn[mid] < A)
//                 {
//                     r = mid;
//                 }
//                 else
//                 {
//                     l = mid + 1;
//                 }
//             }

//             // r 即为最左的合法左端点 L
//             if (r <= i)
//             {
//                 ans = max(ans, i - r + 1);
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }