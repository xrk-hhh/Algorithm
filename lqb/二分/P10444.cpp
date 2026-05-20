// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1, id;
//     cin>>T>>id;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         sort(a.begin(), a.end());

//         // 注意到，对 a 排序后，最小值为a[0]，最大值为a[n - 1]
//         // 只要满足 a[i] - a[0] = a[n - 1] - a[j]，且 i < j
//         // 那么一定能将序列分成两部分

//         ll sum = a[0] + a[n - 1];

//         bool ok = false;
//         for (int i = 1; i < n - 2; i++)
//         {
//             // 考虑寻找满足条件的a[i]和a[j]，有a[i] + a[j] = sum
//             // 可枚举 a[i]，然后再二分查找 a[j]
//             bool vis = binary_search(a.begin() + i + 1, a.end() - 1, sum - a[i]);

//             if (vis)
//             {
//                 ok = true;
//                 break;
//             }
//         }
        
//         if (ok)
//         {
//             cout<<"Yes"<<endl;
//         }
//         else
//         {
//             cout<<"No"<<endl;
//         }
//     }

//     return 0;
// }