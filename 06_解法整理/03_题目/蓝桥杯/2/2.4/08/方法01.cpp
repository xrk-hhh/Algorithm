// 原始稿：03_题目/蓝桥杯/2/2.4/08.cpp
// 原文行号：1-100；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n;
int ans = 0;
vector<string> a;

// 判断当前数列是否为接龙数列

// bool check(vector<string> b)
// {
//     for (int i = 1; i < b.size(); i++)
//     {
//         if (*(b[i].begin()) != *(b[i - 1].end() - 1))
//         {
//             return false;
//         }
//     }
//     return true;
// }

// DFS得部分分，核心：选/不选

// void dfs(int idx, vector<string> b, int cnt)
// {
//     if (idx == n)
//     {
//         ans = max(ans, cnt);
//         return;
//     }

//     dfs(idx + 1, b, cnt);

//     b.push_back(a[idx]);
//     if (check(b))
//     {
//         dfs(idx + 1, b, cnt + 1);
//     }
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        cin>>n;

        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        
        // dfs(0, b, 0);

        // 位掩码得部分分，核心：选/不选

        // for (int mask = 1; mask < (1 << n); mask++)
        // {
        //     int cnt = 0;
        //     bool ok = true;
        //     vector<string> b;
        //     for (int i = 0; i < n; i++)
        //     {
        //         if ((mask >> i) & 1)
        //         {
        //             b.push_back(a[i]);
        //             if (check(b))
        //             {
        //                 cnt++;
        //             }
        //             else
        //             {
        //                 ok = false;
        //                 b.pop_back();
        //                 break;
        //             }
        //         }
        //     }
        //     if (ok)
        //     {
        //         ans = max(ans, cnt);
        //     }
        // }

        cout<<n - ans<<endl;
    }

    return 0;
}
