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

const int Maxn=4e5+5;

class pnt
{
public:
	ll x;
	int t;
	pnt(ll X=0,int T=0)
	{
		x=X;t=T;
	}
	bool operator<(const pnt & o)const
	{
		if(x<o.x) return true;
		if(x>o.x) return false;
		return t<o.t;
	} 
};

int n;
int cnt=0;
pnt p[Maxn];
ll ans[Maxn];
ll cur=0;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		p[cnt++]=pnt(x,0);
		p[cnt++]=pnt(y,1);
	}
	sort(p,p+cnt);
	ll last=p[0].x-1;
	for(int i=0;i<cnt;i++)
	{
		if(p[i].t==0) 
		{
			ans[cur]+=p[i].x-1-last;
			last=p[i].x-1;
			cur++;	
		}
		else
		{
			ans[cur]+=p[i].x-last;
			last=p[i].x;
			cur--;
		}
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	puts("");
	return 0;
}
