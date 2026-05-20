// #include <bits/stdc++.h>
// using namespace std;

// int len[10];

// int main()
// {
//     int T;
//     cin>>T;

//     while (T--)
//     {
//         int maxx = 0, minn = 601;
//         int maxx_cnt = 0, minn_cnt = 0;
//         for (int i = 0; i < 4; i++)
//         {
//             string s;
//             cin>>s;
//             len[i] = s.size();
//             if (len[i] > maxx)
//             {
//                 maxx = len[i];
//                 maxx_cnt = 1;
//             }
//             else if (len[i] == maxx)
//             {
//                 maxx_cnt++;
//             }
            
//             if (len[i] < minn)
//             {
//                 minn = len[i];
//                 minn_cnt = 1;
//             }
//             else if (len[i] == minn)
//             {
//                 minn_cnt++;
//             }
//         }

//         char op;
//         if (maxx_cnt == 1 && minn_cnt != 1)
//         {
//             for (int i = 0; i < 4; i++)
//             {
//                 if (len[i] == maxx)
//                 {
//                     op = i + 'A';
//                     cout<<op<<endl;
//                     break;
//                 }
//             }
//         }
//         else if (maxx_cnt != 1 && minn_cnt == 1)
//         {
//             for (int i = 0; i < 4; i++)
//             {
//                 if (len[i] == minn)
//                 {
//                     op = i + 'A';
//                     cout<<op<<endl;
//                     break;
//                 }
//             }
//         }
//         else
//         {
//             op = 'C';
//             cout<<op<<endl;
//         }
//     }

//     return 0;
// }