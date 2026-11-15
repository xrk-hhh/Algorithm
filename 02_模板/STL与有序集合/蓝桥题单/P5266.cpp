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
//         int q;
//         cin>>q;

//         // 学籍管理
//         unordered_map<string, int> mp;
//         while (q--)
//         {
//             int op;
//             cin>>op;

//             if (op == 1)
//             {
//                 string s;
//                 int sc;
//                 cin>>s>>sc;

//                 mp[s] = sc;
//                 cout<<"OK"<<endl;
//             }
//             else if (op == 2)
//             {
//                 string s;
//                 cin>>s;

//                 auto it = mp.find(s);
//                 if (it != mp.end())
//                 {
//                     cout<<mp[s]<<endl;
//                 }
//                 else
//                 {
//                     cout<<"Not found"<<endl;
//                 }
//             }
//             else if (op == 3)
//             {
//                 string s;
//                 cin>>s;

//                 auto it = mp.find(s);
//                 if (it != mp.end())
//                 {
//                     mp.erase(s);
//                     cout<<"Deleted successfully"<<endl;
//                 }
//                 else
//                 {
//                     cout<<"Not found"<<endl;
//                 }
//             }
//             else if (op == 4)
//             {
//                 cout<<mp.size()<<endl;
//             }
//         }
//     }

//     return 0;
// }