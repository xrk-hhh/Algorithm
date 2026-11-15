// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

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

//         // 无法拼出任何正整数（最小数字1需要2根）
//         if (n < 2)
//         {
//             cout<<-1<<endl;
//             continue;
//         }

//         // 最少位数：每个数字最多用7根，所以位数至少 ceil(n/7)
//         int len = (n + 6) / 7;

//         string ans;

//         // 剩余火柴数
//         int rem = n;
//         for (int i = 0; i < len; i++)
//         {
//             // 首位不能为0
//             int start = (i == 0) ? 1 : 0;
//             for (int k = start; k <= 9; k++)
//             {
//                 int need = cost[k];
//                 if (need > rem)
//                 {
//                     continue;
//                 }

//                 // 剩余位数
//                 int l = len - i - 1;
//                 int rest = rem - need;
//                 // 剩余火柴数必须能由 left 位拼成：每位至少2根，最多7根
//                 if (l * 2 <= rest && rest <= l * 7)
//                 {
//                     ans.push_back('0' + k);
//                     rem = rest;
//                     break;
//                 }
//             }
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }