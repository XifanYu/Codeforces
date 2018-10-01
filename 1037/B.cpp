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

const int Maxn=2e5+5;

int n,s;
int a[Maxn];
int x=0,y=0;

int main()
{
	scanf("%d%d",&n,&s);
	PQ<int,vector<int>,greater<int> > qx,qy;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]>s)
		{
			y++;
			qy.push(a[i]-s);
		}
		else if(a[i]<s)
		{
			x++;
			qx.push(s-a[i]);
		}
	}
	int d=(n>>1);
	ll ans=0;
	while(y>d)
	{
		y--;
		int top=qy.top();
		qy.pop();
		ans+=top;
	}
	while(x>d)
	{
		x--;
		int top=qx.top();
		qx.pop();
		ans+=top;
	}
	printf("%lld\n",ans);
	return 0;
}
