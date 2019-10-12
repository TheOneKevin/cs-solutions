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

#define MAXN 10000000
int N, fct[MAXN+5];
vector<int> ps;

int main()
{
	fct[1] = 1;
	for(int i = 2; i <= MAXN; i++) fct[i] = i;
	for(int i = 4; i < MAXN; i+=2) fct[i] = 2;
	for(int i = 3; i*i <= MAXN; i++)
		for(int j = i*i; j <= MAXN && fct[i] == i; j+=i)
			if(fct[j]==j) fct[j]=i;
	fct[1]=0;
	for(int i = 1; i <= MAXN; i++)
		if(fct[i] == i) ps.push_back(i);
	for(int i = 0; i < 5; i++)
	{
		int pp=0, qq=0, rr=0;
		scanf("%d", &N);
		
		if(fct[N] == N) { printf("%d = %d\n", N, N); continue; }
		//if(N%2 == 0 && fct[N/2] == N/2) { printf("%d = %d + %d\n", N, N/2, N/2); continue; }
		//if(N%3 == 0 && fct[N/3] == N/3) { printf("%d = %d + %d + %d\n", N, N/3, N/3, N/3); continue; }
		
		for(int i = 1; i < ps.size() && ps[i] <= N; i++)
		{
			if(!(ps[i]<=N-ps[i])) continue;
			if(ps[i]%2==0||(N-ps[i])%2==0) continue;
			if(fct[ps[i]] == ps[i] && fct[N-ps[i]] == N-ps[i])
				pp = ps[i], qq = N-ps[i];
		}
		
		if(!(pp == 0 && qq == 0))
		{
			printf("%d = %d + %d\n", N, pp, qq);
			continue;
		}
		
		for(int i = N/2; i > 2; i-=2)
		{
			if(i%2==0) i--;
			if(fct[i]!=i) continue;
			for(int j = (N-i)/2; j >= i; j-=2)
			{
				if(j%2==0) j--;
				if(fct[j]!=j) continue;
				if(N-i<2*j)continue;
				if(N-i-j<=0) continue;
				if(fct[N-i-j]!=N-i-j) continue;
				
				pp = i, qq = j, rr = N-i-j;
				printf("%d = %d + %d + %d\n", N, pp, qq, rr);
				goto fm;
			}
		}
fm:
		continue;
	}
}