// 原始稿：03_题目/蓝桥杯/枚举/P11042.cpp
// 原文行号：1-57；恢复外层注释 1 层；保留方法内部注释。
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
        int maxx = 0;
        for (int i = 1; i <= 10000000; i++)
        {
            vector<int> s;
            int x = i;
            int sum = 0;
            int cnt = 0;
            vector<int> d;
            while (x)
            {
                int t = x % 10;
                d.push_back(t);
                sum += t;
                x /= 10;
                cnt++;
            }

            for (int j = cnt - 1; j >= 0; j--)
            {
                s.push_back(d[j]);
            }
            int k = cnt;
            while (sum < i)
            {
                s.push_back(sum);
                k++;
                sum -= s[k - cnt - 1];
                sum += s[k - 1];
            }

            if (sum == i)
            {
                maxx = max(maxx, sum);
            }
        }

        cout<<maxx<<endl;
    }

    return 0;
}
