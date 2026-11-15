// #include <bits/stdc++.h>
// using namespace std;

// #define end \'n'
// #define ll long long

// void mul(vector<int>& A, vector<int>&B, vector<int>& C)
// {
//     for (int i = 0; i < A.size(); i++)
//     {
//         for (int j = 0; j < B.size(); j++)
//         {
//             C[i + j] += A[i] * B[j];
//             C[i + j + 1] += C[i + j] / 10;
//             C[i + j] %= 10;
//         }
//     }

//     while ((C.size() > 1) && (!C.back()))
//     {
//         C.pop_back();
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         string a, b;
//         cin>>a>>b;

//         vector<int> A, B;
//         for (int i = a.size() - 1; i >= 0; i--)
//         {
//             A.push_back(a[i] - '0');
//         }
//         for (int i = b.size() - 1; i >= 0; i--)
//         {
//             B.push_back(b[i] - '0');
//         }

//         vector<int> C(A.size() + B.size());
//         mul(A, B, C);

//         for (int i = C.size() - 1; i >= 0; i--)
//         {
//             cout<<C[i];
//         }

//         cout<<endl;
//     }

//     return 0;
// }