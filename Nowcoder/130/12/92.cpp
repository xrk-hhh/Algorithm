// #include <bits/stdc++.h>
// using namespace std;

// bool check(int n, const vector<int> &pushed, const vector<int> &poped)
// {
//     stack<int> st;
//     int k = 0;
//     for (int i = 0; i < n; i++)
//     {
//         st.push(pushed[i]);
//         while (!st.empty() && st.top() == poped[k])
//         {
//             st.pop();
//             k++;
//         }
//     }
//     return st.empty();
// }

// int main()
// {
//     int q;
//     cin>>q;

//     while (q--)
//     {
//         int n;
//         cin>>n;

//         vector<int> pushed(n), popped(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>pushed[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin>>popped[i];
//         }

//         if (check(n, pushed, popped))
//         {
//             cout<<"Yes"<<endl;
//         }
//         else
//         {
//             cout<<"No"<<endl;
//         }
//     }

//     return 0;
// }