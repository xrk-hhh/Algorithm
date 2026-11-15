//#include <bits/stdc++.h>
//using namespace std;
//
//#define endl '\n'
//using ll = long long;
//
//int n, sum;
//vector<int> xishu;
//vector<int> ans;
//vector<bool> used;
//
//pair<int, int> bound(int pos, int cur)
//{
//    vector<int> rest_xishu(xishu.begin() + pos, xishu.end());
//    vector<int> rest;
//
//    for (int i = 1; i <= n; i++)
//    {
//        if (!used[i])
//        {
//            rest.push_back(i);
//        }
//    }
//
//    sort(rest_xishu.begin(), rest_xishu.end());
//    sort(rest.begin(), rest.end());
//
//    int minn = 0, maxx = 0;
//    int m = rest_xishu.size();
//    for (int i = 0; i < m; i++)
//    {
//        minn += rest_xishu[i] * rest[m - 1 - i];
//        maxx += rest_xishu[i] * rest[i];
//    }
//
//    return {cur + minn, cur + maxx};
//}
//
//bool dfs(int pos, int cur)
//{
//    if (pos == n)
//    {
//        return cur == sum;
//    }
//
//    auto it = bound(pos, cur);
//    int low = it.first;
//    int high = it.second;
//    if (low > sum || high < sum)
//    {
//        return false;
//    }
//
//    for (int i = 1; i <= n; i++)
//    {
//        if (!used[i])
//        {
//            used[i] = true;
//            ans.push_back(i);
//
//            if (dfs(pos + 1, cur + xishu[pos] * i))
//            {
//                return true;
//            }
//
//            ans.pop_back();
//            used[i] = false;
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T = 1;
//    // cin>>T;
//
//    while (T--)
//    {
//        cin>>n>>sum;
//
//        xishu.resize(n);
//        vector<vector<int>> C(n, vector<int>(n, 0));
//        for (int i = 0; i < n; i++)
//        {
//            C[i][0] = C[i][i] = 1;
//            for (int j = 1; j < i; j++)
//            {
//                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
//            }
//        }
//
//        for (int i = 0; i < n; i++)
//        {
//            xishu[i] = C[n - 1][i];
//        }
//
//        used.assign(n + 1, false);
//
//        if (dfs(0, 0))
//        {
//            for (int i = 0; i < n; i++)
//            {
//                cout<<ans[i]<<' ';
//            }
//            cout<<endl;
//        }
//    }
//
//    return 0;
//}
