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

const int Maxn=3e5+5;

int n,m;
int a[Maxn],b[Maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",b+i);
	int ans=0;
	int l,r;
	ll sum1,sum2;
	for(l=1,r=1,sum1=a[1],sum2=b[1];l<=n&&r<=m;)
	{
		if(sum1==sum2)
		{
			l++;
			r++;
			sum1=(l<=n)?a[l]:0;
			sum2=(r<=m)?b[r]:0;
			ans++;
		}
		else if(sum1<sum2)
		{
			l++;
			sum1+=(l<=n)?a[l]:0;
		}
		else
		{
			r++;
			sum2+=(r<=m)?b[r]:0;
		}
	}
	if(l<=n||r<=m||sum1||sum2) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
