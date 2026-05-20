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

//         vector<ll> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         string s;
//         cin>>s;

//         int cnt = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (a[i] >= 0 && s[i] == '<')
//             {
//                 a[i] = -1;
//                 cnt++;
//             }
//             else if (a[i] <= 0 && s[i] == '>')
//             {
//                 a[i] = 1;
//                 cnt++;
//             }
//         }

//         for (int i = 1; i < n; i++)
//         {
//             if (s[i] == 'Z' && a[i] * a[i - 1] <= 0)
//             {
//                 if (a[i] > 0)
//                 {
//                     a[i] = -1;
//                 }
//                 else if (a[i] < 0)
//                 {
//                     a[i] = 1;
//                 }
//                 else
//                 {
//                     a[i] = a[i - 1];
//                 }
//                 cnt++;
//             }
//         }

//         cout<<cnt<<endl;
//     }

//     return 0;
// }