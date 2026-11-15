// #include <bits/stdc++.h>
// using namespace std;

// int p[110];

// int main()
// {
//     int n, k, m;
//     cin>>n>>k>>m;

//     int cnt = n;
//     int idx = k;

//     while (cnt > 1)
//     {
//         int step = 0;
//         while (step < m)
//         {
//             if (p[idx % n] == 0)
//             {
//                 step++;
//             }
//             if (step == m)
//             {
//                 p[idx % n] = 1;
//                 cnt--;
//             }
//             idx++;
//         }
//     }

//     for (int i = 1; i < n; i++)
//     {
//         if (p[i] == 0)
//         {
//             cout<<i;
//             break;
//         }
//     }

//     return 0;
// }