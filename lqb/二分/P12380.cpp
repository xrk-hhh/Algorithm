// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, len;
// vector<pair<ll, ll>> ls;

// bool check(int x)
// {
//     vector<pair<ll, ll>> t;
//     for (int i = 0; i < n; i++)
//     {
//         ll L = ls[i].first, S = ls[i].second;
//         // 如果 时间 x < S，则它还没有打开，不产生覆盖
//         if (x < S)
//         {
//             continue;
//         }

//         // 左右最远覆盖区间
//         ll l = max(1LL, L - (x - S));
//         ll r = min((ll)len, (ll)L + (x - S));

//         t.push_back({l, r});
//     }

//     sort(t.begin(), t.end());

//     // 维护当前覆盖的最右端点
//     ll cover = 0;
//     // 判断这些区间的并集是否覆盖了整个[1, len]
//     for (int i = 0; i < t.size(); i++)
//     {
//         ll l = t[i].first, r = t[i].second;
//         // 出现空隙，无法覆盖
//         if (l > cover + 1)
//         {
//             break;
//         }

//         cover = max(cover, r);

//         if (cover >= len)
//         {
//             return true;
//         }
//     }

//     return cover >= len;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
        
//         cin>>n>>len;
//         ls.resize(n);
//         ll maxx = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>ls[i].first>>ls[i].second;
//             maxx = max(maxx, ls[i].second);
//         }

//         ll low = 0, high = maxx + len;
//         // 二分答案（最小值）
//         while (low < high)
//         {
//             ll mid = (low + high) >> 1;
//             if (check(mid))
//             {
//                 high = mid;
//             }
//             else
//             {
//                 low = mid + 1;
//             }
//         }

//         cout<<low<<endl;
//     }

//     return 0;
// }