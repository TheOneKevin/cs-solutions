#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define MOD 1000000007 // Change me!
#define lsb(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int)*8-__builtin_clz(n)-1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define ff first
#define ss second
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define cintie { cin.sync_with_stdio(0); cin.tie(0); }
typedef long long ll;
typedef struct{int i, f;}vec;
typedef pair<int, int> ip;

int N, K, sz, bucket[27];
string A, B;
vec freq[27];

int main()
{
	cintie;
	cin >> N >> K >> A;
	for(int i = 0; i < 26; i++) freq[i].i=i;
	for(int i = 0; i < N; i++) freq[A[i]-'a'].f++;
	sort(freq,freq+26, [](vec a, vec b) { return a.f < b.f; });
	if(K < freq[0].f || N < K) { cout << "WRONGANSWER"; return 0; }
	
	// This is why I have depression
	{
		// Determine which letters will fall in the LCS string
		int lcs = 0, i = 0;
		while(lcs < K)
		{
			if(lcs + freq[i].f <= K)
				lcs += freq[i].f, bucket[freq[i].i] = freq[i].f;
			else
			{
				bucket[freq[i].i] = K - lcs;
				lcs = K;
			}
			i++;
		}
	}
	
	//for(int i = 0; i < 26; i++) printf("%c %d\n", (char)(i+'a'), bucket[i]);
	
	// Take substring to satisfy LCS
	for(int i = 0; i < N; i++)
		if(bucket[A[i]-'a'] != 0)
			B += A[i], bucket[A[i]-'a']--;
	// Fill in the rest with a dummy letter
	// But ensure that letter will not change the LCS (i.e., freq.f is smallest)
	while(B.length() < N)
		B += (char)(freq[0].i + 'a');
	
	cout << B;
}
