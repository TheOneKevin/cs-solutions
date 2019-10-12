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

int N, K, Q, a[100005], L[100005], R[100005], sl[16][100005];
deque<int> dmx, dmn;

int query(int l, int r)
{
	int k = ilg2(r - l + 1);
	if(R[sl[k][l]] >= R[sl[k][r-pow2(k)+1]]
		return sl[k][l];
	else return sl[k][r-pow2(k)+1];
}

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	
	{
		int l = 1, r = 1;
		while(r <= N)
		{
			while(!dmn.empty()&&dmn.back()>a[r]) dmn.pop_back();
			while(!dmx.empty()&&dmx.back()<a[r]) dmx.pop_back();
			dmn.push_back(a[r]); dmx.push_back(a[r]);
			while(dmx.front()-dmn.front() > K)
			{
				if(dmx.front() == a[l]) dmx.pop_front();
				if(dmn.front() == a[l]) dmn.pop_front();
				R[l] = r-l; l++;
			}
			L[r] = r-l+1;
			r++;
		}
	}
	
	for(int i = 1; i <= N; i++)
		cout << L[i] << " ";
	cout << endl;
	for(int i = 1; i <= N; i++)
		cout << R[i] << " ";
	
	for(int i = 0; i <= N; i++) sl[0][i] = R[i]-i+1;
	for(int l = 1; l <= ilg2(N); l++)
	{
		for(int i = 1; i+pow2(l)-1<=N; i++)
		{
			if(R[sl[l-i][i]]>sl[l-1][i+pow2(l-1)]) sl[l][i] = sl[l-1][i];
			else sl[l][i] = sl[l-1][i+pow2(l-1)];
		}
	}
	scanf("%d", &Q);
	for(int _ = 0; _ < Q; _++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		
	}
}
