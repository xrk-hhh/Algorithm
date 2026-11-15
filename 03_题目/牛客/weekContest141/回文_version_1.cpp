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

//         int t = sqrt(n);
//         if (t * t != n)
//         {
//             cout<<"NO"<<endl;
//             return 0;
//         }

//         string s1 = to_string(t);
//         int m1 = s1.size();
//         bool ok = true;
//         for (int i = 0; i < m1 / 2; i++)
//         {
//             if (s1[i] != s1[m1 - 1 - i])
//             {
//                 ok = false;
//                 break;
//             }
//         }
//         if (ok)
//         {
//             string s2 = to_string(n);
//             int m2 = s2.size();
//             for (int i = 0; i < m2 / 2; i++)
//             {
//                 if (s2[i] != s2[m2 - 1 - i])
//                 {
//                     ok = false;
//                     break;
//                 }
//             }
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//             return 0;
//         }
        

//         if (ok)
//         {
//             cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//     }

//     return 0;
// }