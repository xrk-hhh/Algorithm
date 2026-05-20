// #include <bits/stdc++.h>
// using namespace std;

// int cnt[1010];

// int main() 
// {
//     int M, N;
//     cin>>M>>N;

//     int ans = 0;

//     queue<int> q;

//     while (N--)
//     {
//         int w;
//         cin>>w;
        
//         if (q.size() > M)
//         {
//             cnt[q.front()]--;
//             q.pop();
//         }
//         if (cnt[w] == 0)
//         {
//             q.push(w);
//             cnt[w]++;
//             ans++;
//         }
//     }

//     cout<<ans;

//     return 0;
// }