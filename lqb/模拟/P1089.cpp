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
//         vector<int> budget(12);
//         for (int i = 0; i < 12; i++)
//         {
//             cin>>budget[i];
//         }

//         int cur = 0;
//         int store = 0;
//         for (int i = 0; i < 12; i++)
//         {
//             cur += 300;
//             if (cur - budget[i] < 0)
//             {
//                 cout<<-(i + 1)<<endl;
//                 return 0;
//             }

//             if (cur - budget[i] >= 100)
//             {
//                 store += ((cur - budget[i]) / 100) * 100;
//                 cur = (cur - budget[i]) % 100;
//             }
//             else
//             {
//                 cur -= budget[i];
//             }
//         }

//         cout<<cur + store * 1.2<<endl;
//     }

//     return 0;
// }