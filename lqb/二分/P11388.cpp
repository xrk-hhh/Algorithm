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
//         int n, k;
//         cin>>n>>k;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         // // 维护当前可达的最小值和最大值
//         // int minn = a[0], maxx = a[0];
//         // cout<<"1"<<" ";

//         // for (int i = 1; i < n; i++)
//         // {
//         //     if (minn - k <= a[i] && a[i] <= maxx + k)
//         //     {
//         //         cout<<"1"<<" ";
//         //         minn = min(minn, a[i]);
//         //         maxx = max(maxx, a[i]);
//         //     }
//         //     else
//         //     {
//         //         cout<<"0"<<" ";
//         //     }
//         // }
//         // cout<<endl;

//         // vector<int> ans(n, 0);
//         // ans[0] = 1;
//         // // 存储当前所有已可达的花高度
//         // set<int> st;
//         // st.insert(a[0]);
//         // for (int i = 1; i < n; i++)
//         // {
//         //     auto it = st.lower_bound(a[i] - k);
//         //     if (it != st.end() && *it <= a[i] + k)
//         //     {
//         //         ans[i] = 1;
//         //         st.insert(a[i]);
//         //     }
//         // }

//         // for (int i = 0; i < n; i++)
//         // {
//         //     cout<<ans[i]<<' ';
//         // }
//         // cout<<endl;
//     }

//     return 0;
// }