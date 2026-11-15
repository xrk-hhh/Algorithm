// 原始稿：03_题目/AtCoder/AT_abc_126_a_ABC_126_A_Changing_a_Character.cpp
// 原文行号：1-28；恢复外层注释 1 层；保留方法内部注释。
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
        int n, k;
        cin>>n>>k;

        string s;
        cin>>s;

        s[k - 1] = s[k - 1] - 'A' + 'a';
        cout<<s<<endl;
    }

    return 0;
}
