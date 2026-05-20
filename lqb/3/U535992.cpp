// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n, k;
//         cin>>n>>k;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         // 排序后，答案一定是某个区间[i, j]的极差 a[j] - a[i]
//         // 要使 a[i] 成为最小值，则需要将左边所有小于 a[i] 的元素变大，至少需要 i 次操作
//         // 同理，要使 a[j] 成为最大值，则需要将右边所有大于 a[j] 的元素变小，至少需要 n - 1 - j 次操作
//         // 但是，操作可以重叠：将小变大时，产生的新值可能成为新的最大值，可以用于后续将大变小
//         // 因此，实际最小操作次数为 i + (n - 1 - j) + min(i, n - 1 - j)
//         sort(a.begin(), a.end());

//         int ans = a[n - 1] - a[0];
//         // 枚举 i
//         for (int i = 0; i < n; i++)
//         {
//             int l = i, r = n - 1;
//             if (i - 0 > k)
//             {
//                 break;
//             }

//             // 二分查找最小的 j，使得操作次数 <= k
//             while (l < r)
//             {
//                 int mid = (l + r) >> 1;
//                 if ((i - 0) + (n - 1 - mid) + min(i - 0, n - 1 - mid) <= k)
//                 {
//                     r = mid;
//                 }
//                 else
//                 {
//                     l = mid + 1;
//                 }
//             }

//             ans = min(ans, a[l] - a[i]);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }