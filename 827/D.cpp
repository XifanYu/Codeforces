#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <memory.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define MP make_pair
#define FF first
#define SS second
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()

typedef long long ll;
typedef pair<int,int> pi; 
typedef double db; 

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=2e5+5;
const int INF=1e9+5;

class edge
{
	public:
		int u,v,c,id;
		void read(int i)
		{
			scanf("%d%d%d",&u,&v,&c);
			id=i;
		}
		bool operator<(const edge&o)const
		{
			return c<o.c;
		}
};

int n,m;
edge e[Maxn];
int ans[Maxn];
int pa[Maxn]; //parent
int dep[Maxn]; //depth
int maxw[Maxn][19]; //max weight
int ancs[Maxn][19]; //ancestor
bool marked[Maxn]; //marked
int up[Maxn]; //next unmarked
int minw[Maxn]; //min weight
vector<pi> adj[Maxn];
bool used[Maxn]; //on MST

int find(int x)
{
	return (x==pa[x])?x:pa[x]=find(pa[x]);
}

bool uni(edge edg)
{
	int a=find(edg.u),b=find(edg.v);
	if(a==b) return false;
	pa[b]=a;
	return true;
}

void mst()
{
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
		if(uni(e[i]))
		{
			adj[e[i].u].PB(pi(e[i].v,e[i].c));
			adj[e[i].v].PB(pi(e[i].u,e[i].c));
			used[i]=true;
		}
	}
}

void dfs(int now,int pre=-1)
{
	for(auto v:adj[now])
	{
		if(v.FF!=pre)
		{
			dep[v.FF]=dep[now]+1;
			ancs[v.FF][0]=now;
			maxw[v.FF][0]=v.SS;
			for(int i=1;i<=18;i++)
			{
				ancs[v.FF][i]=ancs[ancs[v.FF][i-1]][i-1];
				maxw[v.FF][i]=max(maxw[v.FF][i-1],maxw[ancs[v.FF][i-1]][i-1]);
			}
			up[v.FF]=now;
			dfs(v.FF,now);
		}
	}
}

void build()
{
	dep[1]=0;
	for(int i=0;i<=18;i++) 
	{
		ancs[1][i]=1;
		maxw[1][i]=0;
	}
	dfs(1);
	memset(minw,0,sizeof minw);
	memset(marked,0,sizeof marked);
}

int mark(int src,int dst,int wgt)
{
	if(dep[src]<=dep[dst]) return src;
	if(!marked[src])
	{
		marked[src]=true;
		minw[src]=wgt;
	}
	return up[src]=mark(up[src],dst,wgt);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) pa[i]=i;
	for(int i=1;i<=m;i++)
	{
		e[i].read(i);
	}
	mst();
	build();
	for(int i=1;i<=m;i++)
	{
		if(!used[i])
		{
			int u=e[i].u,v=e[i].v;
			if(dep[u]<dep[v]) swap(u,v);
			int w=0;
			for(int i=18;i>=0;i--)
			{
				if((1<<i)<=dep[u]-dep[v])
				{
					w=max(w,maxw[u][i]);
					u=ancs[u][i];
				}
			}
			for(int i=18;i>=0;i--)
			{
				if(ancs[u][i]!=ancs[v][i])
				{
					w=max(w,maxw[u][i]);
					w=max(w,maxw[v][i]);
					u=ancs[u][i];
					v=ancs[v][i];
				}
			}
			int lca=u;
			if(u!=v)
			{
				w=max(w,maxw[u][0]);
				w=max(w,maxw[v][0]);
				lca=ancs[u][0];
			}
			ans[e[i].id]=w-1;
			u=e[i].u;
			v=e[i].v;
			mark(u,lca,e[i].c);
			mark(v,lca,e[i].c);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(used[i])
		{
			int u=e[i].u,v=e[i].v;
			if(dep[u]<dep[v]) swap(u,v);
			ans[e[i].id]=minw[u]-1;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
