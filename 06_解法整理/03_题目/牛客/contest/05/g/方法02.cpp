// 原始稿：03_题目/牛客/contest/05/g.cpp
// 原文行号：71-213；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        string s = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";

        int way = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '0')
            {
                if (way == 0)
                {
                    way = 3;
                }
                else if (way == 1)
                {
                    way = 2;
                }
                else if (way == 2)
                {
                    way = 1;
                }
                else if (way == 3)
                {
                    way = 0;
                }
            }
            else if (c == '1')
            {
                if (way == 0)
                {
                    way = 0;
                }
                else if (way == 1)
                {
                    way = 3;
                }
                else if (way == 2)
                {
                    way = 2;
                }
                else if (way == 3)
                {
                    way = 1;
                }
            }
            else if (c == '2')
            {
                if (way == 0)
                {
                    way = 1;
                }
                else if (way == 1)
                {
                    way = 0;
                }
                else if (way == 2)
                {
                    way = 3;
                }
                else if (way == 3)
                {
                    way = 2;
                }
            }
            else if (c == '3')
            {
                if (way == 0)
                {
                    way = 2;
                }
                else if (way == 1)
                {
                    way = 1;
                }
                else if (way == 2)
                {
                    way = 0;
                }
                else if (way == 3)
                {
                    way = 3;
                }
            }
            else if (c == '4')
            {
                if (way == 0)
                {
                    way = 1;
                }
                else if (way == 1)
                {
                    way = 2;
                }
                else if (way == 2)
                {
                    way = 3;
                }
                else if (way == 3)
                {
                    way = 0;
                }
            }
            else if (c == '5')
            {
                if (way == 0)
                {
                    way = 3;
                }
                else if (way == 1)
                {
                    way = 0;
                }
                else if (way == 2)
                {
                    way = 1;
                }
                else if (way == 3)
                {
                    way = 2;
                }
            }
            cout<<way;
        }
        cout<<endl;
    }

    return 0;
}
