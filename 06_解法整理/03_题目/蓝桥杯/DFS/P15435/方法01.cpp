// 原始稿：03_题目/蓝桥杯/DFS/P15435.cpp
// 原文行号：1-83；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n;
vector<int> perm;;
vector<bool> used;
int cur = -1;
int ans = 1e9;

// DFS枚举
void dfs(int cnt)
{
    if (cnt == 8)
    {   // 将其转化为字符串
        string s;
        for (int d : perm)
        {
            s += d + '0';
        }

        // 在 8 位数的各个位置插入一个 1-8的数字
        for (int pos = 0; pos <= 8; pos++)
        {
            for (int d = 1; d <= 8; d++)
            {
                string t = s;
                t.insert(pos, 1, d + '0');

                int num = stoi(t);
                int g = __gcd(num, n);
                if (g > cur)
                {
                    cur = g;
                    ans = num;
                }
                else if (g == cur)
                {
                    ans = min(ans, num);
                }
            }
        }

        return;
    }
    // 枚举 8 位数的全排列
    for (int i = 1; i <= 8; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            perm.push_back(i);
            dfs(cnt + 1);
            used[i] = false;
            perm.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        cin>>n;

        used.assign(9, false);

        dfs(0);

        cout<<ans<<endl;
    }

    return 0;
}
