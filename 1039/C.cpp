#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;
typedef pair<ll,int> pli;

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
const int md=1e9+7;

int n,m,k;
ll c[Maxn];
vector<pli> adj[Maxn];
unordered_map<ll,vector<int>> mp; //mp[x] stores the vertices such that have a least one edge with cost x
bool vis[Maxn];
ll pw[Maxn];

void init()
{
	pw[0]=1;
	for(int i=1;i<=n+k;i++)
	{
		pw[i]=(pw[i-1]<<1)%md;
	}
}

int dfs(int u,ll val)
{
	vis[u]=true;
	int ret=1;
	for(auto v:adj[u])
	{
		if(v.FF!=val) continue;
		if(vis[v.SS]) continue;
		ret+=dfs(v.SS,val);
	}
	return ret;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1;i<=n;i++) scanf("%lld",c+i);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ll val=(c[x]^c[y]);
		adj[x].PB(pli(val,y));
		adj[y].PB(pli(val,x));
		mp[val].PB(x);
		mp[val].PB(y);
	}
	ll ans=0;
	int cnt=0;
	for(auto v:mp)
	{
		ll val=v.FF;
		vector<int> & vert=v.SS;
		cnt++;
		int scc=0;
		int num=0;
		for(auto x:vert)
		{
			if(!vis[x])
			{
				num+=dfs(x,val);
				scc++;
			}
		}
		for(auto x:vert)
		{
			vis[x]=false;
		}
		ans=(ans+pw[n-num+scc])%md;
	}
	ans=(ans+pw[n+k]-pw[n]*cnt)%md;
	if(ans<0) ans+=md;
	printf("%lld\n",ans);
	return 0;
}
