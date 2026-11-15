// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

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

//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin>>x;

//             pq.push(x);
//         }

//         int ans = 0;
//         while (pq.size() > 1)
//         {
//             int t1 = pq.top();
//             pq.pop();

//             int t2 = pq.top();
//             pq.pop();

//             int t = t1 + t2;
//             ans += t;

//             pq.push(t);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }