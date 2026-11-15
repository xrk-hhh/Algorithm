// #include <bits/stdc++.h>
// using namespace std;

// bool check(string s)
// {
//     int len = s.size();
//     stack<char> st;

//     for (int i = 0; i < len; i++)
//     {
//         if (s[i] == '(' || s[i] == '[')
//         {
//             st.push(s[i]);
//         }
//         else if (s[i] == ')')
//         {
//             if (st.empty() || st.top() != '(')
//             {
//                 return false;
//             }
//             st.pop();
//         }
//         else if (s[i] == ']')
//         {
//             if (st.empty() || st.top() != '[')
//             {
//                 return false;
//             }
//             st.pop();
//         }
//     }
//     return st.empty();
// }

// int main()
// {
//     string s;
//     cin>>s;

//     stack<char> st;

//     if(check(s))
//     {
//         cout<<"true"<<endl;
//     }
//     else
//     {
//         cout<<"false"<<endl;
//     }

//     return 0;
// }