// 原始稿：03_题目/蓝桥杯/2/2.4/09.cpp
// 原文行号：1-102；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n;
vector<int> a;
int maxx = 0;

// 判断是否满足条件

// bool check(vector<int> b)
// {
//     for (int i = 1; i < b.size(); i++)
//     {
//         if ((b[i] & b[i - 1]) == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// DFS得部分分， 核心：选/不选

// void dfs(int idx, vector<int> b, int cnt)
// {
//     if (idx == n)
//     {
//         maxx = max(maxx, cnt);
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

        // 位掩码得部分分，核心：选/不选
        // int maxx = 0;
        // for (int mask = 1; mask < (1 << n); mask++)
        // {
        //     int cnt = 0;
        //     vector<int> b;
        //     bool ok = true;
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
        //                 b.pop_back();
        //                 ok = false;
        //                 break;
        //             }
        //         }
        //     }
        //     if (ok)
        //     {
        //         maxx = max(maxx, cnt);
        //     }
        // }

        // vector<int> b;

        // dfs(0, b, 0);

        cout<<maxx<<endl;
    }

    return 0;
}
