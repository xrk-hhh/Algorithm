// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e8;

// vector<int> primes;
// bool is_composite[N + 10];

// // 线性筛素数
// void linear_sieve(int n)
// {
//     for (int i = 2; i <= n; i++)
//     {
//         if (!is_composite[i])
//         {
//             primes.push_back(i);
//         }

//         for (int p : primes)
//         {
//             if (i * p > n)
//             {
//                 break;
//             }

//             is_composite[i * p] = true;

//             if (i % p == 0)
//             {
//                 break;
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, q;
//         cin>>n>>q;

//         linear_sieve(n);

//         while (q--)
//         {
//             int k;
//             cin>>k;

//             cout<<primes[k - 1]<<endl;
//         }
//     }

//     return 0;
// }