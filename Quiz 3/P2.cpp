#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
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

int N, cnt;

void f(int m, int n, string s)
{
	if(m > N) return;
	if(m == N)
	{
		cnt++;
		cout << N << "=" << s << endl;
		return;
	}
	
	for(int i = n; i+m <= N; i++)
	{
		if(i == N) continue;
		if(s.length() == 0)
			f(m+i, i, s + to_string(i));
		else
			f(m+i, i, s + "+" + to_string(i));
	}
}

int main()
{
	scanf("%d", &N);
	f(0, 1, "");
	printf("total=%d", cnt);
}
