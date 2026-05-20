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

//         deque<int> dq;
//         for (int i = 1; i <= n; i++)
//         {
//             dq.push_back(i);
//         }

//         bool ok = true;
//         for (int i = 1; i <= n; i++)
//         {
//             if (a[i] == dq.front())
//             {
//                 dq.pop_front();
//             }
//             else if (a[i] == dq.back())
//             {
//                 dq.pop_back();
//             }
//             else
//             {
//                 ok = false;
//                 break;
//             }
//         }

//         if (ok)
//         {
//             cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//     }

//     return 0;
// }