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

//         string state;
//         cin>>state;

//         vector<int> s(n);
//         for (int i = 0; i < n; i++)
//         {
//             s[i] = state[i] - '0';
//         }

//         vector<int> x(n), y(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>x[i]>>y[i];
//         }

//         vector<int> t(n);
//         for (int i = 0; i < n; i++)
//         {
//             t[i] = s[i] ^ 1;
//         }

//         vector<bitset<101>> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (x[i] == x[j] || y[i] == y[j])
//                 {
//                     a[i].set(j);
//                 }
//             }
//             if (t[i])
//             {
//                 a[i].set(n);
//             }
//         }

//         vector<int> where(n, -1);
//         int row = 0;
//         for (int col = 0; col < n; col++)
//         {
//             int sel = -1;
//             for (int i = row; i < n; i++)
//             {
//                 if (a[i][col])
//                 {
//                     sel = i;
//                     break;
//                 }
//             }
//             if (sel == -1)
//             {
//                 continue;
//             }

//             swap(a[row], a[sel]);
//             where[row] = col;

//             for (int i = row + 1; i < n; i++)
//             {
//                 if (a[i][col])
//                 {
//                     a[i] ^= a[row];
//                 }
//             }
//             row++;
//         }

//         for (int i = row; i < n; i++)
//         {
//             if (a[i][n])
//             {
//                 cout<<-1<<endl;
//                 return 0;
//             }
//         }

//         vector<int> x_sol(n, 0);
//         for (int i = row - 1; i >= 0; i--)
//         {
//             int col = where[i];
//             int sum = a[i][n];
//             for (int j = col + 1; j < n; j++)
//             {
//                 if (a[i][j])
//                 {
//                     sum ^= x_sol[j];
//                 }
//             }
//             x_sol[col] = sum;
//         }

//         vector<int> ops;
//         for (int i = 0; i < n; i++)
//         {
//             if (x_sol[i])
//             {
//                 ops.push_back(i + 1);
//             }
//         }

//         cout<<ops.size()<<endl;

//         if (!ops.empty())
//         {
//             for (int i = 0; i < ops.size(); i++)
//             {
//                 cout<<ops[i]<<' ';
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }