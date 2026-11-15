// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const vector<string> tiangan = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "kui"};
// const int mod1 = 10;
// const vector<string> dizhi = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};
// const int mod2 = 12;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         string ans;
//         int idx1 = 6, idx2 = 0;

//         int dif = n - 2020;
//         // n∈[1, 9999], 为保证下标不为负数，则 + mod * 10000
//         idx1 = (idx1 + dif + mod1 * 10000) % mod1;
//         idx2 = (idx2 + dif + mod2 * 10000) % mod2;

//         cout<<tiangan[idx1]<<dizhi[idx2]<<endl;
//     }

//     return 0;
// }