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

int n,m,a[105];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	int ans1=0,ans2=0,maxt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>maxt) maxt=a[i];
	}
	int res=0;
	for(int i=1;i<=n;i++) res+=maxt-a[i];
	if(res>=m) ans1=maxt;
	else ans1=maxt+(m-res+n-1)/n;
	ans2=maxt+m;
	printf("%d %d",ans1,ans2);
	return 0;
}
