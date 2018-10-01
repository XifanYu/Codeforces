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

typedef pair<int,pi> ppi;

const int Maxn=1005;
const int md=998244353;

int n,m;
int a[Maxn][Maxn];
ll e[Maxn][Maxn];
ll inv[Maxn*Maxn];
ll cnt[2][Maxn];
int r,c;
vector<ppi> vv;

void pre()
{
	for(int i=1;i<Maxn*Maxn;i++)
	{
		inv[i]=qpow(i,md-2,md);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) 
		{
			scanf("%d",a[i]+j);
			vv.PB(ppi(a[i][j],pi(i,j)));
		}
	}
	scanf("%d%d",&r,&c);
	pre();
	sort(all(vv));
	ll sume=0,sumx=0,sumx2=0,sumy=0,sumy2=0,ans=0;
	for(int i=0,j=0;i<vv.size();i++)
	{
		if(i&&vv[i].FF!=vv[i-1].FF)
		{
			for(;j<i;j++)
			{
				ll nx=vv[j].SS.FF,ny=vv[j].SS.SS;
				sume=(sume+e[nx][ny])%md;
				sumx=(sumx+nx)%md;
				sumx2=(sumx2+nx*nx)%md;
				sumy=(sumy+ny)%md;
				sumy2=(sumy2+ny*ny)%md;
			}
		}
		ll x=vv[i].SS.FF,y=vv[i].SS.SS;
		ll tmp=(sume+sumx2+sumy2-sumx*x*2-sumy*y*2)%md;
		if(j) tmp=(tmp*inv[j]+x*x+y*y)%md;
		if(tmp<0) tmp+=md;
		e[x][y]=tmp;
	}
	printf("%lld\n",e[r][c]);
	return 0;
}
