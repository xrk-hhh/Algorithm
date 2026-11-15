// 原始稿：04_训练与工具/训练赛/laoda2/g.cpp
// 原文行号：1-90；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int T = 1;
   cin>>T;

   while (T--)
   {
       int n, k;
       cin>>n>>k;
       
       string s;
       cin>>s;
       
       vector<int> dp(n + 1, 1e9);
       dp[0] = 0;
       // 最大的下标 x 满足 x ≤ i 且 s[x-1] == s[x-2]（即存在相邻相同对）
       vector<int> pr(n + 1, 0);
       for (int i = 2; i <= n; i++)
       {
			if (s[i - 1] == s[i - 2])
			{
				pr[i] = i;
			}
			else
			{
				pr[i] = pr[i - 1];
			}
		}
		
		// 由于我们需要在区间 [l, r] 内取最小的 dp[j]，且 l 和 r 都随 i 单调不减，
		// 因此可以用单调队列（滑动窗口最小值）维护。
		// 每次将新下标 j 加入队列时，保证队列中 dp 值单调递增。
		// 这样队首就是最小值。
		deque<int> dq;
		// p 记录已经加入队列的最大下标，初始为 -1。
		// 每次循环中，如果 p < r，则继续加入下标直到 p == r。
		int p = -1;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = dp[i - 1] + 1;
			
			// 对于以 i 结尾的子串，如果它要包含至少一个相邻相同对，
			// 其左端点 l 必须满足 l ≤ pr[i]-1（因为这对相同字符位于 [pr[i]-1, pr[i]]）。
			// 因此，合法子串的左端点范围是 [max(1, i-K+1), pr[i]-1]。
			// 转换为分割点 j = l-1，则 j ∈ [max(0, i-K), pr[i]-2]。
			// 这就是 r = pr[i]-2 的由来。
			
			int l = max(0, i - k);
			int r = pr[i] - 2;
			if (l <= r)
			{
				while (p < r)
				{
					p++;
					// 单调队列维护滑动窗口最小值
					while (!dq.empty() && dp[dq.back()] >= dp[p])
					{
						dq.pop_back();
					}
					
					dq.push_back(p);
				}
				
				// 删除队首小于 l 的元素。
				while (!dq.empty() && dq.front() < l)
				{
					dq.pop_front();
				}
				
				if (!dq.empty())
				{
					dp[i] = min(dp[i], dp[dq.front()] + 1);
				}
			}
		}
		
		cout<<dp[n] - 1<<endl;
   }

   return 0;
}
