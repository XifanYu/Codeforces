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

typedef pair<ll,int> pli;

const int Maxn=2e5+5;

int n,m,q;
int nxt[Maxn],head[Maxn],to[Maxn],wt[Maxn],dep[Maxn],cnte;
bool flag[Maxn],vis[Maxn];
int pa[18][Maxn];
ll dp[18][Maxn];
ll d[45][Maxn];
int pt[45],cntp;

void add_edge(int u,int v,int w)
{
	nxt[cnte]=head[u];
	to[cnte]=v;
	wt[cnte]=w;
	head[u]=cnte++;
}

void dfs(int u=1,int f=0,int w=0)
{
	vis[u]=true;
	dep[u]=dep[f]+1;
	pa[0][u]=f;
	dp[0][u]=w;
	for(int i=1;i<18;i++)
	{
		pa[i][u]=pa[i-1][pa[i-1][u]];
		dp[i][u]=dp[i-1][pa[i-1][u]]+dp[i-1][u];
	}
	for(int e=head[u];~e;e=nxt[e])
	{
		if(vis[to[e]]) continue;
		flag[e]=flag[e^1]=true;
		dfs(to[e],u,wt[e]);
	}
}

void dij(int now)
{
	PQ<pli,vector<pli>,greater<pli> > pq;
	clean(d[now],0x3f);
	d[now][pt[now]]=0;
	pq.push(pli(0,pt[now]));
	while(!pq.empty())
	{
		auto p=pq.top();
		pq.pop();
		ll dis=p.FF;
		int pos=p.SS;
		for(int e=head[pos];~e;e=nxt[e])
		{
			if(d[now][to[e]]>dis+wt[e])
			{
				d[now][to[e]]=dis+wt[e];
				pq.push(pli(d[now][to[e]],to[e]));
			}
		}
	}
}

ll solve(int u,int v)
{
	ll ret=0;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=17;i>=0;i--)
	{
		if(dep[pa[i][u]]>=dep[v])
		{
			ret+=dp[i][u];
			u=pa[i][u];
		}
	}
	if(u==v) return ret;
	for(int i=17;i>=0;i--)
	{
		if(pa[i][u]!=pa[i][v])
		{
			ret+=dp[i][u]+dp[i][v];
			u=pa[i][u];
			v=pa[i][v];
		}
	}
	ret+=dp[0][u]+dp[0][v];
	return ret;
}

int main()
{
	scanf("%d%d",&n,&m);
	clean(nxt,-1);
	clean(head,-1);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dfs();
	for(int e=0;e<(m<<1);e++)
	{
		if(!flag[e])
		{
			pt[cntp++]=to[e];
		}
	}
	for(int i=0;i<cntp;i++)
	{
		dij(i);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ll ans=(ll)0x3f3f3f3f3f3f3f3f;
		ans=min(ans,solve(u,v));
		for(int i=0;i<cntp;i++)
		{
			ans=min(ans,d[i][u]+d[i][v]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
