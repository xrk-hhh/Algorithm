// 原始稿：04_训练与工具/训练赛/laoda2/c.cpp
// 原文行号：1-69；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

struct Node
{
	string s;
	vector<int> cnt;
	// 构造函数：初始化列表 
	Node(const string& str) : s(str), cnt(26, 0)
	{
		for (int i = 0; i < s.size(); i++)
		{
			cnt[s[i] - 'a']++;
		}
	}
};

bool cmp(const Node& a, const Node& b)
{
	for (int i = 0; i < 26; i++)
	{
		if (a.cnt[i] != b.cnt[i])
		{
			return a.cnt[i] > b.cnt[i];
		}
	}
	
	return a.s < b.s;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int T = 1;
   // cin>>T;

   while (T--)
   {
       int n;
       cin>>n;
       
       vector<Node> nodes;
       // 提前分配内存 
       nodes.reserve(n);
       for (int i = 0; i < n; i++)
       {
       	string s;
       	cin>>s;
       	
       	// 仍需emplace_back 
       	nodes.emplace_back(s);
		}
		
		sort(nodes.begin(), nodes.end(), cmp);
		
		for (int i = 0; i < n; i++)
		{
			cout<<nodes[i].s<<" ";
		}
		cout<<endl;
   }

   return 0;
}
