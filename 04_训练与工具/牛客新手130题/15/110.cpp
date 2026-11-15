// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'

// // int main() 
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int n, m;
// //     cin>>n>>m;

// //     multiset<int> a;

// //     while (n--)
// //     {
// //         int x;
// //         cin>>x;
// //         a.insert(x);
// //     }
// //     while (m--)
// //     {
// //         int b;
// //         cin>>b;
// //         int x = *a.begin();
// //         a.erase(a.find(x));
// //         a.insert(x + b);
// //         cout<<*--a.end()<<endl;
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'

// int main() 
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin>>n>>m;

//     priority_queue<int, vector<int>, greater<int> > pq;
//     int maxx = 0;

//     while (n--)
//     {
//         int x;
//         cin>>x;
//         pq.push(x);
//         maxx = max(maxx, x);
//     }
//     while (m--)
//     {
//         int b;
//         cin>>b;
        
//         int minn = pq.top();
//         pq.pop();
//         minn += b;
//         pq.push(minn);

//         maxx = max(maxx, minn);

//         cout<<maxx<<endl;
//     }

//     return 0;
// }