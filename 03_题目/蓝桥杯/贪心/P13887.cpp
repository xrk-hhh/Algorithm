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
//         int n;
//         cin>>n;

//         vector<int> a(n), b(n), c(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin>>b[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin>>c[i];
//         }

//         // 各组与另外两组的差值
//         vector<ll> aa(n), bb(n), cc(n);
//         for (int i = 0; i < n; i++)
//         {
//             aa[i] = a[i] - b[i] - c[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             bb[i] = b[i] - a[i] - c[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cc[i] = c[i] - a[i] - b[i];
//         }

//         // 按从大到小排序
//         sort(aa.begin(), aa.end(), greater<ll>());
//         sort(bb.begin(), bb.end(), greater<ll>());
//         sort(cc.begin(), cc.end(), greater<ll>());

//         // 看看每一组使差值之和大于0的有多少项
//         int ans = 0;
//         int cnt1 = 0;
//         ll maxx1 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             maxx1 += aa[i];
//             if (maxx1 <= 0)
//             {
//                 break;
//             }
//             cnt1++;
//         }
//         ans = max(ans, cnt1);
        
//         int cnt2 = 0;
//         ll maxx2 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             maxx2 += bb[i];
//             if (maxx2 <= 0)
//             {
//                 break;
//             }
//             cnt2++;
//         }
//         ans = max(ans, cnt2);
        
//         int cnt3 = 0;
//         ll maxx3 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             maxx3 += cc[i];
//             if (maxx3 <= 0)
//             {
//                 break;
//             }
//             cnt3++;
//         }
//         ans = max(ans, cnt3);

//         if (ans == 0)
//         {
//             cout<<-1<<endl;
//         }
//         else
//         {
//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }