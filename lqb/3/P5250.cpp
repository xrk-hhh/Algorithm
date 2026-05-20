// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

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

//         set<int> wood;
//         while (m--)
//         {
//             int op, len;
//             cin>>op>>len;

//             auto it = wood.find(len);
//             if (op == 1)
//             {
//                 if (it != wood.end())
//                 {
//                     cout<<"Already Exist"<<endl;
//                 }
//                 else
//                 {
//                     wood.insert(len);
//                 }
//             }
//             else if (op == 2)
//             {
//                 if (it != wood.end())
//                 {
//                     cout<<*it<<endl;
//                     wood.erase(*it);
//                 }
//                 else
//                 {
//                     if (wood.size() > 0)
//                     {
//                         auto p = wood.lower_bound(len);
//                         auto q = wood.upper_bound(len);

//                         if (p != wood.begin() && q != wood.end())
//                         {
//                             p--;
//                             if (abs(*p - len) < abs(*q - len))
//                             {
//                                 cout<<*p<<endl;
//                                 wood.erase(*p);
//                             }
//                             else if (abs(*p - len) > abs(*q - len))
//                             {
//                                 cout<<*q<<endl;
//                                 wood.erase(*q);
//                             }
//                             else
//                             {
//                                 cout<<*p<<endl;
//                                 wood.erase(*p);
//                             }
//                         }
//                         else if (p == wood.begin() && q != wood.end())
//                         {
//                             cout<<*q<<endl;
//                             wood.erase(*q);
//                         }
//                         else if (p != wood.begin() && q == wood.end())
//                         {
//                             p--;
//                             cout<<*p<<endl;
//                             wood.erase(*p);
//                         }                        
//                     }
//                     else
//                     {
//                         cout<<"Empty"<<endl;
//                     }
//                 }
//             }
//         }
//     }

//     return 0;
// }