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

ll dp[20][4];
ll pw[20];

void init()
{
	for(int i=0;i<=18;i++) dp[i][0]=1;
	for(int j=1;j<=3;j++)
	{
		for(int i=j;i<=18;i++) dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*9;
	}
	pw[0]=1;
	for(int i=1;i<=18;i++) pw[i]=pw[i-1]*10;
}

ll solve(ll k,int num)
{
	if(num==0) return 1;
	if(k==0) return 0;
	ll tmp=k;
	int cnt=0;
	while(tmp>=10)
	{
		cnt++;
		tmp/=10;
	}
	ll ret=dp[cnt][num]+(tmp-1)*dp[cnt][num-1]+solve(k-tmp*pw[cnt],num-1);
	return ret;
}

int main()
{
	int t;
	scanf("%d",&t);
	init();
	for(int i=1;i<=t;i++)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		ll ans=0;
		for(int j=1;j<=3;j++) 
		{
			ans+=solve(r,j)-solve(l-1,j);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
