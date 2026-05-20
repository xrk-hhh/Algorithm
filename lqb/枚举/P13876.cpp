// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// bool is_leap(int y)
// {
//     return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int ans = 0;
//         for (int y = 2000; y < 2000000; y++)
//         {
//             for (int m = 1; m <= 12; m++)
//             {
//                 if (y % m != 0)
//                 {
//                     continue;
//                 }
//                 int dd = days[m - 1];
//                 if (m == 2 && is_leap(y))
//                 {
//                     dd++;
//                 }
//                 for (int d = 1; d <= dd; d++)
//                 {
//                     if (y % d == 0)
//                     {
//                         ans++;
//                     }
//                 }
//             }
//         }

//         ans++;

//         cout<<ans<<endl;
//     }

//     return 0;
// }