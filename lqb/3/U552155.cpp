// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         // 关于前缀和相关的式子，先考虑能不能化简式子
//         // pre：表示数组 a 前缀和 
//         // sum(i * bi) ( 1 <= i <= k)   					=>
//         // sum(i * (pre[i] - pre[i - 1])) ( 1 <= i <= k) 	=>
//         // 展开前缀和每一项
//         // 1 * pre[1] - 1 * pre[0] +
//         // 2 * pre[2] - 2 * pre[1] +
//         // 3 * pre[3] - 3 * pre[2] + 
//         // ......
//         // k * pre[n] - k * pre[n - 1]  => 	
        
//         // 最终得到： k * pre[n] - sum(pre[i]) (1 <= i <= k - 1) 
//         // 最小化 sum(pre[i]) (1 <= i <= k - 1) 
        
//         // 即：f: 表示pre的前缀和
//         // ans = k * pre[n] - f[k - 1] 

//         int n;
//         cin>>n;

//         vector<int> a(n);
//         ll total = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             total += a[i];
//         }

//         if (n == 1)
//         {
//             cout<<total<<endl;
//             continue;
//         }

//         vector<ll> pre;
//         ll cur = 0;
//         for (int i = 0; i < n - 1; i++)
//         {
//             cur += a[i];
//             pre.push_back(cur);
//         }

//         sort(pre.begin(), pre.end());

//         vector<ll> minsum(pre.size() + 1, 0);
//         for (int i = 0; i < pre.size(); i++)
//         {
//             minsum[i + 1] = minsum[i] + pre[i];
//         }

//         for (int k = 1; k <= n; k++)
//         {
//             ll ans = k * total;

//             if (k > 1)
//             {
//                 ans -= minsum[k - 1];
//             }

//             cout<<ans<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }