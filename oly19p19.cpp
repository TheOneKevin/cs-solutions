#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, K, c, mx = -1;
unordered_map<int, vector<int>> mp;

int main()
{
	scanf("%d %d", &N, &K);
	mp[0].push_back(0);
	for(int i = 1, a; i <= N; i++)
	{
		scanf("%d", &a);
		c = (c + a) % K;
		if(mp[c].size() != 0)
			mx = max(mx, i - mp[c].front());
		mp[c].push_back(i);
	}
	printf("%d", mx);
}