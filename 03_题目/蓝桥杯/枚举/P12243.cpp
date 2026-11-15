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
//         int ans = 0;
//         for (int i = 1; i <= 1000000; i++)
//         {
//             vector<int> cnt1(11, 0);
//             int x = i;
//             while (x)
//             {
//                 cnt1[x % 10]++;
//                 x /= 10;
//             }
//             for (int j = 1; j * j <= i; j++)
//             {
//                 int k = i / j;
//                 if (j * k == i)
//                 {
//                     vector<int> cnt2(11, 0);
//                     int y = j;
//                     while (y)
//                     {
//                         cnt2[y % 10]++;
//                         y /= 10;
//                     }
//                     int z = k;
//                     while (z)
//                     {
//                         cnt2[z % 10]++;
//                         z /= 10;
//                     }
                    
//                     bool ok = true;
//                     for (int t = 0; t < 10; t++)
//                     {
//                         if (cnt1[t] != cnt2[t])
//                         {
//                             ok = false;
//                         }
//                     }
//                     if (ok)
//                     {
//                         ans++;
//                         break;
//                     }
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }