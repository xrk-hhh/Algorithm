// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 1e8 - 3;

// // 归并排序 + 计算逆序对
// ll calc(vector<int>& a, vector<int>& t, int l, int r)
// {
//     if (l >= r)
//     {
//         return 0;
//     }

//     int mid = (l + r) >> 1;
//     // 递归分割数组（排序）
//     ll inv = calc(a, t, l, mid) + calc(a, t, mid + 1, r);

//     int i = l, j = mid + 1, k = l;
//     // 合并
//     while (i <= mid && j <= r)
//     {
//         if (a[i] <= a[j])
//         {
//             t[k++] = a[i++];
//         }
//         else
//         {
//             t[k++] = a[j++];

//             // 左半边剩余的所有元素都大于a[j]
//             inv += (mid - i + 1);
//         }
//     }

//     while (i <= mid)
//     {
//         t[k++] = a[i++];
//     }
//     while (j <= r)
//     {
//         t[k++] = a[j++];
//     }

//     for (i = l; i <= r; i++)
//     {
//         a[i] = t[i];
//     }

//     return inv;
// }

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

//         vector<int> a(n), b(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin>>b[i];
//         }

//         // 离散化 a
//         vector<int> at = a;
//         sort(at.begin(), at.end());
//         vector<int> rankA(n);
//         for (int i = 0; i < n; i++)
//         {
//             rankA[i] = lower_bound(at.begin(), at.end(), a[i]) - at.begin() + 1;
//         }
//         // 离散化 b
//         vector<int> bt = b;
//         sort(bt.begin(), bt.end());
//         vector<int> rankB(n);
//         for (int i = 0; i < n; i++)
//         {
//             rankB[i] = lower_bound(bt.begin(), bt.end(), b[i]) - bt.begin() + 1;
//         }

//         // pos[排名] = 在 a 中的下标
//         vector<int> pos(n + 1);
//         for (int i = 0; i < n; i++)
//         {
//             pos[rankA[i]] = i;
//         }

//         // c：b 中第 i 个元素应该放到的位置
//         vector<int> c(n);
//         for (int i = 0; i < n; i++)
//         {
//             c[i] = pos[rankB[i]];
//         }

//         vector<int> t(n);
//         // 一次相邻交换最多减少一个逆序对
//         // 冒泡排序的实际交换次数恰好等于初始的逆序对数
//         // 则，最小相邻交换次数，即为逆序对数
        
//         ll inv = calc(c, t, 0, n - 1);

//         cout<<inv % mod<<endl;
//     }

//     return 0;
// }