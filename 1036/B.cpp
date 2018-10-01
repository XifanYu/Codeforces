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

int main()
{
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		ll n,m,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		if(n<0) n=-n;
		if(m<0) m=-m;
		if(n>m) swap(n,m);
		ll ans=n;
		ll res=m-n;
		bool flag;
		if(res&1)
		{
			flag=true;
			ans+=res-1;
			k--;
		}
		else
		{
			flag=false;
			ans+=res;
		}
		if(ans>k)
		{
			printf("-1\n");
			continue;
		}
		ll go=k-ans;
		if(go&1)
		{
			if(flag) ans+=go;
			else ans+=go-2;
		}
		else
		{
			ans+=go;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
