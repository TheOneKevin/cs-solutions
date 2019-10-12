#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define MOD 1000000007
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

#define SUBMIT

int N, M;
map<int, int> mp1;

void fold(int z, bool l)
{
	int sm = 0;
	for(auto m : mp1)
	{
		sm = m.first;
		break;
	}
	int nm = z - sm + 1;
	//cout << nm << endl;
	if(l)
	{
		for(int i = 1; mp1.count(nm+i)&&mp1[nm+i]!=0; i++)
		{
			mp1[nm+i]--;
			if(mp1.count(nm-i) == 0)
				mp1[nm-i]=1;
			else
				mp1[nm-i]++;
			
		}
	}
	else
	{
		for(int i = 1; mp1.count(nm-i) && mp1[nm-i]!=0; i++)
		{
			mp1[nm-i]--;
			if(mp1.count(nm-i) == 0)
				mp1[nm+i]=1;
			else
				mp1[nm+i]++;
			
		}
	}
}

int main()
{
int kevin=1;
#ifndef SUBMIT
	freopen("DATA31.txt", "r", stdin);
	kevin=10;
#endif

for(int test=1;test<=kevin;test++){
	
	mp1.clear();
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) mp1[i] = 1;
	for(int i = 0; i < M; i++)
	{
		int a; char c;
		cin >> a >> c;
		fold(a, c == 'L');
	}
	int l = 0, w = 0;
	for(auto a : mp1)
	{
		if(a.second != 0) l++;
		w = max(w, a.second);
	}
	printf("%d %d", l, w);
}

}
