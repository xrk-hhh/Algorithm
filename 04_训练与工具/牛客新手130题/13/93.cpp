// #include <bits/stdc++.h>
// using namespace std;

// queue<int> q;

// int main() 
// {
//     int n;
//     cin>>n;

//     while (n--)
//     {
//         int op;
//         cin>>op;
//         switch(op)
//         {
//             case 1:
//                 int x;
//                 cin>>x;
//                 q.push(x);
//                 break;
//             case 2:
//                 if (q.empty())
//                 {
//                     cout<<"ERR_CANNOT_POP"<<endl;
//                 }
//                 else
//                 {
//                     q.pop();
//                 }
//                 break;
//             case 3:
//                 if (q.empty())
//                 {
//                     cout<<"ERR_CANNOT_QUERY"<<endl;
//                 }
//                 else
//                 {
//                     cout<<q.front()<<endl;
//                 }
//                 break;
//             case 4:
//                 cout<<q.size()<<endl;
//                 break;
//         }
//     }

//     return 0;
// }