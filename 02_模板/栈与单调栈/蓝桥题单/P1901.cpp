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

//         vector<int> h(n + 1), v(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>h[i]>>v[i];
//         }

//         vector<int> l(n + 1, 0), r(n + 1, 0);
//         stack<int> st;
//         // 左边第一个更高的位置
//         for (int i = 1; i <= n; i++)
//         {
//             while (!st.empty() && h[st.top()] <= h[i])
//             {
//                 st.pop();
//             }

//             l[i] = st.empty() ? 0 : st.top();
//             st.push(i);
//         }

//         while (!st.empty())
//         {
//             st.pop();
//         }

//         // 右边第一个更高的位置
//         for (int i = n; i >= 1; i--)
//         {
//             while (!st.empty() && h[st.top()] <= h[i])
//             {
//                 st.pop();
//             }

//             r[i] = st.empty() ? 0 : st.top();
//             st.push(i);
//         }

//         vector<int> res(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             if (l[i])
//             {
//                 res[l[i]] += v[i];
//             }

//             if (r[i])
//             {
//                 res[r[i]] += v[i];
//             }
//         }

//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             ans = max(ans, res[i]);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }