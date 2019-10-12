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

#define MAXN 10000

int fct[10004], f[10004];
//vector<int> p;

void getF(int n)
{
	while(n != 1)
	{
		//p.push_back(fct[x]);
		f[fct[n]]++;
		n /= fct[n];
	}
}

int main()
{
	fct[1] = 1;
	for(int i = 2; i <= MAXN; i++) fct[i] = i;
	for(int i = 4; i < MAXN; i+=2) fct[i] = 2;
	for(int i = 3; i*i <= MAXN; i++)
		if(fct[i] == i)
			for(int j = i*i; j <= MAXN; j+=i)
				if(fct[j]==j)
					fct[j]=i;
	//
	for(int i = 0, a; i < 5; i++)
	{
		memset(f,0,sizeof(f));
		scanf("%d", &a);
		for(int j = 1; j <= a; j++)
			getF(j);
		bool has = false;
		for(int j = 0; j <= MAXN; j++)
		{
			if(has && f[j]) printf(" * ");
			if(f[j])
			{
				has = true;
				printf("%d^%d", j, f[j]);
			}
		}
		printf("\n");
	}
}
