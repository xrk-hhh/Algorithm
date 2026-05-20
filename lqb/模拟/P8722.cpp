// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         string s;
//         cin>>s;

//         string m;
//         for (int i = 0; i < 3; i++)
//         {
//             m += s[i];
//         }

//         if (m == "Jan")
//         {
//             cout<<"1"<<' ';
//         }
//         else if (m == "Feb")
//         {
//             cout<<"2"<<' ';
//         }
//         else if (m == "Mar")
//         {
//             cout<<'3'<<' ';
//         }
//         else if (m == "Apr")
//         {
//             cout<<"4"<<' ';
//         }
//         else if (m == "May")
//         {
//             cout<<"5"<<' ';
//         }
//         else if (m == "Jun")
//         {
//             cout<<"6"<<' ';
//         }
//         else if (m == "Jul")
//         {
//             cout<<"7"<<' ';
//         }
//         else if (m == "Aug")
//         {
//             cout<<"8"<<' ';
//         }
//         else if (m == "Sep")
//         {
//             cout<<"9"<<' ';
//         }
//         else if (m == "Oct")
//         {
//             cout<<"10"<<' ';
//         }
//         else if (m == "Nov")
//         {
//             cout<<"11"<<' ';
//         }
//         else if (m == "Dec")
//         {
//             cout<<"12"<<' ';
//         }

//         bool ok = false;
//         for (int i = 3; i < 5; i++)
//         {
//             if (s[i] != '0')
//             {
//                 ok = true;
//             }

//             if (ok)
//             {
//                 cout<<s[i];
//             }
//         }
//     }

//     return 0;
// }