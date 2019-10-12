#include <bits/stdc++.h>
using namespace std;

int N;
unordered_set<string> s;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		int* f = new int[6];
		for(int j = 0; j < 6; j++) scanf("%d", &f[j]);
		sort(f, f + 6);
		string ss;
		for(int j = 0; j < 6; j++) ss += to_string(f[j]);
		s.insert(ss);
	}
	
	printf((s.size() == N) ? "No two snowflakes are alike." : "Twin snowflakes found.");
}
