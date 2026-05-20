// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MAXP = 25;

// const int prime[MAXP] = 
// {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

// int get_mask(int x)
// {
//     int mask = 0;
//     for (int i = 0; i < MAXP; i++)
//     {
//         int p = prime[i];
//         int cnt = 0;
//         while (x % p == 0)
//         {
//             cnt++;
//             x /= p;
//         }

//         if (cnt & 1)
//         {
//             mask |= (1 << i);
//         }
//     }
//     return mask;
// }

// bool query(int l, int r, const vector<int>& mask)
// {
//     vector<int> vec;
//     for (int i = l - 1; i < r; i++)
//     {
//         if (mask[i] == 0)
//         {
//             return true;
//         }
//         vec.push_back(mask[i]);
//     }

//     if (vec.size() > MAXP)
//     {
//         return true;
//     }

//     vector<int> base(MAXP);
//     for (int i = 0; i < vec.size(); i++)
//     {
//         int x = vec[i];
//         for (int j = MAXP - 1; j >= 0; j--)
//         {
//             if ((x >> j) & 1)
//             {
//                 if (base[j])
//                 {
//                     x ^= base[j];
//                 }
//                 else
//                 {
//                     base[j] = x;
//                     break;
//                 }
//             }
//         }

//         if (x == 0)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// // bool is_prime(int x)
// // {
// //     if (x == 1)
// //     {
// //         return false;
// //     }
// //     if (x == 2)
// //     {
// //         return true;
// //     }
// //     if (!(x & 1))
// //     {
// //         return false;
// //     }

// //     int tmp = sqrt(x);
// //     for (int i = 3; i <= tmp; i += 2)
// //     {
// //         if (x % i == 0)
// //         {
// //             return false;
// //         }
// //     }
// //     return true;
// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     // vector<int> prime;
//     // // 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
//     // for (int i = 1; i <= 100; i++)
//     // {
//     //     if (is_prime(i))
//     //     {
//     //         cout<<i<<' ';
//     //         prime.push_back(i);
//     //     }
//     // }

//     // cout<<endl;

//     // cout<<prime.size()<<endl;// 25

//     while (T--)
//     {
//         int n, q;
//         cin>>n>>q;

//         vector<int> a(n);
//         vector<int> mask(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             mask[i] = get_mask(a[i]);
//         }

//         while (q--)
//         {
//             int l, r;
//             cin>>l>>r;

//             if (query(l, r, mask))
//             {
//                 cout<<"Yes"<<endl;
//             }
//             else
//             {
//                 cout<<"No"<<endl;
//             }
//         }
//     }

//     return 0;
// }