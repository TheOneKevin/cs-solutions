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

char getRNA(char a)
{
	switch(a)
	{
		case 'A': return 'U';
		case 'T': return 'A';
		case 'G': return 'C';
		case 'C': return 'G';
	}
	return 'X';
}

bool isMatch(char a, char b)
{
	return
		(a == 'A' && b == 'T') ||
		(a == 'T' && b == 'A') ||
		(a == 'C' && b == 'G') ||
		(a == 'G' && b == 'C');
}

bool isComplement(string a, string b)
{
	for(int i = 0; i < 6; i++)
		if(!isMatch(a[i], b[6-i-1]))
			return false;
	return true;
}

int main()
{
	cintie(0);
for(int _ = 0; _ < 5; _++) {
	
	string s;
	cin >> s;
	int st = s.find("TATAAT")+10;
	int end = 0;
	for(int l = st; l < s.length(); l++)
	{
		for(int r = s.length()-1; r > l; r--)
		{
			if(r-l < 12) break;
			if(isComplement(s.substr(l,6),s.substr(r-5,6)))
			{
				//cout << s.substr(l,6) << " " << s.substr(r-5,6) << endl;
				end = l;
				goto done;
			} // End if
		} // For r
	} // For l
done:
	cout << _+1 << ": ";
	for(int i = st; i < end; i++)
	{
		cout << getRNA(s[i]);
	}
	cout << "\n";
}} // Main
