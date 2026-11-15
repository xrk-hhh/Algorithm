// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

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

//         vector<int> a(n), b(n);
//         int sum1 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             sum1 ^= a[i];
//         }

//         for (int i = 0; i < n; i++)
//         {
//             cin>>b[i];
//         }

//         int N = 30;
//         vector<int> t1(N, 0), pos(N, -1);
//         vector<int> d(N, 0);

//         for (int i = 0; i < n; i++)
//         {
//             int x = a[i] ^ b[i];
//             int tmp1 = 0;
//             for (int j = N - 1; j >= 0; j--)
//             {
//                 if ((x >> j) & 1)
//                 {
//                     if (t1[j] == 0)
//                     {
//                         t1[j] = x;
//                         pos[j] = i;

//                         d[j] = tmp1;
//                         break; 
//                     }
//                     else
//                     {
//                         tmp1 ^= (1 << j);
//                         x ^= t1[j];
//                         tmp1 ^= d[j];
//                     }
//                 }
//             }
//         }

//         int sum2 = sum1;
//         int tmp2 = 0;
//         bool check1 = true;
//         for (int i = N - 1; i >= 0; i--)
//         {
//             if ((sum2 >> i) & 1)
//             {
//                 if (t1[i] == 0)
//                 {
//                     check1 = false;
//                     break;
//                 }

//                 sum2 ^= t1[i];
//                 tmp2 ^= (1 << i);
//             }
//         }

//         if (!check1 || sum2 != 0)
//         {
//             cout<<-1<<endl;
//             continue;
//         }

//         vector<bool> check2(n, false);
//         for (int i = 0; i < N; i++)
//         {
//             if ((tmp2 >> i) & 1)
//             {
//                 int idx = pos[i];
//                 tmp2 ^= d[i];
//                 if (idx != -1)
//                 {
//                     check2[idx].flip();
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             if (check2[i])
//             {
//                 cout<<b[i]<<' ';
//             }
//             else
//             {
//                 cout<<a[i]<<' ';
//             }
//         }

//         cout<<endl;
//     }

//     return 0;
// }