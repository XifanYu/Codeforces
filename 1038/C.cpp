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

const int Maxn=1e5+5;

int n,a[Maxn],b[Maxn];
int l,r;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	l=n;r=n;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(l==0)
		{
			r--;
		}
		else if(r==0)
		{
			ans+=a[l];
			l--;
		}
		else if(a[l]>=b[r])
		{
			ans+=a[l];
			l--;
		}
		else
		{
			r--;
		}
		if(l==0)
		{
			ans-=b[r];
			r--;
		}
		else if(r==0)
		{
			l--;
		}
		else if(a[l]<=b[r])
		{
			ans-=b[r];
			r--;
		}
		else
		{
			l--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
