// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// vector<int> mul(const vector<int>& a, int x)
// {
//     vector<int> res;
//     int carry = 0;

//     for (int digit : a)
//     {
//         carry += digit * x;
//         res.push_back(carry % 10);
//         carry /= 10;
//     }

//     while (carry)
//     {
//         res.push_back(carry % 10);
//         carry /= 10;
//     }

//     return res;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<int> nums;
//         int sum = 0;
//         int i = 2;
//         while (sum < n)
//         {
//             nums.push_back(i);
//             sum += i;
//             i++;
//         }

//         if (sum > n)
//         {
//             int d = sum - n;
//             if (d == 1)
//             {
//                 nums.erase(nums.begin());
//                 nums.back()++;
//             }
//             else
//             {
//                 auto it = find(nums.begin(), nums.end(), d);
//                 if (it != nums.end())
//                 {
//                     nums.erase(it);
//                 }
//             }
//         }

//         for (size_t i = 0; i < nums.size(); i++)
//         {
//             if (i)
//             {
//                 cout<<' ';
//             }
//             cout<<nums[i];
//         }
//         cout<<endl;

//         vector<int> prod = {1};
//         for (int x : nums)
//         {
//             prod = mul(prod, x);
//         }

//         for (int i = prod.size() - 1; i >= 0; i--)
//         {
//             cout<<prod[i];
//         }
//         cout<<endl;
//     }

//     return 0;
// }