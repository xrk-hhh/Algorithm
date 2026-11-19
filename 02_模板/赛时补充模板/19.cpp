#include <bits/stdc++.h>
using namespace std;

bool nim_win(const vector<int> &a)
{
    int x = 0;
    for (int v : a)
        x ^= v;
    return x != 0;
}
// 有限取子集合moves，每次从一堆减去其中一个正数
vector<int> get_sg(int n, const vector<int> &moves)
{
    vector<int> sg(n + 1), seen(moves.size() + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        for (int d : moves)
            if (d <= i && sg[i - d] < (int)seen.size())
                seen[sg[i - d]] = i;
        while (sg[i] < (int)seen.size() && seen[sg[i]] == i)
            sg[i]++;
    }
    return sg;
} // 多堆独立游戏异或各自sg；moves中的步长必须>0
