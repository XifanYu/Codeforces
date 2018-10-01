#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;

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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define clean(v,a) memset(v,a,sizeof(v))
#define PQ priority_queue

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=2e5+5;
const int Maxq=11e5+5;
const int Maxa=5032107+5;

vector<int> prime;
int lp[Maxa]; //lp[i]: the least prime that divides i
int simp[Maxa]; //simp[i]: the simplified form after removing all squares inside i
int num[Maxa]; //num[i]: the number of distinct primes in the factorization of i 
int n,q;
int a[Maxn];
int ans[Maxq];
vector<pi> Q[Maxn];
int dp[Maxa][8]; //dp[val][x]: the rightmost position i st. a[i] = val * (the product of x primes)
int best[15]; //best[x]: the rightmost position l st. the answer for [l,now] is x

void pre()
{
	for(int i=2;i<Maxa;i++)
	{
		if(lp[i]==0)
		{
			lp[i]=i;
			prime.PB(i);
		}
		for(int j=0;j<prime.size();j++)
		{
			if(prime[j]*i>=Maxa) break;
			if(prime[j]>lp[i]) break;
			lp[prime[j]*i]=prime[j];
		}
	}
	simp[1]=1;
	for(int i=2;i<Maxa;i++)
	{
		int cur=i/lp[i];
		if(cur%lp[i]==0)
		{
			simp[i]=simp[cur/lp[i]];
			num[i]=num[cur/lp[i]];
		}
		else
		{
			simp[i]=simp[cur]*lp[i];
			num[i]=num[cur]+1;
		}
	}
}

vector<int> divs;

void get_divisor(int x)
{
	divs.clear();
	divs.PB(1);
	while(x>1)
	{
		int sz=divs.size();
		for(int i=0;i<sz;i++)
		{
			divs.PB(divs[i]*lp[x]);
		}
		x/=lp[x];
	}
}

int main()
{
	pre();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",a+i);
		a[i]=simp[a[i]];
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		Q[r].PB(pi(l,i));
	}
	for(int i=1;i<=n;i++)
	{
		get_divisor(a[i]);
		for(auto d:divs)
		{
			int add1=num[a[i]]-num[d];
			for(int add2=0;add2<=7;add2++)
			{
				int l=dp[d][add2];
				if(l>best[add1+add2]) best[add1+add2]=l;
			}
		}
		for(auto qr:Q[i])
		{
			for(int i=0;i<=14;i++)
			{
				if(best[i]>=qr.FF)
				{
					ans[qr.SS]=i;
					break;
				}
			}
		}
		for(auto d:divs)
		{
			int add=num[a[i]]-num[d];
			if(i>dp[d][add]) dp[d][add]=i;
		}
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
