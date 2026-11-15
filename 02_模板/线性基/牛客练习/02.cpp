// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MAXN = 60;

// void insert(ll x, vector<ll>& basis)
// {
//     for (int i = MAXN - 1; i >= 0; i--)
//     {
//         if ((x >> i) & 1)
//         {
//             if (basis[i] == 0)
//             {
//                 basis[i] = x;
//                 break;
//             }
//             else
//             {
//                 x ^= basis[i];
//             }
//         }
//     }
// }

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

//         vector<ll> basis(MAXN, 0);
//         for (int i = 0; i < n; i++)
//         {
//             ll a;
//             cin>>a;
//             insert(a, basis);
//         }

//         int cnt = 0;
//         for (int i = 0; i < MAXN; i++)
//         {
//             if (basis[i] != 0)
//             {
//                 cnt++;
//             }
//         }

//         ll mex = 1LL << MAXN;
//         for (int i = 0; i < MAXN; i++)
//         {
//             if (basis[i] == 0)
//             {
//                 mex = 1LL << i;
//                 break;
//             }
//         }

//         cout<<mex<<endl;
//     }

//     return 0;
// }