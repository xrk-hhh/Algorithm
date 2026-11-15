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
//         int a, b, c, l, r;
//         cin>>a>>b>>c>>l>>r;

//         set<int> st;
//         st.insert(a);
//         st.insert(b);
//         st.insert(c);
        
//         int cnt = 0;
//         for (int x : st)
//         {
//             if (x >= l && x <= r)
//             {
//                 cnt++;
//             }
//         }

//         cout<<r - l + 1 - cnt<<endl;
//     }

//     return 0;
// }