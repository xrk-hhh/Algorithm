// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 是否含有共鸣数（0/2/4）
// bool check(int x)
// {
//     if (x == 0)
//     {
//         return true;
//     }
//     while (x)
//     {
//         int tx = x % 10;
//         if (tx == 0 || tx == 2 || tx == 4)
//         {
//             return true;
//         }
//         x /= 10;
//     }
//     return false;
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

//         vector<int> s(n), t(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>s[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin>>t[i];
//         }
        
//         int ans = 0;
//         // 谁的回合
//         int turn = 1;
//         for (int i = 0; i < n; i++)
//         {
//             // s的回合
//             if (turn == 1)
//             {
//                 if (check(s[i]))
//                 {
//                     ans++;
//                     turn = 2;
//                 }
//             }
//             // t的回合
//             else
//             {
//                 if (check(t[i]))
//                 {
//                     ans++;
//                     turn = 1;
//                 }
//             }
//         }
        
//         cout<<ans<<endl;
//     }

//     return 0;
// }