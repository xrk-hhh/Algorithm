// 原始稿：02_模板/栈与单调栈/蓝桥题单/P1950.cpp
// 原文行号：1-70；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        vector<string> g(n);
        for (int i = 0; i < n; i++)
        {
            cin>>g[i];
        }
        
        vector<int> h(m, 0);
        ll ans = 0;
        // 每个矩形由其下边界（当前行）唯一确定，因此不会重复
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == '.')
                {
                    h[j]++;
                }
                else
                {
                    h[j] = 0;
                }
            }

            stack<pair<int, int>> st;
            // 以当前列为右边界的所有矩形的个数
            ll sum = 0;
            for (int j = 0; j < m; j++)
            {
                // 连续多少个列的高度 >= 该高度
                int ww = 1;
                while (!st.empty() && st.top().first > h[j])
                {
                    auto binding_value_01 = st.top();
                    auto hh = binding_value_01.first;
                    auto w = binding_value_01.second;
                    st.pop();

                    // 去被弹出部分贡献的矩形数
                    sum -= 1LL * hh * w;
                    ww += w;
                }

                st.push({h[j], ww});
                sum += 1LL * h[j] * ww;
                ans += sum;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
