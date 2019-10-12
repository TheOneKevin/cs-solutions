#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define loop(x, a, b) for(int x = a; x < b; x++)
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int T, G, s[5], asnus;
bool p[6];

struct vv
{
	int ss[5];
	bool pp[6];
};

void rec(vv st)
{
	int ii = 0, jj = 0;
	if(!st.pp[0]) ii = 1, jj = 2, st.pp[0] = true;
	else if(!st.pp[1]) ii = 1, jj = 3, st.pp[1] = true;
	else if(!st.pp[2]) ii = 1, jj = 4, st.pp[2] = true;
	else if(!st.pp[3]) ii = 2, jj = 3, st.pp[3] = true;
	else if(!st.pp[4]) ii = 2, jj = 4, st.pp[4] = true;
	else if(!st.pp[5]) ii = 3, jj = 4, st.pp[5] = true;
	else
	{
		int maxidx = 0, ans = 0;
		for(int i = 0; i < 5; i++)
		{
			if(ans < st.ss[i]) ans = st.ss[i], maxidx = i;
			else if(ans == st.ss[i] && i != T) maxidx = i;
		}
		if(maxidx == T) asnus++;
		//printf("%d %d %d %d %d\n", st.ss[1], st.ss[2], st.ss[3], st.ss[4], maxidx);
		return;
	}
	
	st.ss[ii]+=3;
	rec(st);
	st.ss[ii]-=3, st.ss[jj]+=3;
	rec(st);
	st.ss[jj]-=2, st.ss[ii]++;
	rec(st);
}

int main()
{
	scanf("%d %d", &T, &G);
	for(int i = 0, a, b, sa, sb; i < G; i++)
	{
		scanf("%d %d %d %d", &a, &b, &sa, &sb);
		//s[a] += sa, s[b] += sb;
		if(sa > sb) s[a] += 3;
		else if(sb > sa) s[b] += 3;
		else s[a]++, s[b]++;
		if(a == 1 && b == 2) p[0] = true;
		else if(a == 1 && b == 3) p[1] = true;
		else if(a == 1 && b == 4) p[2] = true;
		else if(a == 2 && b == 3) p[3] = true;
		else if(a == 2 && b == 4) p[4] = true;
		else if(a == 3 && b == 4) p[5] = true;
	}
	// I hate life
	rec({
		{s[0],s[1],s[2],s[3],s[4]},
		{p[0],p[1],p[2],p[3],p[4],p[5]}
	});
	// Kill me now.
	printf("%d", asnus);
}