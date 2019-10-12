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

//#define SUBMIT

int N, R, S, st=0x3f3f3f3f;
long long ans;
int a[1000001];

int main()
{
int kevin=1;
#ifndef SUBMIT
	freopen("DATA42.txt", "r", stdin);
	kevin=10;
#endif

for(int test=1;test<=kevin;test++){
	
	st=0x3f3f3f3f;
	memset(a, 0, sizeof(a));
	
	scanf("%d%d%d", &N, &R, &S);
	
	for(int i=1;i<=N;i++){
		scanf("%d", &a[i]);
		if(a[i]){
			st=min(st, i);
		}
	}
	
	ans=S;
	int k=0;
	for(int i=st;i<=N;i++){
		if(a[i]==0){
			k++;
		}
		else{
			if(S+R<=R*(k+1)){
				ans+=S+R;
			}
			else{
				ans+=R*(k+1);
			}
			k=0;
		}
	}
	
	if(st==0x3f3f3f3f){
		printf("0\n");
	}
	else{
		printf("%lld\n", ans);
	}
	
}

}
