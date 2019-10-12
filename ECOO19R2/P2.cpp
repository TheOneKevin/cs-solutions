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
//typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

#define SUBMIT

struct vec
{
	int x, y;
}v[10003];

int N;

int mod(int a)
{
	if((a+4*N)%N == 0) return N;
	return (a+4*N)%N;
}

bool isRef(int a, int b)
{
	for(int i = 1; i <= N/2-1; i++)
	{
		ll d1 = pow(v[a].x-v[mod(a+i)].x, 2)+pow(v[a].y-v[mod(a+i)].y, 2);
		ll d2 = pow(v[b].x-v[mod(a+i)].x, 2)+pow(v[b].y-v[mod(a+i)].y, 2);
		ll d3 = pow(v[a].x-v[mod(a-i)].x, 2)+pow(v[a].y-v[mod(a-i)].y, 2);
		ll d4 = pow(v[b].x-v[mod(a-i)].x, 2)+pow(v[b].y-v[mod(a-i)].y, 2);
		if(!(d1 == d3 && d2 == d4))
			return false;
	}
	//printf("%d %d , %d %d\n", v[a].x, v[a].y, v[b].x, v[b].y);
	return true;
}

int main()
{
#ifndef SUBMIT
	freopen("DATA21.txt", "r", stdin);
#endif
for(int _ = 0; _ < 10; _++){			//CHANGE TO 10
	int cnt=0;
	memset(v, 0, sizeof(v));
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d", &v[i].x, &v[i].y);
		//v[i+N].x = v[i].x, v[i+N].y = v[i].y;
	}
	if(N%2 == 1){
		printf("0\n");
	}
	else{
		for(int i = 1; i <= N/2; i++)
			if(isRef(i, i+N/2))
				cnt++;
		printf("%d\n", cnt);
	}
}
}
