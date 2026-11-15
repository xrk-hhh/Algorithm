// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int MAXN = 1e3 + 10;

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

//         vector<vector<int>> d(MAXN, vector<int>(MAXN, 0));
//         for (int i = 0; i < n; i++)
//         {
//             int x, y, r;
//             cin>>x>>y>>r;

//             int miny = max(1, y - r), maxy = min(1000, y + r);
//             for (int j = miny; j <= maxy; j++)
//             {
//                 int dy = abs(j - y);
//                 int d2 = r * r - dy * dy;
//                 int dx = sqrt(d2);

//                 while ((dx + 1) * (dx + 1) <= d2)
//                 {
//                     dx++;
//                 }

//                 while (dx * dx > d2)
//                 {
//                     dx--;
//                 }

//                 int l = max(1, x - dx), r = min(1000, x + dx);
//                 d[j][l] += 1;
//                 if (r + 1 <= 1000)
//                 {
//                     d[j][r + 1] -= 1;
//                 }
//             }
//         }

//         vector<vector<bool>> ok(MAXN, vector<bool>(MAXN, false)); 
//         for (int y = 1; y <= 1000; y++)
//         {
//             int cur = 0;
//             for (int x = 1; x <= 1000; x++)
//             {
//                 cur += d[y][x];
//                 ok[y][x] = (cur & 1);
//             }
//         }

//         int q;
//         cin>>q;

//         while (q--)
//         {
//             int qx, qy;
//             cin>>qx>>qy;

//             if (ok[qy][qx])
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