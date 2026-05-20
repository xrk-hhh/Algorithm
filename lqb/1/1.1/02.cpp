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

//         string s;
//         cin>>s;

//         string s1, s2;
//         for (int i = 0; i < 2 * n; i++)
//         {
//             if (i & 1)
//             {
//                 s1 += 'B';
//                 s2 += 'A';
//             }
//             else
//             {
//                 s1 += 'A';
//                 s2 += 'B';
//             }
//         }

//         int cnt1 = 0, cnt2 = 0;
//         for (int i = 0; i < 2 * n; i++)
//         {
//             if (s[i] != s1[i])
//             {
//                 cnt1++;
//             }
//             else if (s[i] != s2[i])
//             {
//                 cnt2++;
//             }
//         }

//         cout<<min(cnt1, cnt2) / 2<<endl;
//     }

//     return 0;
// }