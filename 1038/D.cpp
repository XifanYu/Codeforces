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

const int Maxn=5e5+5;

int n,a[Maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	if(n==1)
	{
		printf("%d\n",a[1]);
		return 0;
	}
	bool flag1=true,flag2=true;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=0) flag1=false;
		if(a[i]>=0) flag2=false;
	}
	if(!flag1&&!flag2)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<0) ans-=a[i];
			else ans+=a[i];
		}
		printf("%lld\n",ans);
	}
	else if(flag1)
	{
		ll ans=0;
		int maxt=1e9+7;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i];
			if(a[i]<maxt)
			{
				maxt=a[i];
			}
		}
		ans-=(ll)2*maxt;
		printf("%lld\n",ans);
	}
	else if(flag2)
	{
		ll ans=0;
		int maxt=1e9+7;
		for(int i=1;i<=n;i++)
		{
			ans-=a[i];
			if(-a[i]<maxt)
			{
				maxt=-a[i];
			}
		}
		ans-=(ll)2*maxt;
		printf("%lld\n",ans);
	}
	return 0;
}
