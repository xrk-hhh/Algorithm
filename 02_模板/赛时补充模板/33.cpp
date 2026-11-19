#include <bits/stdc++.h>
using namespace std;

// 下标0..n-1，每颗豆子可从i分裂成j,k，要求i<j<=k<n
struct SplitGame
{
    vector<int> sg;
    int all = 0;
    SplitGame(const vector<int> &a)
    {
        int n = a.size();
        sg.resize(n);
        for (int i = n - 1; i >= 0; i--)
        {
            set<int> seen;
            for (int j = i + 1; j < n; j++)
                for (int k = j; k < n; k++)
                    seen.insert(sg[j] ^ sg[k]);
            while (seen.count(sg[i]))
                sg[i]++;
        }
        for (int i = 0; i < n; i++)
            if (a[i] & 1)
                all ^= sg[i];
    }
    vector<array<int, 3>> winning(const vector<int> &a)
    {
        vector<array<int, 3>> ans;
        int n = a.size();
        for (int i = 0; i < n; i++)
            if (a[i])
                for (int j = i + 1; j < n; j++)
                    for (int k = j; k < n; k++)
                        if ((all ^ sg[i] ^ sg[j] ^ sg[k]) == 0)
                            ans.push_back({i, j, k});
        return ans;
    }
}; // 仅枚举确实有豆子的起点；无合法操作为败态
