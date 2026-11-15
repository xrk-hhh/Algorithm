// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int x, y;
//         cin>>x>>y;

//         int t = x ^ y;
//         int k = 31 - __builtin_clz(t);

//         int n = (x >> k) & 1 ? 0 : (1 << k);

//         cout<<n<<endl;
//     }

//     return 0;
// }