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

//         // 队列安排（数组模拟双向链表）
//         vector<int> pre(n + 1, 0), nxt(n + 1, 0);
//         vector<bool> del(n + 1, false);
//         for (int i = 2; i <= n; i++)
//         {
//             int k, p;
//             cin>>k>>p;

//             // 插到左侧
//             if (p == 0)
//             {
//                 int l = pre[k];
//                 pre[i] = l;
//                 nxt[i] = k;
//                 if (l)
//                 {
//                     nxt[l] = i;
//                 }
//                 pre[k] = i;
//             }
//             // 插到右侧
//             else if (p == 1)
//             {
//                 int r = nxt[k];
//                 nxt[i] = r;
//                 pre[i] = k;
//                 if (r)
//                 {
//                     pre[r] = i;
//                 }
//                 nxt[k] = i;
//             }
//         }

//         int m;
//         cin>>m;

//         // 删除
//         while (m--)
//         {
//             int x;
//             cin>>x;

//             if (!del[x])
//             {
//                 del[x] = true;
//             }
//         }

//         // 寻找头节点
//         int head = 1;
//         while (pre[head])
//         {
//             head = pre[head];
//         }
//         for (int cur = head; cur; cur = nxt[cur])
//         {
//             if (!del[cur])
//             {
//                 cout<<cur<<" ";
//             }
//         }
//         cout<<endl;
//     }

//     return 0;
// }