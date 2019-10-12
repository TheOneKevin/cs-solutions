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

//start and end i coord will be h-1

int l, w, h, lsj, lej;
char g[12][102];
queue<ip> q;
bool inq[12][102], r[102];
bool suc;

bool clear_down(int si, int sj){
	for(int i=si;i<=h-1;i++){		//coming back down
		if(g[i][sj]=='@'){
			//printf("   down %d %d\n", i, sj);
			return false;
		}
	}
	return true;
}

bool clear_side(int si, int sj){
	for(int j=sj;j<=sj+2;j++){		//sideways two
		if(g[si][j]=='@'){
			//printf("  side %d %d\n", si, j);
			return false;
		}
		r[j]=true;
	}
	return clear_down(si, sj+2);
}

bool clear_up(int si, int sj){
	bool ret=false;
	//printf(":%d\n", si-l);
	for(int i=si;i>=si-l;i--){		//jumping up
		if(g[i][sj]!='@'){
			//printf(" %d %d\n", i, sj);
			ret=ret||clear_side(i, sj);
		}
	}
	return ret;
}

//////////////////////////////////////

int main()
{
	for(int test=1;test<=10;test++){
		
		memset(inq, false, sizeof(inq));
		memset(r, false, sizeof(r));
		suc=false;
		for(int i=1;i<=10;i++){
			for(int j=1;j<=100;j++){
				g[i][j]=' ';
			}
		}
		while(!q.empty()){
			q.pop();
		}
		
		scanf("%d%d%d", &l, &w, &h);
		
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				scanf(" %c", &g[i][j]);
				if(g[i][j]=='L'){
					lsj=j;
				}
				else if(g[i][j]=='G'){
					lej=j;
				}
			}
		}

		/*for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				printf("%c", g[i][j]);
			}
			printf("\n");
		}*/
		
		//printf("eoi\n");
		//printf("lsj=%d\n", lsj);
		
		q.push({h-1, lsj});
		inq[h-1][lsj]=true;
		r[lsj]=true;
		while(!q.empty()){
			int ci=q.front().first, cj=q.front().second;			//ci should always be h-1
			q.pop();
			if(ci<1||ci>h||cj<1||cj>lej){
				break;
			}
			inq[ci][cj]=false;
			r[cj]=true;
			//printf(" %d %d\n", ci, cj);
			if(ci==h-1&&cj==lej){
				printf("CLEAR\n");
				suc=true;
				break;
			}
			if(g[ci][cj+1]!='@'&&!inq[ci][cj+1]){		//can we run?
				q.push({ci, cj+1});
				inq[ci][cj+1]=true;
			}
			if(ci==h-1&&clear_up(ci, cj)&&!inq[ci][cj]){		//can we jump?
				q.push({ci, cj+2});
				inq[ci][cj]=true;
			}
		}
		
		if(!suc){
			for(int j=lsj;j<=lej;j++){
				if(!r[j]){
					printf("%d\n", j);
					break;
				}
			}
		}
		
	}
}
