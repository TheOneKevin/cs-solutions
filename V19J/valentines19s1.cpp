#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(int)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define sc(x) {do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
#define ff first
#define ss second
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define btst(a,b) ((a) & (1 << (b)))
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, M, X, cnt;
queue<int> q[10004];
vector<int> v[22];
map<string, int> mp;
string rmp[22];
bool isE[22];

int main()
{
	cintie(0);
	cin >> N >> M;
	cnt = N;
	for(int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		mp[s] = i;
		rmp[i] = s;
	}
	
	for(int i = 0, x; i < M; i++)
	{
		cin >> x;
		for(int j = 0; j < x; j++)
		{
			string s;
			cin >> s;
			q[i].push(mp[s]);
		}
		X = max(X, x);
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 1; j <= N; j++) v[j].clear();
		int mn = INF, mi = INF, mj = 0;
		for(int j = 0; j < M; j++)
		{
			if(q[j].empty()) continue;
			while(isE[q[j].front()]) q[j].pop();
			if(q[j].empty()) continue;
			v[q[j].front()].push_back(j);
		}
		for(int j = 1; j <= N; j++)
			if(!isE[j])
				mn = min(mn, (int) v[j].size());
		for(int j = 1; j <= N; j++)
			if((int)v[j].size() == mn && !isE[j])
				//if(v[j].front() <= mi)
				{
					//mi = v[j].front();
					mj = j;
					break;
				}
		//cout << "elim:" << v[mj].size() << rmp[mj] << endl;
		cnt--;
		if(cnt > 0)
			isE[mj] = true;
		else
			break;
		for(auto e : v[mj])
			if(!q[e].empty())
				q[e].pop();
	}
	
	for(int j = 1; j <= N; j++)
		if(!isE[j])
			cout << rmp[j];
}