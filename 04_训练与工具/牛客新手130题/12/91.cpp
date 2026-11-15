// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     stack<int> st;
//     stack<int> minn;
//     void push(int value) {
//         st.push(value);
//         if (minn.empty())
//         {
//             minn.push(value);
//         }
//         else if (minn.top() >= value)
//         {
//             minn.push(value);
//         }
//     }
//     void pop() {
//         if (!minn.empty() && minn.top() == st.top())
//         {
//             minn.pop();
//         }
//         st.pop();
//     }
//     int top() {
//         return st.top();
//     }
//     int min() {
//         return minn.top();
//     }
// };