// 原始稿：03_题目/牛客/contest/02/i.cpp
// 原文行号：1-129；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define pr pair<int, int>
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        vector<string> a(n);

        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        vector<vector<int>> cp(n, vector<int>(m, -1));
        vector<pr> cnt;
        int idx = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (cp[i][j] == -1)
                {
                    queue<pr> q;
                    q.push({i, j});

                    cp[i][j] = idx;

                    int cnt0 = 0, cnt1 = 0;

                    if (a[i][j] == '0')
                    {
                        cnt0++;
                    }
                    else
                    {
                        cnt1++;
                    }

                    while (!q.empty())
                    {
                        auto binding_value_01 = q.front();
                        auto x = binding_value_01.first;
                        auto y = binding_value_01.second;
                        q.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && cp[nx][ny] == -1)
                            {
                                cp[nx][ny] = idx;

                                if (a[nx][ny] == '0')
                                {
                                    cnt0++;
                                }
                                else
                                {
                                    cnt1++;
                                }

                                q.push({nx, ny});
                            }
                        }
                    }

                    cnt.push_back({cnt0, cnt1});

                    idx++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int c = cp[i][j];

                if (a[i][j] == '0')
                {
                    if (cnt[c].first >= 2)
                    {
                        cout<<'Y';
                    }
                    else
                    {
                        cout<<'N';
                    }
                }
                else
                {
                    if (cnt[c].second >= 2)
                    {
                        cout<<'Y';
                    }
                    else
                    {
                        cout<<'N';
                    }
                }
            }
            cout<<endl;
        }
    }

    return 0;
}
