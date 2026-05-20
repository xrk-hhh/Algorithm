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
//         // vector<int> l = {1189, 841, 594, 420, 297, 210, 148, 105, 74, 52};
//         // vector<int> w = {841, 594, 420, 297, 210, 148, 105, 74, 52, 37};
//         vector<int> l(10), w(10);
//         l[0] = 1189;
//         w[0] = 841;
//         for (int i = 1; i < 10; i++)
//         {
//             l[i] = w[i - 1];
//             w[i] = l[i - 1] >> 1;
//         }

//         // for (int i = 0; i < 10; i++)
//         // {
//         //     cout<<l[i]<<' ';
//         // }
//         // cout<<endl;
//         // for (int i = 0; i < 10; i++)
//         // {
//         //     cout<<w[i]<<' ';
//         // }
//         // cout<<endl;
        

//         string s;
//         cin>>s;

//         int n = s[1] - '0';

//         cout<<l[n]<<endl<<w[n]<<endl;
//     }

//     return 0;
// }