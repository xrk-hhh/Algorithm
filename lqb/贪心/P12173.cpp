// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         string s;
//         cin>>s;

//         int n = s.size();

//         set<string> st = {"lqb", "lbq", "qlb", "qbl", "blq", "bql"};

//         int ans = 0;
//         for (int i = 2; i < n; i++)
//         {
//             string tmp;
//             // 注意：不能直接 tmp += s[i - 2] + s[i - 1] + s[i]
//             // 因为这样会将三个字符的ASCII码相加，得到单个字符，而不是三个字符的字符串。
//             tmp += s[i - 2];
//             tmp += s[i - 1];
//             tmp += s[i];
//             if (st.count(tmp))
//             {
//                 ans++;
//                 i += 2;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }