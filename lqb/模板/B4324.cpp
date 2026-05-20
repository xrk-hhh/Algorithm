// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// vector<int> pre, nxt;

// // 分离函数
// void detach(int x)
// {
//     int l = pre[x], r = nxt[x];
//     if (l)
//     {
//         nxt[l] = r;
//     }
//     if (r)
//     {
//         pre[r] = l;
//     }
//     pre[x] = 0;
//     nxt[x] = 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m;
//         cin>>n>>m;

//         // 双向链表（数组模拟双向链表）
//         pre.resize(n + 1);
//         nxt.resize(n + 1);
//         vector<bool> del(n + 1, false);
//         pre[1] = 0;
//         nxt[1] = 2;
//         pre[n] = n - 1;
//         nxt[n] = 0;
//         for (int i = 2; i < n; i++)
//         {
//             pre[i] = i - 1;
//             nxt[i] = i + 1;
//         }
//         while (m--)
//         {
//             int op;
//             cin>>op;

//             // 将 x 插到 y 左边
//             if (op == 1)
//             {
//                 int x, y;
//                 cin>>x>>y;

//                 if (x != y)
//                 {
//                     detach(x);

//                     int l = pre[y];
//                     pre[x] = l;
//                     nxt[x] = y;
//                     if (l)
//                     {
//                         nxt[l] = x;
//                     }
//                     pre[y] = x;
//                 }
//             }
//             // 将 x 插到 y 右边
//             else if (op == 2)
//             {
//                 int x, y;
//                 cin>>x>>y;

//                 if (x != y)
//                 {
//                     detach(x);

//                     int r = nxt[y];
//                     nxt[x] = r;
//                     pre[x] = y;
//                     if (r)
//                     {
//                         pre[r] = x;
//                     }
//                     nxt[y] = x;
//                 }
//             }
//             // 删除 x
//             else if (op == 3)
//             {
//                 int x;
//                 cin>>x;

//                 if (!del[x])
//                 {
//                     detach(x);
//                     del[x] = true;
//                 }
//             }
//         }

//         // 找到头节点
//         int head = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             // 未被删除且 pre为 0
//             if (!del[i] && pre[i] == 0)
//             {
//                 head = i;
//                 break;
//             }
//         }
//         if (head == 0)
//         {
//             cout<<"Empty!";
//         }
//         else
//         {
//             // 遍历链表
//             for (int cur = head; cur; cur = nxt[cur])
//             {
//                 cout<<cur<<' ';
//             }
//         }
//         cout<<endl;
//     }

//     return 0;
// }