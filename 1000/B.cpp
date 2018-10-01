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

int n,M;
int a[Maxn];
int pre[Maxn];
int suf[Maxn];

int main()
{
	scanf("%d%d",&n,&M);
	a[0]=0;a[n+1]=M;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	pre[0]=0;
	for(int i=1;i<=n+1;i++)
	{
		pre[i]=pre[i-1];
		if(i&1) pre[i]+=a[i]-a[i-1];
	}
	suf[n+1]=0;
	for(int i=n;i>=0;i--)
	{
		suf[i]=suf[i+1];
		if(i&1) suf[i]+=a[i+1]-a[i];
	}
	int ans=pre[n+1];
	for(int i=0;i<=n;i++)
	{
		if(a[i+1]-a[i]==1) continue;
		int tmp=pre[i]+suf[i+1];
		tmp+=a[i+1]-a[i]-1;
		if(tmp>ans) ans=tmp;
	}
	printf("%d\n",ans);
	return 0;
}
