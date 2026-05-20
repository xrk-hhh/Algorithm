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

//         // 队列
//         queue<int> q;
//         while (n--)
//         {
//             int op;
//             cin>>op;

//             if (op == 1)
//             {
//                 int x;
//                 cin>>x;

//                 q.push(x);
//             }
//             else if (op == 2)
//             {
//                 if (!q.empty())
//                 {
//                     q.pop();
//                 }
//                 else
//                 {
//                     cout<<"ERR_CANNOT_POP"<<endl;
//                 }
//             }
//             else if (op == 3)
//             {
//                 if (!q.empty())
//                 {
//                     cout<<q.front()<<endl;
//                 }
//                 else
//                 {
//                     cout<<"ERR_CANNOT_QUERY"<<endl;
//                 }
//             }
//             else if (op == 4)
//             {
//                 cout<<q.size()<<endl;
//             }
//         }
//     }

//     return 0;
// }