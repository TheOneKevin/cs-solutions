#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define MOD 1000000007
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> ip;

int N, A, C, da[400005], dc[400005];
vector<int> p;
vector<ip> sa, sc;
map<int, int> mp;

int main()
{
	scanf("%d %d %d",&N,&A,&C);
	for(int i = 0, a, c; i < A; i++)
	{
		scanf("%d%d",&a,&c);
		sa.push_back({a,c+1});
		p.push_back(a); p.push_back(c+1);
	}
	for(int i = 0, a, c; i < C; i++)
	{
		scanf("%d%d",&a,&c);
		sc.push_back({a,c+1});
		p.push_back(a); p.push_back(c+1);
	}
	// Compress
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	for(int i = 0; i < p.size(); i++) mp[p[i]] = i;
	for(int i = 0; i < sa.size(); i++) sa[i] = { mp[sa[i].ff], mp[sa[i].ss] };
	for(int i = 0; i < sc.size(); i++) sc[i] = { mp[sc[i].ff], mp[sc[i].ss] };
	// Difference
	for(int i = 0; i < sa.size(); i++)
	{
		da[sa[i].ff]++; da[sa[i].ss]--;
	}
	for(int i = 0; i < p.size(); i++)
	{
		if(i > 0) da[i] += da[i-1];
	}
	for(int i = 0; i < sc.size(); i++)
	{
		dc[sc[i].ff]++; dc[sc[i].ss]--;
	}
	for(int i = 0; i < p.size(); i++)
	{
		if(i > 0) dc[i] += dc[i-1];
	}
	ll res = 0;
	for(int i = 0; i < p.size(); i++)
	{
		//printf("%d %d\n", da[i], dc[i]);
		if(da[i] > 0 && dc[i] == 0)
			res+=p[i+1]-p[i];
	}
	printf("%lld\n", res);
}
