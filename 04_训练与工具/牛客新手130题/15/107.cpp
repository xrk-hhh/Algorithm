// #include<bits/stdc++.h>
// using namespace std;

// struct node{
//     int chinese, math, english, sum;
// };

// bool operator<(node a, node b){
//     // TODO: 实现比较逻辑，按照总分、语文、数学、英语的优先级排序
//     if (a.sum != b.sum)
//     {
//         return a.sum < b.sum;
//     }
//     if (a.chinese != b.chinese)
//     {
//         return a.chinese < b.chinese;
//     }
//     if (a.math != b.math)
//     {
//         return a.math < b.math;
//     }
//     return a.english < b.english;
// }

// priority_queue<node> s;
// void insertValue(int chinese, int math, int english){
//     // TODO: 实现插入操作
//     s.push({chinese, math, english, chinese + math + english});
// }

// void deleteValue(){
//     // TODO: 实现删除操作
//     if (!s.empty())
//     {
//         s.pop();
//     }
// }

// node getTop(){
//     // TODO: 返回成绩最好的学生
//     if (!s.empty())
//     {
//         return s.top();
//     }
//     return {};
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int q,op;
//     int x, y, z;
//     cin>>q;
//     while(q--){
//         cin>>op;
//         if(op==1){
//             cin>>x>>y>>z;
//             insertValue(x, y, z);
//         }
//         if(op==2){
//             node tmp = getTop();
//             cout<<tmp.chinese<<" "<<tmp.math<<" "<<tmp.english<<endl;
//         }
//         if(op==3){
//            deleteValue();
//         }
//     }
//     return 0;
// }