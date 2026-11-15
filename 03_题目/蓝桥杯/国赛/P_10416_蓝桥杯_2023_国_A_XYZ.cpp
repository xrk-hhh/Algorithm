// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int l, r;
//         cin>>l>>r;

//         // 显然的数学公式
//         // l, l+1, ..., r
//         // 不妨设 X<=Y<=Z，令 t = r-l
//         // 则有 l <= X <= Y <= t <= Z <= r
//         // 显然，若 t 不在[l,r]内时，无解
//         // 若 t属于[l,r]，则可取
//         // X 可取 l, l+1, ..., Y
//         // 也就是说 X 的取值有 Y-l+1种
//         // 而 Y 可取 l, l+1, ..., t
//         // 那么，答案显然就是 (l-l+1)+(l+1-l+1)+(l+2-l+1)+...(t-l+1)
//         // 即 1+2+3+...+t-l+1
//         // 显然的等差数列求和，则 ans = (t-l+1 + 1) * (t-l+1) / 2
        

//         ll t = r - l;
//         ll ans = 0;
//         if (t >= l && t <= r)
//         {
//             ll m = t - l + 1;
//             ans += m * (m + 1) >> 1;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }