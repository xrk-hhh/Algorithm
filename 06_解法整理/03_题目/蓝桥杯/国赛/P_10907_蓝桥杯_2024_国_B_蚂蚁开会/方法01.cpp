// 原始稿：03_题目/蓝桥杯/国赛/P_10907_蓝桥杯_2024_国_B_蚂蚁开会.cpp
// 原文行号：1-69；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n;
        cin>>n;

        // 考虑到共线重叠、平行等问题处理过于麻烦
        // 且直接求出所有线段交点再判断是否为整点过于麻烦
        // 则 考虑正难则反
        // 即 直接把线段上的整点扔进 map 里，判断这个点的出现次数是否 >= 2即可

        // 那么，如何求出线段上的整点呢？
        // 可以考虑把线段看成向量
        // 那么只需求出其单位向量，再把它分解到 x轴 和 y轴 上
        // 这样每走一个单位步长，即可得到一个整点

        // 键 = x * mod + y，值 = 出现次数
        unordered_map<ll, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;

            int dx = x2 - x1, dy = y2 - y1;
            int g = __gcd(abs(dx), abs(dy));

            // 整点步长
            int sx = dx / g, sy = dy / g;
            for (int j = 0; j <= g; j++)
            {
                ll x = x1 + j * sx;
                ll y = y1 + j * sy;

                // 坐标组合成唯一值
                ll p = x * mod + y;

                mp[p]++;
            }
        }

        int ans = 0;
        for (auto& binding_value_01 : mp)
        {
            auto& p = binding_value_01.first;
            auto& cnt = binding_value_01.second;
            if (cnt >= 2)
            {
                ans++;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
