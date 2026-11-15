// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'

// set<int> s; 

// int main() 
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int Q;
//     cin>>Q;

//     while (Q--)
//     {
//         int op, x;
//         cin>>op>>x;

//         if (op == 1)
//         {
//             if (!s.count(x))
//             {
//                 s.insert(x);
//             }
//             else 
//             {
//                 cout<<"Already Exist"<<endl;
//             }
//         }
//         else
//         {
//             if (!s.empty())
//             {
//                 if (x <= *s.begin())
//                 {
//                     cout<<*s.begin()<<endl;
//                     s.erase(*s.begin());
//                     continue;
//                 }
//                 else if (x >= *--s.end())
//                 {
//                     cout<<*--s.end()<<endl;
//                     s.erase(*--s.end());
//                     continue;
//                 }
//                 int a, b;
//                 auto it = s.lower_bound(x);
//                 a = *it;
//                 b = *--it;
//                 if ((x - b) > (a - x))
//                 {
//                     cout<<a<<endl;
//                     s.erase(a);
//                 }
//                 else
//                 {
//                     cout<<b<<endl;
//                     s.erase(b);
//                 }
//             }
//             else
//             {
//                 cout<<"Empty"<<endl;
//             }
//         }
//     }

//     return 0;
// }