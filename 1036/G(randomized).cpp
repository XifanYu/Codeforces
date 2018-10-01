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

int n,m;
vector<int> iadj[Maxn],adj[42];
int in[Maxn],out[Maxn];
int src[22],cnt1=0,snk[22],cnt2=0;
bool vis[Maxn];
int ss[22];
int dfs_clock;
int dfn[42],low[42];
stack<int> stk;
bool instk[42];
int id;

void idfs(int u)
{
	vis[u]=true;
	for(auto v:iadj[u])
	{
		if(!vis[v]) idfs(v);
	}
}

void dfs(int u)
{
	dfn[u]=low[u]=++dfs_clock;
	stk.push(u);
	instk[u]=true;
	for(auto v:adj[u])
	{
		if(!dfn[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instk[v])
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u])
	{
		id++;
		while(stk.top()!=u)
		{
			instk[stk.top()]=false;
			stk.pop();
		}
		instk[stk.top()]=false;
		stk.pop();
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	int st=clock();
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		iadj[u].PB(v);
		out[u]++;
		in[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!in[i])
		{
			src[cnt1++]=i;
		}
		if(!out[i])
		{
			snk[cnt2++]=i;
		}
	}
	int cnt=cnt1;
	for(int i=0;i<cnt;i++)
	{
		clean(vis,false);
		idfs(src[i]);
		for(int j=0;j<cnt;j++)
		{
			if(vis[snk[j]])
			{
				adj[i].PB(j+cnt);
			}
		}
	}
	vector<int> p;
	for(int i=0;i<cnt;i++) p.PB(i);
	while(clock()-st<=CLOCKS_PER_SEC*6.5)
	{
		random_shuffle(all(p));
		for(int i=0;i<cnt;i++)
		{
			adj[i+cnt].PB(p[i]);
		}
		clean(instk,false);
		clean(dfn,0);
		clean(low,0);
		dfs_clock=id=0;
		for(int i=0;i<(cnt<<1)&&id<=1;i++)
		{
			if(!dfn[i]) dfs(i);
		}
		if(id>1)
		{
			puts("NO");
			return 0;
		}
		for(int i=0;i<cnt;i++)
		{
			adj[i+cnt].pop_back();
		}
	}
	puts("YES");
	return 0;
}
