#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;
typedef long long ll;

int N = 0;
deque<char> dq;

int main()
{
	string s;
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());
	char* ptr = c;
	while(*c != 0)
	{
		if(dq.empty()) { dq.push_back(*c++); continue; }
		if(dq.back() == '(' && *c == ')') dq.pop_back();
		else dq.push_back(*c);
		c++;
	}
	
	if(dq.size() == 0) { printf("YES"); return 0; }
	//cout << "c" << endl;
	
	while(!dq.empty() && (dq.back() == '(' && *c == ')'))
		dq.pop_back();
	
	c = ptr;
	
	if(!dq.empty() && (dq.front() != ')' || dq.back() != '('))
		printf("%s", dq.size() == 2 ? "YES" : "NO");
	else
		printf("NO");
	
	//printf("%c %c %d\n", dq.front(), dq.back(), dq.size());
}

/*

if(balanced) yes
if(balance = 2 and minimal = 0)
if(balance = -2 and minimal = -2)

*/
