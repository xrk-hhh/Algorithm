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
//         int a, b;
//         cin>>a>>b;

//         if (b == 0)
//         {
//             while (a--)
//             {
//                 cout<<'0';
//             }
//             cout<<endl;
//             continue;
//         }
//         else if (a == 0)
//         {
//             while (b--)
//             {
//                 cout<<'1';
//             }
//             cout<<endl;
//             continue;
//         }
//         else
//         {
//             if (b >= a + 1)
//             {
//                 int k = a + 1;
//                 int len = b / k;
//                 int r = b % k;
//                 string s;
//                 for (int i = 0; i < k; i++)
//                 {
//                     if (i < r)
//                     {
//                         int tmp = len + 1;
//                         while (tmp--)
//                         {
//                             s += '1';
//                         }
//                     }
//                     else
//                     {
//                         int tmp = len;
//                         while (tmp--)
//                         {
//                             s += '1';
//                         }
//                     }

//                     if (i != k - 1)
//                     {
//                         s += '0';
//                     }

//                 }

//                 cout<<s<<endl;
//                 continue;
//             }
//             else
//             {
//                 int k = b + 1;
//                 int len = a / k;
//                 int r = a % k;
//                 string s;
//                 for (int i = 0; i < k; i++)
//                 {
//                     if (i < r)
//                     {
//                         int tmp = len + 1;
//                         while (tmp--)
//                         {
//                             s += '0';
//                         }
//                     }
//                     else
//                     {
//                         int tmp = len;
//                         while (tmp--)
//                         {
//                             s += '0';
//                         }
//                     }

//                     if (i != k - 1)
//                     {
//                         s += '1';
//                     }

//                 }

//                 cout<<s<<endl;
//                 continue;
//             }
//         }
//     }

//     return 0;
// }