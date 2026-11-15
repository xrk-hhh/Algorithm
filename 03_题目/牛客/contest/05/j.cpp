// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         vector<vector<int>> a(4, vector<int>(4));
//         vector<bool> check(10, false);
//         bool flag = true;
//         for (int i = 1; i <= 3; i++)
//         {
//             for (int j = 1; j <= 3; j++)
//             {
//                 cin>>a[i][j];
//                 if (a[i][j] < 1 || a[i][j] > 9 || check[a[i][j]])
//                 {
//                     flag = false;
//                 }
//                 else
//                 {
//                     check[a[i][j]] = true;
//                 }
//             }
//         }

//         if (!flag)
//         {
//             cout<<"No"<<endl;
//             return 0;
//         }

//         if (a[1][1] + a[2][2] + a[3][3] != 15 || a[3][1] + a[2][2] + a[1][3] != 15)
//         {
//             cout<<"No"<<endl;
//             return 0;
//         }

//         for (int i = 1; i <= 3; i++)
//         {
//             int sum1 = 0, sum2 = 0;
//             for (int j = 1; j <= 3; j++)
//             {
//                 sum1 += a[i][j];
//                 sum2 += a[j][i];
//             }
//             if (sum1 != 15 || sum2 != 15)
//             {
//                 cout<<"No"<<endl;
//                 return 0;
//             }
//         }
        
//         cout<<"Yes"<<endl;
//     }

//     return 0;
// }