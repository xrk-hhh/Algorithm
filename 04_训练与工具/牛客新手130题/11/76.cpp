// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int q;
//     cin>>q;

//     vector<int> v;

//     while (q--)
//     {
//         int op;
//         cin>>op;

//         int x;
//         switch(op)
//         {
//             case 1:
//                 cin>>x;
//                 v.push_back(x);
//                 break;
//             case 2:
//                 v.pop_back();
//                 break;
//             case 3:
//                 int i;
//                 cin>>i;
//                 cout<<v[i]<<endl;
//                 break;
//             case 4:
//                 int pos;
//                 cin>>pos>>x;
//                 // v.push_back(0);
//                 // for (int i = v.size() - 1; i > pos; i--)
//                 // {
//                 //     v[i] = v[i - 1];
//                 // }
//                 // v[pos + 1] = x;
//                 v.insert(v.begin() + pos + 1, x);
//                 break;
//             case 5:
//                 sort(v.begin(), v.end());
//                 break;
//             case 6:
//                 // sort(v.begin(), v.end());
//                 // reverse(v.begin(), v.end());
//                 sort(v.begin(), v.end(), greater<int>());
//                 break;
//             case 7:
//                 cout<<v.size()<<endl;
//                 break;
//             case 8:
//                 for (int i = 0; i < v.size(); i++)
//                 {
//                     cout<<v[i]<<' ';
//                 }
//                 cout<<endl;
//                 break;
//         }
//     }

//     return 0;
// }