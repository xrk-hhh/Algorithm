// 原始稿：03_题目/蓝桥杯/枚举/P8680.cpp
// 原文行号：1-45；恢复外层注释 1 层；保留方法内部注释。
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
        int n;
        cin>>n;

        int sum = 0;
        set<int> st;
        st.emplace(2);
        st.emplace(0);
        st.emplace(1);
        st.emplace(9);
        for (int i = 1; i <= n; i++)
        {
            int x = i;
            while (x)
            {
                int t = x % 10;
                if (st.count(t))
                {
                    sum += i;
                    break;
                }
                x /= 10;
            }
        }

        cout<<sum<<endl;
    }

    return 0;
}
