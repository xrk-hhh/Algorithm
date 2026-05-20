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
//         int n;
//         cin>>n;

//         vector<int> a(n + 1);
//         ll sum = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//             sum += a[i];
//         }

//         if (sum % n != 0)
//         {
//             cout<<"NO"<<endl;
//         }
//         else
//         {
//             int t = sum / n;

//             // 与平均值的差值
//             vector<int> d(n + 1);
//             for (int i = 1; i <= n; i++)
//             {
//                 d[i] = a[i] - t;
//             }

//             // 注意到，当 1-n 其中一个固定选择后，所有人的选择也就随之固定下来了
//             // 因此，可以枚举 1 的选择，看看合不合法
//             auto check = [&](int start) -> bool
//             {
//                 // 传递值
//                 vector<int> x(n + 1);
//                 x[1] = start;

//                 if (x[1] > a[1])
//                 {
//                     return false;
//                 }

//                 for (int i = 2; i <= n; i++)
//                 {
//                     x[i] = x[i - 1] + d[i];
//                     if (x[i] < 0 || x[i] > 1 || x[i] > a[i])
//                     {
//                         return false;
//                     }
//                 }

//                 return x[1] - x[n] == d[1];
//             };

//             if (check(0) || check(1))
//             {
//                 cout<<"YES"<<endl;
//             }
//             else
//             {
//                 cout<<"NO"<<endl;
//             }
//         }
//     }

//     return 0;
// }