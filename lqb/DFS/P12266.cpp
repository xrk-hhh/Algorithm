// #include <bits/stdc++.h>
// #include <cstdlib>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// vector<int> a = {5, 5, 10, 10, 15, 15, 20, 20, 25, 25};
// set<int> score;
// int ans = 0;

// void dfs(int pos, int cur)
// {
//     if (pos == 10)
//     {
//         // 该分数之前没有出现过
//         if (!score.count(cur))
//         {
//             score.insert(cur);
//             ans++;
//         }
//         return;
//     }

//     // 得 0 分
//     dfs(pos + 1, cur);

//     // 得 a[pos] 分
//     dfs(pos + 1, cur + a[pos]);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         dfs(0, 0);

//         cout<<ans<<endl;
//     }

//     return 0;
// }