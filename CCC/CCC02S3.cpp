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

// CCC '02 S3 - Blindfold
int r, c, m, ans, cx, cy;
char g[377][82]; // x, y
char d[30004];

bool isInBounds(int x, int y) { return x <= c && x >= 1 && y <= r && y >= 1; }
bool isEmpty(int x, int y) { return isInBounds(x,y)&&(g[x][y] == '.' || g[x][y] == '*'); }

int step(int f, char c, int& dx, int& dy)
{
	switch(c)
	{
		case 'F':
			switch(f)
			{
				case 0: dy++; return f;
				case 1: dx++; return f;
				case 2: dy--; return f;
				case 3: dx--; return f;
			}
		case 'R': return (f+1)%4;
		case 'L': return (f+3)%4;
	}
}

inline bool run(int x, int y, int f)
{
	int i = 0; bool noObs = true;
	while(d[i] != 0 && noObs)
	{
		int dx = 0, dy = 0;
		f = step(f, d[i], dx, dy);
		//printf("[%c %d %d, %d]",d[i],f,dx,dy);
		x+=dx,y+=dy;
		noObs &= isEmpty(x, y); i++;
	}
	if(noObs) g[x][y] = '*';
	return noObs;
}

int main()
{
	scanf("%d %d ", &r, &c);
	for(int y = 1; y <= r; y++)
		for(int x = 1; x <= c; x++)
			scanf(" %c", &g[x][r+1-y]);
	scanf("%d", &m);
	int facing = 0;
	for(int i = 0; i < m; i++)
	{
		scanf(" %c", &d[i]);
		//facing = step(facing, d[i], cx, cy);
	}
	//printf("(%d, %d)\n", cx, cy);
	for(int x = 1; x <= c; x++)
	{
		for(int y = 1; y <= r; y++)
		{
			if(!isEmpty(x,y)) continue;
			run(x, y, 0);
			run(x, y, 1);
			run(x, y, 2);
			run(x, y, 3);
			//printf("(%d, %d) ",x,y);
			//if(isEmpty(x+cx, y+cy) && isEmpty(x, y+1) && run(x, y, 0)) g[x+cx][y+cy] = '*';
			//if(isEmpty(x-cx, y-cy) && isEmpty(x, y-1) && run(x, y, 2)) g[x-cx][y-cy] = '*';
			//if(isEmpty(x-cy, y+cx) && isEmpty(x+1, y) && run(x, y, 3)) g[x-cy][y+cx] = '*';
			//if(isEmpty(x+cy, y-cx) && isEmpty(x-1, y) && run(x, y, 1)) g[x+cy][y-cx] = '*';
			//printf("\n");
		}
	}
	
	for(int y = 1; y <= r; y++)
	{
		for(int x = 1; x <= c; x++)
			printf("%c", g[x][r-y+1]);
		printf("\n");
	}
}
