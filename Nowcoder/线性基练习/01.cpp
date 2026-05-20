// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MAXN = 30;

// void insert(int x, vector<int>& basis)
// {
//     for (int i = MAXN; i >= 0; i--)
//     {
//         if ((x >> i) & 1)
//         {
//             if (basis[i] == 0)
//             {
//                 basis[i] = x;
//                 break;
//             }
//             else
//             {
//                 x ^= basis[i];
//             }
//         }
//     }
// }

// bool is_in_span(int x, const vector<int>& basis)
// {
//     for (int i = MAXN; i >=0; i--)
//     {
//         if ((x >> i) & 1)
//         {
//             if (basis[i] == 0)
//             {
//                 return false;
//             }
//             x ^= basis[i];
//         }
//     }
//     return x == 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
// //     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;
        
//         vector<int> basis(MAXN + 1, 0);
//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin>>a;
//             insert(a, basis);
//         }
        
//         int q;
//         cin>>q;
        
//         while (q--)
//         {
//             int x, y;
//             cin>>x>>y;
            
//             int t = x ^ y;
//             if (is_in_span(t, basis))
//             {
//                 cout<<"YES"<<endl;
//             }
//             else
//             {
//                 cout<<"NO"<<endl;
//             }
//         }
//     }

//     return 0;
// }