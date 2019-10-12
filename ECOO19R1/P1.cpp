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

int n, m, d, ans, cur;
int a[1001];		//true if event on that day

int main()
{
	
	for(int test=1;test<=10;test++){
		
		memset(a, false, sizeof(a));
		ans=0;
		
		scanf("%d%d%d", &n, &m, &d);
		
		for(int i=1,x;i<=m;i++){
			scanf("%d", &x);
			a[x]++;
		}
		
		cur=n;
		
		for(int i=1;i<=d;i++){
			if(cur<1){
				ans++;
				cur=n;
				//printf(" %d ", i);
			}
			cur--;
			cur+=a[i];
			n+=a[i];
		}
		
		printf("%d\n", ans);
		
	}
	
}
