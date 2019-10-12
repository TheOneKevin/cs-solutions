#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ip;
int N, P[1000001];
vector<ip> v;

int main(){
	scanf("%d", &N);
	for(int i = 0, a; i < N; i++)
	{
		scanf("%d", &a);
		int p = -1;
		if(v.empty() || v.back().first < a)
		{
			v.push_back({ a, i });
			if(v.size() <= 1)
				P[i] = -1;
			else
				P[i] = v[v.size() - 2].second;
		}
		else
		{
			p = lower_bound(v.begin(), v.end(), { a, 0 }, [](ip a, ip b)
				{ return a.first < b.first; }) - v.begin();
			v[p] = { a, i };
			if(p - 1 < 0)
				P[i] = -1;
		}
	}
}