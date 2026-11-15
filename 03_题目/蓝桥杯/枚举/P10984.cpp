// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// string s[] = 
// {
//     "1111110",
//     "0110000",
//     "1101101",
//     "1111001",
//     "0110011",
//     "1011011",
//     "1011111",
//     "1110000",
//     "1111111",
//     "1111011"
// };

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         string ss[] = 
//         {
//             "0000011", "1001011", "0000001", "0100001", "0101011", "0110110", "1111111", "0010110", "0101001", "0010110", "1011100", "0100110", "1010000", "0010011", "0001111", "0101101", "0110101", "1101010"
//         };

//         int ans = 1;
//         for (int i = 0; i < 18; i++)
//         {
//             int cnt = 0;
//             for (int j = 0; j < 10; j++)
//             {
//                 bool ok = true;
//                 for (int k = 0; k < 7; k++)
//                 {
//                     if (ss[i][k] == '1' && s[j][k] == '0')
//                     {
//                         ok = false;
//                         break;
//                     }
//                 }
//                 if (ok)
//                 {
//                     cnt++;
//                 }
//             }
//             ans *= cnt;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }