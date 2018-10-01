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
#include <functional>
#include <string.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi; 
typedef double db;

const int mod=1e9+7;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
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
#define clean(v,a) memset(v,a,sizeof(v))

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=1e5+5;

int t;
int a,b,c;
vector<pi> A,B,C;
int p[Maxn];
bool prime[Maxn];

void sieve()
{
	clean(prime,true);
	for(int i=2;i<Maxn;i++)
	{
		if(prime[i])
		{
			for(int j=2*i;j<Maxn;j+=i)
			{
				prime[j]=false;
			}
		}
	}
	for(int i=2,id=1;i<Maxn;i++)
	{
		if(prime[i]) p[id++]=i;
	}
}

ll solve(int x,int y,int z)
{
	A.clear();B.clear();C.clear();
	int d;
	d=1;
	while(x>1)
	{
		if(p[d]*p[d]>x)
		{
			A.PB(pi(x,1));
			x=1;
			break;
		}
		while(x%p[d]) d++;
		int cnt=0;
		while(x%p[d]==0)
		{
			cnt++;
			x/=p[d];
		}
		A.PB(pi(p[d],cnt));
	}
	d=1;
	while(y>1)
	{
		if(p[d]*p[d]>y)
		{
			B.PB(pi(y,1));
			y=1;
			break;
		}
		while(y%p[d]) d++;
		int cnt=0;
		while(y%p[d]==0)
		{
			cnt++;
			y/=p[d];
		}
		B.PB(pi(p[d],cnt));
	}
	d=1;
	while(z>1)
	{
		if(p[d]*p[d]>z)
		{
			C.PB(pi(z,1));
			z=1;
			break;
		}
		while(z%p[d]) d++;
		int cnt=0;
		while(z%p[d]==0)
		{
			cnt++;
			z/=p[d];
		}
		C.PB(pi(p[d],cnt));
	}
	ll ret=1;
	int sz1=A.size(),sz2=B.size(),sz3=C.size();
	for(int i=0;i<sz1;i++)
	{
		ret*=A[i].SS+1;
	}
	for(int i=0;i<sz2;i++)
	{
		ret*=B[i].SS+1;
	}
	for(int i=0;i<sz3;i++)
	{
		ret*=C[i].SS+1;
	}
	ll del=1;
	for(int i=0,j=0,k=0;i<sz1;i++)
	{
		while(j<sz2&&B[j].FF<A[i].FF) j++;
		while(k<sz3&&C[k].FF<A[i].FF) k++;
		if(A[i].FF==B[j].FF&A[i].FF==C[k].FF)
		{
			int mint=A[i].SS;
			mint=min(mint,B[j].SS);
			mint=min(mint,C[k].SS);
			del*=mint+1;
		}
	}
	if(del>1)
	{
		ret-=del*2;
	}
	return ret;
}

int main()
{
	scanf("%d",&t);
	sieve();
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		ll ans=solve(a,b,c);
		printf("%lld\n",ans);
	}	
	return 0;
}
