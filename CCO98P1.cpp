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
typedef unsigned long long ll;

// I really hope this works
typedef struct
{
	// bit 0 -> bit 256
	uint64_t lo, hi;
	__uint128_t xhi; // Agh! Using 4 lls is too difficult!
} llx;

int N;

#define ONE ((llx) { .lo=1, .hi=0, .xhi=0 })
#define ZRO ((llx) { .lo=0, .hi=0, .xhi=0 })

llx operator+(llx x, llx y)
{
	__uint128_t lo = (__uint128_t) x.lo+y.lo;
	__uint128_t hi = (__uint128_t) x.hi+y.hi+(lo>>64);
	llx res =
	{
		.lo = (uint64_t) lo,
		.hi = (uint64_t) hi,
		.xhi = x.xhi+y.xhi+(hi>>64)
	};
	return res;
}

llx operator*(llx x, llx y)
{
	__uint128_t a1 = (__uint128_t) x.lo*y.lo;
	__uint128_t a2 = (__uint128_t) x.lo*y.hi;
	__uint128_t a3 = (__uint128_t) x.lo*y.xhi;
	__uint128_t a4 = (__uint128_t) x.hi*y.lo;
	__uint128_t a5 = (__uint128_t) x.hi*y.hi;
	uint64_t a6 = x.hi*y.xhi;
	__uint128_t a7 = (__uint128_t) x.xhi*y.lo;
	__uint128_t a8 = (__uint128_t) x.xhi*y.hi;
	uint64_t lo = a1;
	__uint128_t t1 = (a1 >> 64) + (uint64_t) a2;
	uint64_t t2 = t1;
	__uint128_t hi = (__uint128_t) t2 + (uint64_t) a4;
	__uint128_t xhi = (a2 >> 64) + a3 + (a4 >> 64) + a5 + ((__uint128_t) a6 << 64) +
					   a7 + ((__uint128_t) a8 << 64) + (t1 >> 64) + (hi >> 64);
	llx res =
	{
		.lo = lo,
		.hi = (uint64_t) hi,
		.xhi = xhi
	};
	return res;
}

void mult(llx F[2][2], llx M[2][2])
{
	llx x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	llx y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	llx z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	llx w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
	
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void powe(llx F[2][2], int n)
{
	if(n == 0 || n == 1) return;
	llx M[2][2] = {{ONE, ONE}, {ONE, ZRO}};
	powe(F, n / 2);
	mult(F, F); // F * F
	if(n % 2 != 0)
		mult(F, M); // F * M
}

llx fib(int n)
{
	llx F[2][2] = {{ONE, ONE}, {ONE, ZRO}};
	if(n == 0) return ZRO;
	powe(F, n - 1);
	return F[0][0];
}

char* tostring(const uint64_t N[4])
{
	static char s[79];
	uint64_t n[4];
	char* p = s;
	memset(s, '0', sizeof(s) - 1);
	s[sizeof(s) - 1] = '\0';
	memcpy(n, N, sizeof(n));
	for (int i = 0; i < 256; i++)
	{
		int carry = (n[3] >= (1ULL<<63));
		// Shift n[] left, doubling it
		n[3] = ((n[3]<<1) & (~1ULL)) + (n[2] >= (1ULL<<63));
		n[2] = ((n[2]<<1) & (~1ULL)) + (n[1] >= (1ULL<<63));
		n[1] = ((n[1]<<1) & (~1ULL)) + (n[0] >= (1ULL<<63));
		n[0] = ((n[0]<<1) & (~1ULL));
		// Add s[] to itself in decimal, doubling it
		for (int j = sizeof(s) - 2; j >= 0; j--)
		{
			s[j] += s[j] - '0' + carry;
			carry = (s[j] > '9');
			if (carry) s[j] -= 10;
		}
	}
	while ((p[0] == '0') && (p < &s[sizeof(s) - 2]))
		p++;  
	return p;
}

int main()
{
	while(true)
	{
		scanf("%d", &N);
		if(N == 0) break;
		llx f = fib(N);
		constexpr const __uint128_t bottom_mask = (__uint128_t{1} << 64) - 1;
		constexpr const __uint128_t top_mask = ~bottom_mask;
		uint64_t test[4] = { f.lo, f.hi, f.xhi & bottom_mask, (f.xhi & top_mask) >> 64 };
		printf("%s\n", tostring(test));
	}
}
