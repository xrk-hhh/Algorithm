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
//         cin>>n;

//         vector<int> h(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>h[i];
//         }

//         // {高度，相同高度的连续人数}
//         stack<pair<int, int>> st;
//         ll ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             // 当前人自身
//             int cnt = 1;
//             // 栈顶的高度比当前高度低（单调减序列）
//             while (!st.empty() && st.top().first <= h[i])
//             {
//                 // 栈顶的每个人都能与当前人互相看见
//                 ans += st.top().second;
//                 if (st.top().first == h[i])
//                 {
//                     // 合并相同高度
//                     cnt += st.top().second;
//                 }
//                 st.pop();
//             }

//             // 栈非空 且 栈顶高度 > h[i]
//             if (!st.empty())
//             {
//                 // 当前人仅与栈顶可互相看见
//                 ans++;
//             }
//             st.push({h[i], cnt});
//         }
        
//         cout<<ans<<endl;
//     }

//     return 0;
// }