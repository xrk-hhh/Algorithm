// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MAXN = 40000;

// vector<int> prime;
// vector<bool> check0(MAXN + 1, true);

// void init()
// {
//     check0[0] = false;
//     check0[1] = false;
//     for (int i = 2; i <= MAXN; i++)
//     {
//         if (check0[i])
//         {
//             prime.push_back(i);
//             for (int j = i * 2; j <= MAXN; j += i)
//             {
//                 check0[j] = false;  
//             }
//         }
//     }
// }

// vector<int> fac(int x)
// {
//     vector<int> res;
//     if (!(x & 1))
//     {
//         res.push_back(2);
//         while (!(x & 1))
//         {
//             x >>= 1;
//         }
//     }

//     for (int p : prime)
//     {
//         if (p * p > x)
//         {
//             break;
//         }
//         if (x % p == 0)
//         {
//             res.push_back(p);
//             while (x % p == 0)
//             {
//                 x /= p;
//             }
//         }
//     }

//     if (x > 1)
//     {
//         res.push_back(x);
//     }

//     return res;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     init();

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         unordered_map<int, int> mp;
//         bool check = false;

//         for (int i = 0; i < n; i++)
//         {
//             int x = a[i];
//             if (x == 1)
//             {
//                 continue;
//             }

//             auto ft = fac(x);
//             for (auto p : ft)
//             {
//                 if (mp.count(p))
//                 {
//                     cout<<mp[p]<<' '<<x<<endl;
//                     check = true;
//                     break;
//                 }
//             }

//             if (check)
//             {
//                 break;
//             }

//             for (int p : ft)
//             {
//                 mp[p] = x;
//             }
//         }

//         if (!check)
//         {
//             cout<<-1<<endl;
//         }
//     }

//     return 0;
// }