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
//         int n;
//         cin>>n;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         string s;
//         cin>>s;

//         ll sum0 = 0, sum1 = 0;
//         int cnt0 = 0, cnt1 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (s[i] == '0')
//             {
//                 sum0 += a[i];
//                 cnt0++;
//             }
//             else
//             {
//                 sum1 += a[i];
//                 cnt1++;
//             }
//         }

//         ll ans = labs(cnt0 * sum1 - cnt1 * sum0);
//         if (ans % n == 0)
//         {
//             cout<<ans / n<<endl;
//         }
//         else
//         {
//             cout<<-1<<endl;
//         }
//     }

//     return 0;
// }