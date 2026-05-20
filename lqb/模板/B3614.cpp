// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;
// using ull = unsigned long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         // 栈
//         stack<ull> st;
//         while (n--)
//         {
//             string op;
//             cin>>op;

//             if (op == "push")
//             {
//                 ull x;
//                 cin>>x;
//                 st.push(x);
//             }
//             else if (op == "pop")
//             {
//                 if (!st.empty())
//                 {
//                     st.pop();
//                 }
//                 else
//                 {
//                     cout<<"Empty"<<endl;
//                 }
//             }
//             else if (op == "query")
//             {
//                 if (!st.empty())
//                 {
//                     cout<<st.top()<<endl;
//                 }
//                 else
//                 {
//                     cout<<"Anguei!"<<endl;
//                 }
//             }
//             else if (op == "size")
//             {
//                 cout<<st.size()<<endl;
//             }
//         }
//     }

//     return 0;
// }