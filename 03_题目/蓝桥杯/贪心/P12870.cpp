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

//         int cnt = 0;
//         int sum = 0;
//         int t = n;
//         while (t)
//         {
//             cnt++;
//             sum += t % 10;
//             t /= 10;
//         }

//         if (sum == 1)
//         {
//             cout<<n<<endl;
//             return 0;
//         }

//         ll ans = 1;
//         while (cnt--)
//         {
//             ans *= 10;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }