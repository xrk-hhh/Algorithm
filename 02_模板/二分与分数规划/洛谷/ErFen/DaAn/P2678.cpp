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
//         int L, N, M;
//         cin>>L>>N>>M;

//         vector<int> D(N + 2);
//         for (int i = 1; i <= N; i++)
//         {
//             cin>>D[i];
//         }
//         D[N + 1] = L;

//         auto check = [&](int x) -> bool
//         {
//             int last = 0;
//             int cnt = 0;
//             for (int i = 1; i <= N + 1; i++)
//             {
//                 if (D[i] - D[last] < x)
//                 {
//                     cnt++;
//                 }
//                 else
//                 {
//                     last = i;
//                 }
//             }
//             return cnt <= M;
//         };

//         int l = 0, r = 1e9 + 1;
//         while (l + 1 < r)
//         {
//             int mid = (l + r) >> 1;
//             if (check(mid))
//             {
//                 l = mid;
//             }
//             else
//             {
//                 r = mid;
//             }
//         }

//         cout<<l<<endl;
//     }

//     return 0;
// }