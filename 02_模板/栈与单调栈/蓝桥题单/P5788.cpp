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

//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         vector<int> ans(n + 1, 0);
//         // 单调栈
//         stack<int> st;
//         for (int i = 1; i <= n; i++)
//         {
//             // 栈非空且当前元素 a[i] 大于栈顶元素 a[st.top()] 
//             while (!st.empty() && a[st.top()] < a[i])
//             {
//                 // 栈顶元素右边第一个大于它的就是 i
//                 ans[st.top()] = i;
//                 st.pop();
//             }

//             st.push(i);
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             cout<<ans[i]<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }