// #include<bits/stdc++.h>
// using namespace std;

// multiset<int> s;

// void insertValue(int x){
//     //TODO 实现插入逻辑
//     s.insert(x);
// }
// void eraseValue(int x){
//     //TODO 实现删除逻辑
//     if (s.count(x))
//     {
//         s.erase(s.find(x));
//     }
// }
// int xCount(int x){
//     //TODO 求x在集合中的个数
//     return s.count(x);
// }
// int sizeOfSet(){
//     //TODO 返回集合大小
//     return s.size();
// }
// int getPre(int x){
//     //TODO 实现找前驱
//     auto it = s.lower_bound(x);
//     if (it == s.begin())
//     {
//         return -1;
//     }
//     else 
//     {
//         it--;
//         return *it;
//     }
// }
// int getBack(int x){
//     //TODO 实现找后继
//     auto it = s.upper_bound(x);
//     if (it == s.end())
//     {
//         return -1;
//     }
//     else
//     {
//         return *it;
//     }
// }

// int main(){
//     int q,op,x;
//     cin>>q;
//     while(q--){
//         cin>>op;
//         if(op==1){
//             cin>>x;
//             insertValue(x);
//         }
//         if(op==2){
//             cin>>x;
//             eraseValue(x);
//         }
//         if(op==3){
//             cin>>x;
//             cout<<xCount(x)<<endl;
//         }
//         if(op==4){
//             cout<<sizeOfSet()<<endl;
//         }
//         if(op==5){
//             cin>>x;
//             cout<<getPre(x)<<endl;
//         }
//         if(op==6){
//             cin>>x;
//             cout<<getBack(x)<<endl;
//         }
//     }
//     return 0;
// }