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

//         for (int i = 1; i < n; i++)
//         {
//             int dif = abs(a[i] - a[i - 1]);
//             if (dif < 1 || dif > n - 1)
//             {
//                 cout<<"Not jolly"<<endl;
//                 return 0;
//             }
//         }

//         cout<<"Jolly"<<endl;
//     }

//     return 0;
// }