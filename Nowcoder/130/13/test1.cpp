// #include <iostream>
// #include <map>

// using namespace std;

// int main() 
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);


//     // ios::sync_with_stdio(false);
//     // cin.tie(nullptr;)

//     int n, m;
//     long long k;
//     cin >> n >> m >> k;

//     map<long long, long long> cnt;

//     // 读取棋盘，统计初始数字
//     for (int i = 0; i < n; i++) 
//     {
//         for (int j = 0; j < m; j++) 
//         {
//             long long x;
//             cin >> x;
//             if (x != 0) 
//             {
//                 cnt[x]++;
//             }
//         }
//     }

//     long long merge_times = 0;
//     long long coins = 0;

//     // 按数字从小到大合并
//     for (auto it = cnt.begin(); it != cnt.end();) 
//     {
//         long long x = it->first;
//         long long count = it->second;

//         long long merge = count / 2;
//         if (merge == 0) 
//         {
//             it++;
//             continue;
//         }

//         merge_times += merge;
//         if (x + 1 >= k) 
//         {
//             coins += merge;
//         }

//         cnt[x + 1] += merge;
//         it = cnt.erase(it);
//     }

//     cout << merge_times << " " << coins << endl;

//     return 0;
// }