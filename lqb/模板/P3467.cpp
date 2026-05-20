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

//         vector<int> d(n), w(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>d[i]>>w[i];
//         }

//         // 段数
//         int ans = n;
//         // 该段中的高度序列（单调增）
//         stack<int> st;
//         for (int i = 0; i < n; i++)
//         {
//             // 弹出栈中大于当前高度的（无法合并）
//             while (!st.empty() && st.top() > w[i])
//             {
//                 st.pop();
//             }

//             // 当前高度与栈顶高度相同，且中间没有比它们更低的高度
//             if (!st.empty() && st.top() == w[i])
//             {
//                 // 可合并
//                 ans--;
//             }
//             st.push(w[i]);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }