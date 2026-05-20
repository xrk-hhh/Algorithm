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

//         // 各个队列中已经同步了的元素个数
//         vector<int> sync_cnt(n, 0);
//         string op;
//         // 添加的元素个数
//         int add_cnt = 0;
//         while (cin>>op)
//         {
//             if (op == "add")
//             {
//                 int x;
//                 cin>>x;
//                 add_cnt++;
//             }
//             else if (op == "sync")
//             {
//                 int id;
//                 cin>>id;
//                 sync_cnt[id]++;
//             }
//             else if (op == "query")
//             {
//                 // 若没有副节点
//                 int minn = add_cnt;
//                 for (int i = 1; i < n; i++)
//                 {
//                     minn = min(minn, sync_cnt[i]);
//                 }

//                 cout<<minn<<endl;
//             }
//         }
//     }

//     return 0;
// }