// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int T;
//     cin>>T;

//     while(T--)
//     {
//         string s;
//         cin>>s;

//         stack<char> st;
//         int len = s.size();

//         for (int i = 0; i < len; i++)
//         {
//             char ch = s[i];

//             if (st.empty())
//             {
//                 st.push(ch);
//                 continue;
//             }
//             char top = st.top();

//             bool flag = false;

//             while (ch == top)
//             {
//                 if (ch =='o')
//                 {
//                     st.pop();
//                     ch ='O';
//                 }
//                 else
//                 {
//                     st.pop();
//                     flag = true;
//                     break;
//                 }
//                 if (st.empty())
//                 {
//                     break;
//                 }
//                 top = st.top();
//             }

//             if (!flag)
//             {
//                 st.push(ch);
//             }
//         }

//         stack<char> tmp;
//         while (!st.empty())
//         {
//             tmp.push(st.top());
//             st.pop();
//         }
//         while (!tmp.empty())
//         {
//             cout<<tmp.top();
//             tmp.pop();
//         }
//         cout<<endl;
//     }

//     return 0;
// }