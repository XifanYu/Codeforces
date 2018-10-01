#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ll,int> pli;
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

const int Maxn=1e4+5;

ll dp[Maxn][6];

ll dfs(ll l,int t) //if we can find out the number in range [l,r) within t queries, return r-l
{
	if(l>10000) return dfs(10000,t);
	if(dp[l][t]!=-1) return dp[l][t];
	if(t==0) return dp[l][t]=0;
	ll now=l;
	for(ll i=0;i<=l;i++)
	{
		ll x=dfs(now,t-1);
		now+=x+1;
	}
	now--;
	return dp[l][t]=now-l;
}

ll a[Maxn];

void solve(ll l,int t)
{
	ll mx=min(l,(ll)10000);
	ll now=l;
	a[0]=l-1;
	for(ll i=1;i<=mx;i++)
	{
		ll x=dfs(now,t-1);
		now+=x+1;
		a[i]=now-1;
	}
	printf("%lld ",mx);
	for(ll i=1;i<=mx;i++) printf("%lld ",a[i]);
	puts("");
	fflush(stdout);
}

ll lb=1;
int q=5;
int v;

int main()
{
	clean(dp,-1);
	while(true)
	{
		solve(lb,q);
		scanf("%d",&v);
		if(v<0) return 0;
		lb=a[v]+1;
		q--;
	}
	return 0;
}
