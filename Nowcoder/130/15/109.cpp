// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'

// int main() 
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     multiset<int> ms;

//     int n;
//     cin>>n;

//     while (n--)
//     {
//         int op;
//         cin>>op;

//         if (op == 1)
//         {
//             int x;
//             cin>>x;
//             ms.insert(x);
//         }
//         else if (op == 2)
//         {
//             cout<<*ms.begin()<<endl;
//         }
//         else if (op == 3)
//         {
//             cout<<*--ms.end()<<endl;
//         }
//         else if (op == 4)
//         {
//             ms.erase(ms.find(*ms.begin()));
//         }
//         else
//         {
//             ms.erase(ms.find(*--ms.end()));
//         }
//     }

//     return 0;
// }