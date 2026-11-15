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
//         string s, t;
//         cin>>s>>t;

//         // int ls = s.size();
//         // int lt = t.size();
//         // string st;
//         // int lst = 0;
//         // for (int i = 0; i < lt; i++)
//         // {
//         //     st += t[i];
//         //     lst++;
//         //     int k = 0;
//         //     bool ok = false;
//         //     for (int j = 0; j < ls; j++)
//         //     {
//         //         if (k == lst)
//         //         {
//         //             ok = true;
//         //             break;
//         //         }
//         //         if (s[j] == st[k])
//         //         {
//         //             k++;
//         //         }
//         //     }
//         //     if (!ok)
//         //     {
//         //         cout<<lst - 1<<endl;
//         //         return 0;
//         //     }
//         // }

//         // cout<<lt<<endl;

//         int ans = 0;
//         // 双指针优化
//         for (int i = 0, j = 0; i < s.size() && j < t.size(); i++)
//         {
//             if (s[i] == t[j])
//             {
//                 ans++;
//                 j++;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }