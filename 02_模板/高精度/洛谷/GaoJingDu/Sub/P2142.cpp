// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// bool cmp(const string& a, const string& b)
// {
//     if (a.size() != b.size())
//     {
//         return a.size() > b.size();
//     }

//     return a >= b;
// }

// void sub(vector<int>& A, vector<int>& B, vector<int>& C)
// {
//     int t = 0;
//     for (int i = 0; i < A.size(); i++)
//     {
//         t = A[i];

//         if (i < B.size())
//         {
//             t -= B[i];
//         }

//         if (t < 0)
//         {
//             A[i + 1]--;
//             t += 10;
//         }

//         C.push_back(t);
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

//         if (!cmp(a, b))
//         {
//             swap(a, b);
//             cout<<"-";
//         }

//         vector<int> A, B, C;
//         for (int i = a.size() - 1; i >= 0; i--)
//         {
//             A.push_back(a[i] - '0');
//         }
//         for (int i = b.size() - 1; i >= 0; i--)
//         {
//             B.push_back(b[i] - '0');
//         }

//         sub(A, B, C);

//         for (int i = C.size() - 1; i >= 0; i--)
//         {
//             cout<<C[i];
//         }

//         cout<<endl;
//     }

//     return 0;
// }