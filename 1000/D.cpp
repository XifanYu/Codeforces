#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;

ll qpow(ll x,ll k,ll mod)
{
    ll ret=1;
	while(k)
	{
	   if(k&1)	
	   {
	   	 ret=ret*x;
	   	 ret=ret%mod;
	   }
	   x=x*x;
	   x=x%mod;
	   k=(k>>1);
	}
	return ret;	
}
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

const int Maxn=1e3+5;
const int md=998244353;

int n;
int a[Maxn];
ll dp[Maxn];
int c[Maxn][Maxn];

void init()
{
	clean(c,-1);
}

int comb(int x,int y)
{
	if(c[x][y]!=-1) return c[x][y];
	if(y<0||y>x) return c[x][y]=0;
	if(y==0) return c[x][y]=1;
	return c[x][y]=(comb(x-1,y)+comb(x-1,y-1))%md;
}

int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	dp[n+1]=1;
	ll ans=0;
	for(int i=n;i>=1;i--)
	{
		if(a[i]<=0) continue;
		for(int j=i+a[i]+1;j<=n+1;j++)
		{
			dp[i]=(dp[i]+dp[j]*comb(j-i-1,a[i]))%md;
		}
		ans=(ans+dp[i])%md;
	}
	printf("%lld\n",ans);
	return 0;
}
