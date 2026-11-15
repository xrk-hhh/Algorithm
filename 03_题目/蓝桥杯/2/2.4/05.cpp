// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MAXN = 1e7;

// vector<bool> is_prime(MAXN + 1, true);
// vector<int> primes;

// void pre()
// {
//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i <= MAXN; i++)
//     {
//         if (is_prime[i])
//         {
//             primes.push_back(i);
//         }
//         for (int p : primes)
//         {
//             if ((ll)(i * p) > MAXN)
//             {
//                 break;
//             }
//             is_prime[i * p] = false;
//             if (i % p == 0)
//             {
//                 break;
//             }
//         }
//     }
// }

// void dfs(int idx, const vector<int>& stars, string& cur, int& ans)
// {
//     if (idx == stars.size())
//     {
//         int num = stoi(cur);
//         if (is_prime[num])
//         {
//             if (ans == -1 || num < ans)
//             {
//                 ans = num;
//             }
//         }
//         return;
//     }
//     int pos = stars[idx];
//     for (char c = '0'; c <= '9'; c++)
//     {
//         cur[pos] = c;
//         dfs(idx + 1, stars, cur, ans);
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     pre();

//     while (T--)
//     {
//         string s;
//         cin>>s;

//         vector<int> stars;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '*')
//             {
//                 stars.push_back(i);
//             }
//         }

//         int ans = -1;
//         if (stars.empty())
//         {
//             int num = stoi(s);
//             if (is_prime[num])
//             {
//                 ans = num;
//             }
//         }
//         else
//         {
//             dfs(0, stars, s, ans);
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }