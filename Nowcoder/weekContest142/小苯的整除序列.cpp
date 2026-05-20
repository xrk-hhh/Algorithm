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
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         int idx = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             if (a[i] % idx == 0)
//             {
//                 idx++;
//             }
//         }

//         cout<<idx - 1<<endl;
//     }

//     return 0;
// }