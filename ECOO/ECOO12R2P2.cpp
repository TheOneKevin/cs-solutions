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

int getUpper(string s)
{
	int res = 0;
	for(int i = 0; i < s.length(); i++)
		if(s[i] >= 'A' && s[i] <= 'Z')
			res++;
	return res;
}

int getLower(string s)
{
	int res = 0;
	for(int i = 0; i < s.length(); i++)
		if(s[i] >= 'a' && s[i] <= 'z')
			res++;
	return res;
}

int getDigits(string s)
{
	int res = 0;
	for(int i = 0; i < s.length(); i++)
		if(s[i] >= '0' && s[i] <= '9')
			res++;
	return res;
}

int getOthers(string s)
{
	return s.length() - getDigits(s) - getLower(s) - getUpper(s);
}

bool isOther(char c)
{
	if(c >= '0' && c <= '9') return false;
	if(c >= 'A' && c <= 'Z') return false;
	if(c >= 'a' && c <= 'z') return false;
	return true;
}

int getNumberOfCharTypes(string s)
{
	int res = 0;
	if(getDigits(s)) res++;
	if(getOthers(s)) res++;
	if(getLower(s)) res++;
	if(getUpper(s)) res++;
	return res;
}

int getLongestSequence(string s)
{
	int cnt=0, mx=0;
	char l = 0; // previous
	for(int i = 0; i < s.length(); i++)
	{
        //cout << l << " " << s[i] << endl;
		if(l - s[i] == 1 && (
			(s[i] >= 'a' && s[i] <= 'z' && l >= 'a' && l <= 'z')||
			(s[i] >= 'A' && s[i] <= 'Z' && l >= 'A' && l <= 'Z')))
			cnt++;
		else{
            //cout << "Y" << endl;
			mx = max(mx, cnt);
			cnt = 0;
		}
		l = s[i];
	}
	
	cnt=0;
	l = 0; // previous
	for(int i = 0; i < s.length(); i++)
	{
		if(l - s[i] == -1 && (
			(s[i] >= 'a' && s[i] <= 'z' && l >= 'a' && l <= 'z')||
			(s[i] >= 'A' && s[i] <= 'Z' && l >= 'A' && l <= 'Z')))
			cnt++;
		else{
			mx = max(mx, cnt);
			cnt = 0;
		}
		l = s[i];
	}
	
	return max(mx, cnt)+1;
}

int getLongestDigits(string s)
{
	int cnt=0, mx=0;
	char l = 0; // previous
	for(int i = 0; i < s.length(); i++)
	{
        //cout << l << " " << s[i] << endl;
		if(abs(l - s[i]) == 1 && 
			(s[i] >= '0' && s[i] <= '9' && l >= '0' && l <= '9'))
			cnt++;
		else{
            //cout << "Y" << endl;
			mx = max(mx, cnt);
			cnt = 0;
		}
		l = s[i];
	}
	cnt=0;
	l = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(abs(l - s[i]) == -1 && 
			(s[i] >= '0' && s[i] <= '9' && l >= '0' && l <= '9'))
			cnt++;
		else{
			mx = max(mx, cnt);
			cnt = 0;
		}
		l = s[i];
	}
	return max(mx, cnt)+1;
}

int main()
{
for(int _ = 0; _ < 10; _++){

	int res=0;
	string s;
	cin >> s;
	// Easy stuff
	res += s.length()*4;
	if(s.length() >= 8 && getNumberOfCharTypes(s) >= 3)
		res += 2 + getNumberOfCharTypes(s)*2;
	if(getUpper(s)) res += (s.length()-getUpper(s))*2;
	if(getLower(s)) res += (s.length()-getLower(s))*2;
	if(getDigits(s) < s.length())
		res += 4 * getDigits(s);
	res += 6 * getOthers(s);
	//cout<<res<<endl;
	// Get stuff minus edges
	res += 2 * getDigits(s);
	if(s[0] >= '0' && s[0] <= '9') res -= 2;
	if(s[s.length()-1] >= '0' && s[s.length()-1] <= '9') res -= 2;
	//cout<<res<<endl;
	res += 2 * getOthers(s);
	if(isOther(s[0])) res -= 2;
	if(isOther(s[s.length()-1])) res -= 2;
	//cout<<res<<endl;
	// Only letters etc...
	if(getUpper(s) + getLower(s) == s.length())
		res -= s.length();
	if(getDigits(s) == s.length())
		res -= s.length();
	//cout<<res<<endl;
	// Consecutive & sequential
	for(int i = 0; i < s.length(); i++)
	{
		int n = i;
		while(s[i] >= 'A' && s[i] <= 'Z') i++;
		if(i <= s.length() && i != n)
			res -= 2*(i-n-1);
	}
	for(int i = 0; i < s.length(); i++)
	{
		int n = i;
		while(s[i] >= 'a' && s[i] <= 'z') i++;
		if(i <= s.length() && i != n)
			res -= 2*(i-n-1);
	}
	//cout<<res<<endl;
	for(int i = 0; i < s.length(); i++)
	{
		int n = i;
		while(s[i] >= '0' && s[i] <= '9') i++;
		if(i <= s.length() && i != n)
			res -= 2*(i-n-1);
	}
	cout<<res<<endl;
	if(getLongestSequence(s) > 2)
		res -= 3*(getLongestSequence(s)-2);
	cout<<res<<endl;
	if(getLongestDigits(s) > 2)
		res -= 3*(getLongestDigits(s)-2);
	
	if(res < 0) res = 0;
	if(res > 100) res = 100;
	
	if(res >= 0 && res <= 20) cout << "Very Weak ";
	if(res >= 21 && res <= 40) cout << "Weak ";
	if(res >= 41 && res <= 60) cout << "Good ";
	if(res >= 61 && res <= 71) cout << "Strong ";
	if(res >= 81 && res <= 100) cout << "Very Strong ";
	cout << "(score = " << res << ")\n";
	
}}
