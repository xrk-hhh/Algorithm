// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// bool check(int x)
// {
//     for (int i = 1; x; i++)
//     {
//         int tmp = x % 10;
//         if (((i & 1) && !(tmp & 1)) || (!(i & 1) && (tmp & 1)))
//         {
//             return false;
//         }
//         x /= 10;
//     }
//     return true;
// }

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

//         int cnt = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             if (check(i))
//             {
//                 cnt++;
//             }
//         }

//         cout<<cnt<<endl;
//     }

//     return 0;
// }