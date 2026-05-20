// // #include <bits/stdc++.h>
// // using namespace std;

// // #define ll long long

// // int main()
// // {
// //     int T;
// //     cin>>T;

// //     while (T--)
// //     {
// //         int n;
// //         cin>>n;

// //         int minn = 1000000001, maxx = -1000000001;
// //         ll sum1 = 0;
// //         ll sum2 = 0.0;
// //         for (int i = 0; i < n; i++)
// //         {
// //             int num;
// //             cin>>num;
// //             if (num > maxx)
// //             {
// //                 maxx = num;
// //             }
// //             if (num < minn)
// //             {
// //                 minn = num;
// //             }

// //             sum1 += num;
// //             sum2 += num * num;
// //         }

// //         ll ans1 = maxx - minn;

// //         double avg = sum1 * 1.0 / n;
// //         double ans2 = sum2 * 1.0 / n - avg * avg;

// //         cout<<ans1<<' '<<fixed<<setprecision(3)<<ans2<<endl;
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// int a[100010];

// int main()
// {
//     int T;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         int minn = 1000000001, maxx = -1000000001;
//         ll sum1 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             if (a[i] > maxx)
//             {
//                 maxx = a[i];
//             }
//             if (a[i] < minn)
//             {
//                 minn = a[i];
//             }

//             sum1 += a[i];
//         }

//         ll ans1 = maxx - minn;

//         double avg = sum1 * 1.0 / n;
//         double sum2 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             sum2 += (a[i] - avg) * (a[i] - avg);
//         }

//         double ans2 = sum2 / n;

//         cout<<ans1<<' '<<fixed<<setprecision(3)<<ans2<<endl;
//     }

//     return 0;
// }