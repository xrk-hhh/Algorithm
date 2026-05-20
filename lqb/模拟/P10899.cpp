// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int cnt = 2000;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         vector<char> c1(cnt), c2(cnt);
//         vector<ll> c3(cnt);
//         for (int i = 0; i < cnt; i++)
//         {
//             cin>>c1[i]>>c2[i]>>c3[i];
//         }

//         int maxx = 0;
//         int cur = 1;
//         for (int i = 0; i < cnt - 1; i++)
//         {
//             if (c1[i] == c2[i] && c1[i + 1] == c2[i + 1] && labs(c3[i + 1] - c3[i]) <= 1000)
//             {
//                 cur++;
//             }
//             else
//             {
//                 maxx = max(maxx, cur);
//                 cur = 1;
//             }
//         }

//         cout<<maxx<<endl;
//     }

//     return 0;
// }