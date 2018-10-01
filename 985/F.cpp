#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <memory.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define MP make_pair
#define FF first
#define SS second
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()

typedef long long ll;
typedef pair<int,int> pi; 
typedef double db; 

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=2e5+5;
const int MD1=1e9+7;
const int MD2=1e9+9;
const int K1=37;
const int K2=41;

class dhash
{
	public:
		ll a,b;
		dhash()
		{
			a=b=0;
		}
		dhash(ll x,ll y)
		{
			a=x;
			b=y;
		}
		dhash operator*(const dhash&o)const
		{
			return dhash((a*o.a)%MD1,(b*o.b)%MD2);
		}
		dhash operator+(const dhash&o)const
		{
			return dhash((a+o.a)%MD1,(b+o.b)%MD2);
		}
		dhash operator+(const int&o)const
		{
			return dhash((a+1)%MD1,(b+1)%MD2);
		}
		dhash operator-(const dhash&o)const
		{
			return dhash((a-o.a+MD1)%MD1,(b-o.b+MD2)%MD2);
		}
		bool operator<(const dhash&o)const
		{
			return (a<o.a)||(a==o.a&&b<o.b);
		}
		bool operator!=(const dhash&o)const
		{
			return (a!=o.a)||(b!=o.b);
		}
};

int n,m;
char s[Maxn];
dhash K=dhash(K1,K2);
dhash hsh[26][Maxn];
dhash pw[Maxn];

dhash get_hsh(int c,int l,int r)
{
	return hsh[c][r]-hsh[c][l-1]*pw[r-l+1];
}

void process()
{
	pw[0]=dhash(1,1);
	for(int i=0;i<26;i++) hsh[i][0]=dhash(0,0);
	for(int i=1;i<=n;i++)
	{
		pw[i]=pw[i-1]*K;
		for(int j=0;j<26;j++)
		{
			hsh[j][i]=hsh[j][i-1]*K;
		}
		int c=s[i]-'a';
		hsh[c][i]=hsh[c][i]+1;
	}
}

void solve(int x1,int y1,int l)
{
	dhash A[26],B[26];
	int x2=x1+l-1,y2=y1+l-1;
	for(int i=0;i<26;i++)
	{
		A[i]=get_hsh(i,x1,x2);
		B[i]=get_hsh(i,y1,y2);
	}
	sort(A,A+26);
	sort(B,B+26);
	for(int i=0;i<26;i++)
	{
		if(A[i]!=B[i])
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	process();
	for(int i=1;i<=m;i++)
	{
		int x,y,l;
		scanf("%d%d%d",&x,&y,&l);
		solve(x,y,l);
	}
	return 0;
}
