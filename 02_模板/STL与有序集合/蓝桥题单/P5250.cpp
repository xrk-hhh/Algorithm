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
//         int m;
//         cin>>m;

//         // 木材仓库
//         set<int> st;
//         while (m--)
//         {
//             int op, len;
//             cin>>op>>len;

//             if (op == 1)
//             {
//                 if (st.count(len))
//                 {
//                     cout<<"Already Exist"<<endl;
//                 }
//                 else
//                 {
//                     st.insert(len);
//                 }
//             }
//             else if (op == 2)
//             {
//                 if (!st.empty())
//                 {
//                     if (len <= *st.begin())
//                     {
//                         cout<<*st.begin()<<endl;
//                         st.erase(*st.begin());
//                         continue;
//                     }
//                     else if (len >= *--st.end())
//                     {
//                         cout<<*--st.end()<<endl;
//                         st.erase(*--st.end());
//                         continue;
//                     }
                    
//                     int a, b;
//                     auto it = st.lower_bound(len);
//                     a = *it;
//                     b = *--it;

//                     if ((len - b) > (a - len))
//                     {
//                         cout<<a<<endl;
//                         st.erase(a);
//                         continue;
//                     }
//                     else
//                     {
//                         cout<<b<<endl;
//                         st.erase(b);
//                         continue;
//                     }
//                 }
//                 else
//                 {
//                     cout<<"Empty"<<endl;
//                 }
//             }
//         }
//     }

//     return 0;
// }