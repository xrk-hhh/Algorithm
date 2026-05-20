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
//         int N, C;
//         cin>>N>>C;

//         // 方法一：哈希表，时间复杂度 O(n)

//         // 先存储每个数的出现次数

//         // vector<int> a(N);
//         // unordered_map<int, int> cnt;
//         // for (int i = 0; i < N; i++)
//         // {
//         //     cin>>a[i];
//         //     cnt[a[i]]++;
//         // }

//         // 再遍历每个数(B)，累加目标答案(A = B + C)次数
//         // A - B = C  ->  A = B + C 

//         // ll ans = 0;
//         // for (int i = 0; i < N; i++)
//         // {
//         //     ans += cnt[a[i] + C];
//         // }
        
//         // cout<<ans<<endl;

//         // 方法二：排序 + 双指针，时间复杂度 O(nlongn)

//         // 先排序

//         vector<int> a(N);
//         for (int i = 0; i < N; i++)
//         {
//             cin>>a[i];
//         }

//         sort(a.begin(), a.end());

//         // 再求出第一个大于等于(>=)目标答案(target)的指针(p)，第一个大于(>)目标答案(target)的指针(q)
//         // 则目标答案区间为 [p, q)
//         // 答案累加 q - p

//         ll ans = 0;
//         int p = 0, q = 0;
//         for (int i = 0; i < N; i++)
//         {
//             int target = a[i] + C;

//             while (p < N && a[p] < target)
//             {
//                 p++;
//             }

//             while (q < N && a[q] <= target)
//             {
//                 q++;
//             }

//             ans += q - p;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }