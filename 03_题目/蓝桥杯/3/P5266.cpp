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
//         int Q;
//         cin>>Q;

//         unordered_map<string, int> stu;

//         while (Q--)
//         {
//             int op;
//             cin>>op;

//             if (op == 1)
//             {
//                 string name;
//                 int score;
//                 cin>>name>>score;

//                 stu[name] = score;
//                 cout<<"OK"<<endl;
//             }
//             else if (op == 2)
//             {
//                 string name;
//                 cin>>name;

//                 auto it = stu.find(name);
//                 if (it != stu.end())
//                 {
//                     cout<<it->second<<endl;
//                 }
//                 else
//                 {
//                     cout<<"Not found"<<endl;
//                 }
//             }
//             else if (op == 3)
//             {
//                 string name;
//                 cin>>name;

//                 auto it = stu.find(name);
//                 if (it != stu.end())
//                 {
//                     stu.erase(it);
//                     cout<<"Deleted successfully"<<endl;
//                 }
//                 else
//                 {
//                     cout<<"Not found"<<endl;
//                 }
//             }
//             else if (op == 4)
//             {
//                 cout<<stu.size()<<endl;;
//             }
//         }
//     }

//     return 0;
// }