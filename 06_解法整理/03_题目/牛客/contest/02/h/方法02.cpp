// 原始稿：03_题目/牛客/contest/02/h.cpp
// 原文行号：54-106；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;

    while (T--)
    {
        int n;
        cin>>n;

        unordered_map<int, int> last_pos;
        
        ll ans = 0;
        ll S = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;

            int prev;

            if (last_pos.count(x))
            {
                prev = last_pos[x];
            }
            else
            {
                prev = -1;
            }

            S += (i - prev);

            ans += S * (n - i);

            last_pos[x] = i;
        }

        cout<<ans<<endl;
    }

    return 0;
}
