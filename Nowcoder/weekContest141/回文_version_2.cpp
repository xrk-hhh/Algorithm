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
//         string s;
//         cin>>s;
        
//         int n = s.size();
//         bool ok = true;
//         for (int l = 0, r = n - 1; l < r;)
//         {
//             if (s[l] != s[r])
//             {
//                 if (l + 1 <= r && s[l] == 'n' && s[l + 1] == 'n')
//                 {
//                     l += 2;
//                     r--;
//                 }
//                 else if (l <= r - 1 && s[r] == 'n' && s[r - 1] == 'n')
//                 {
//                     l++;
//                     r -= 2;
//                 }
//                 else
//                 {
//                     ok = false;
//                     break;
//                 }
//             }
//             else
//             {
//                 l++;
//                 r--;
//             }
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