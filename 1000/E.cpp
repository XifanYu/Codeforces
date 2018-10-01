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
vector<int> adj[Maxn],nadj[Maxn];
int low[Maxn],dfn[Maxn],cur=0;
int stk[Maxn],top=0;
int comp[Maxn],cnt=0;
int dis[Maxn];
int maxt,maxid;

void tarjan(int u,int f)
{
    low[u]=dfn[u]=++cur;
    stk[++top]=u;
    for(auto v:adj[u])
    {
    	if(v==f) continue;
    	if(!dfn[v])
    	{
    		tarjan(v,u);
    		low[u]=min(low[u],low[v]);
		}
		else
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
    if(low[u]==dfn[u])
	{
        int v=-1;
        cnt++;
        while(u!=v)
		{
            v=stk[top--];
            comp[v]=cnt;
        }
    }
}

void dfs(int u,int f)
{
	for(auto v:nadj[u])
	{
		if(v==f) continue;
		dis[v]=dis[u]+1;
		dfs(v,u);
	}
}


int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].PB(y);
		adj[y].PB(x);
	}
	tarjan(1,-1);
	for(int i=1;i<=n;i++)
	{
		for(auto v:adj[i])
		{
			if(comp[i]==comp[v]) continue;
			nadj[comp[i]].PB(comp[v]);
		}
	}
	dis[1]=0;
	dfs(1,-1);
	maxt=-1;
	for(int i=1;i<=cnt;i++)
	{
		if(maxt<dis[i])
		{
			maxt=dis[i];
			maxid=i;
		}
	}
	dis[maxid]=0;
	dfs(maxid,-1);
	maxt=-1;
	for(int i=1;i<=cnt;i++)
	{
		if(maxt<dis[i])
		{
			maxt=dis[i];
		}
	}
	printf("%d\n",maxt);
	return 0;
}
