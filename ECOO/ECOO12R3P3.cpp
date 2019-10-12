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

stack<int> s;

int doOp(int a, int b, char c)
{
	switch(c)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case 'q': return a / b;
		case 'r': return a % b;
	}
	return 0;
}

void parseargs()
{
	char c = ' ';
	while(c == ' ') scanf("%c", &c);
	//cout << c << endl;
	if(c == '(')
	{
		scanf("%c ", &c);
		s.push((int) c);
		//printf("OPR %c\n", c);
		parseargs();
	}
	else
	{
		if(c >= '0' && c <= '9')
		{
			//printf("ARG %c\n", c);
			s.push(c - '0');
		}
		else if(c == ')')
		{
			// Get operands
			int b = (int) s.top(); s.pop();
			int a = (int) s.top(); s.pop();
			char op = s.top(); s.pop();
			s.push(doOp(a, b, op));
			//printf("END %d %c %d = %d\n", a, op, b, s.top());
			if(s.size() == 1) return;
			//return;
		}
		parseargs();
	}
}

int main()
{
	for(int i = 0; i < 10; i++)
	{
		while(!s.empty()) s.pop();
		parseargs();
		printf("%d\n", s.top());
	}
}
