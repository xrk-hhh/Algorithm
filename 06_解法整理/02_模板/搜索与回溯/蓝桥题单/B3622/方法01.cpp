// 原始稿：02_模板/搜索与回溯/蓝桥题单/B3622.cpp
// 原文行号：1-60；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int n;
// string ans;

// void dfs(int pos)
// {
//     if (pos == n)
//     {
//         cout<<ans<<endl;
//         return;
//     }

//     ans.push_back('N');
//     dfs(pos + 1);
//     ans.pop_back();
//     ans.push_back('Y');
//     dfs(pos + 1);
//     ans.pop_back();
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

        // 枚举子集（递归实现指数型枚举）
        // dfs(0);

        for (int mask = 0; mask < (1 << n); mask++)
        {
            string ans;
            for (int i = n - 1; i >= 0; i--)
            {
                if (mask >> i & 1)
                {
                    ans.push_back('Y');
                }
                else
                {
                    ans.push_back('N');
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
