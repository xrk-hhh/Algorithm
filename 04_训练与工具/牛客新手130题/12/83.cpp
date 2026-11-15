// #include <bits/stdc++.h>
// using namespace std;

// stack<int> s;

// int main()
// {
//     int T;
//     cin>>T;

//     while (T--)
//     {
//         string op;
//         int x;
//         cin>>op;

//         if (op == "push")
//         {
//             cin>>x;
//             s.push(x);
//         }
//         else if (op == "pop")
//         {
//             if (s.empty())
//             {
//                 cout<<"Empty"<<endl;
//             }
//             else
//             {
//                 s.pop();
//             }
//         }
//         else if (op == "query")
//         {
//             if (s.empty())
//             {
//                 cout<<"Empty"<<endl;
//             }
//             else
//             {
//                 cout<<s.top()<<endl;
//             }
//         }
//         else
//         {
//             cout<<s.size()<<endl;
//         }
//     }

//     return 0;
// }