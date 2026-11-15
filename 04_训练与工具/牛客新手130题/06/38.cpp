// #include <bits/stdc++.h>
// using namespace std;

// int ans[100010];

// int main()
// {
//     int n;
//     cin>>n;

//     int k = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (i % 4 == 0)
//         {
//             continue;
//         }
//         int a;
//         a = i;
//         bool is_ans = true;
//         while (a != 0)
//         {
//             int tmp = a % 10;
//             if (tmp == 4)
//             {
//                 is_ans = false;
//                 break;
//             }
//             a /= 10;
//         }
//         if (is_ans)
//         {
//             ans[k++] = i;
//         }
//     }

//     for (int i = 0; i < k; i++)
//     {
//         cout<<ans[i]<<endl;
//     }

//     return 0;
// }