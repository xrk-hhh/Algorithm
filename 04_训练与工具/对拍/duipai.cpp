#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	system("g++ -std=c++11 generator.cpp -o generator.exe");
	system("g++ -std=c++11 brute.cpp -o brute.exe");
	system("g++ -std=c++11 std.cpp -o std.exe");
	
	while (1)
	{
		system("generator.exe > data.txt");
		system("brute.exe < data.txt > brute.txt");
		system("std.exe < data.txt > std.txt");
		
		if (system("fc std.txt brute.txt"))
		{
			cout<<"WA！！！"<<endl;
			
			system("type data.txt");
			system("type brute.txt");
			system("type std.txt");
			break;
		}
		else
		{
			cout<<"AC！！！"<<endl;
		}
	}
	
	
	return 0;
}
