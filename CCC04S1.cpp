#include <bits/stdc++.h>
using namespace std;

int N;

bool isPrePost(string a, string b)
{
	if(a.length() > b.length()) return false;
	return (0 == b.compare(b.length() - a.length(), a.length(), a))
	    || (0 == b.compare(0, a.length(), a));
}

int main()
{
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		string s0, s1, s2;
		cin >> s0 >> s1 >> s2;
		if(isPrePost(s0, s1) || isPrePost(s0, s2) ||
			isPrePost(s1, s0) || isPrePost(s1, s2) ||
			isPrePost(s2, s0) || isPrePost(s2, s1))
			cout << "No\n";
		else
			cout << "Yes\n";
	}
}
