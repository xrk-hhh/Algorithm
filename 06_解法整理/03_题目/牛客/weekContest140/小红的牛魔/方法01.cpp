// 原始稿：03_题目/牛客/weekContest140/小红的牛魔.cpp
// 原文行号：1-55；恢复外层注释 1 层；保留方法内部注释。
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

        string s;
        cin>>s;

        vector<char> st;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            st.push_back(c);

            int t = st.size();

            if (t >= 3 && st[t - 3] == 'n' && st[t - 2] == 'i' && st[t - 1] == 'u')
            {
                st.pop_back();
                st.pop_back();
                st.pop_back();
            }
            else if (t >= 2 && st[t - 2] == 'm' && st[t - 1] == 'o')
            {
                st.pop_back();
                st.pop_back();
            }
        }

        if (st.empty())
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
