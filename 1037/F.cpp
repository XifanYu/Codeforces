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

const int Maxn=1e6+5;
const ll md=1e9+7;

int n,k;
int a[Maxn];
int l[Maxn],r[Maxn];
int cnt[Maxn];

void init()
{
	stack<int> stk;
	while(!stk.empty()) stk.pop();
	for(int i=0;i<n;i++)
	{
		while(!stk.empty()&&a[stk.top()]<a[i]) stk.pop();
		if(stk.empty()) l[i]=0;
		else l[i]=stk.top()+1;
		stk.push(i);
	}
	while(!stk.empty()) stk.pop();
	for(int i=n-1;i>=0;i--)
	{
		while(!stk.empty()&&a[stk.top()]<=a[i]) stk.pop();
		if(stk.empty()) r[i]=n-1;
		else r[i]=stk.top()-1;
		stk.push(i);
	}
	for(int i=1;i<=n;i++)
	{
		cnt[i]=cnt[i-1];
		cnt[i]+=(i-1)/(k-1);
		if(cnt[i]>=md) cnt[i]-=md;
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	init();
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		int x=i-l[i];
		int y=r[i]-i;
		int num=cnt[x+y+1]-cnt[x]-cnt[y];
		while(num<0) num+=md;
		ans+=(ll)num*a[i];
		ans%=md;
	}
	printf("%lld\n",ans);
	return 0;
}
