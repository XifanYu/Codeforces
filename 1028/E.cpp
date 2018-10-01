#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;

const int mod=1e9+7;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
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

int n;
ll b[Maxn];
ll a[Maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",b+i);
	b[0]=b[n];
	ll maxt=-1;
	int id;
	bool same=true;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>maxt&&b[i-1]<b[i])
		{
			maxt=b[i];
			id=i;
		}
		if(b[i-1]!=b[i]) same=false;
	}
	if(same)
	{
		if(b[1]==0)
		{
			printf("YES\n");
			for(int i=0;i<n;i++)
			{
				printf("1 ");
			}
			printf("\n");
		}
		else printf("NO\n");
		return 0;
	}
	a[id]=b[id];
	ll base=b[id]*2;
	for(int i=id-1;;i--)
	{
		if(i==0) i+=n;
		if(i==id) break;
		base+=b[i];
		a[i]=base;
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",a[i]);
	}
	printf("\n");
	return 0;
}
