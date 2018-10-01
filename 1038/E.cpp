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

const int Maxn=2e2+5;
const int inf=0x3f3f3f3f;

int n;
int deg[4];
vector<int> adj[4];
int to[Maxn];
int w[Maxn];
bool vis[Maxn];
bool flag[4];
vector<vector<int>> scc;
vector<int> vs;
vector<int> path;

void dfs(int u) //find connected components
{
	flag[u]=true;
	vs.PB(u);
	for(auto v:adj[u])
	{
		if(!flag[to[v]])
		{
			dfs(to[v]);
		}
	}
}

void euler(int u) //find euler path
{
	for(auto e:adj[u])
	{
		if(!vis[e])
		{
			vis[e]=vis[e^1]=true;
			euler(to[e]);
			path.PB(e);
		}
	}
}

int solve(vector<int> s)
{
	int cnt=0;//number of vertices with odd degree
	for(auto v:s)
	{
		if(deg[v]&1) cnt++;
	}
	if(cnt>2) //need to delete one edge
	{
		int ret=0;
		for(auto v:s)
		{
			for(auto e:adj[v])
			{
				if(to[e]!=v)
				{
					vis[e]=vis[e^1]=true;
					deg[to[e]]--;
					deg[to[e^1]]--;
					for(auto v:s)
					{
						if(deg[v]&1)
						{
							path.clear();
							euler(v);
							int tmp=0;
							for(auto e:path)
							{
								tmp+=w[e];
							}
							ret=max(ret,tmp);
						}
					}
					clean(vis,false);
					deg[to[e]]++;
					deg[to[e^1]]++;
				}
			}
		}
		return ret;
	}
	for(auto v:s)
	{
		if(deg[v]&1)
		{
			path.clear();
			euler(v);
			int ret=0;
			for(auto e:path)
			{
				ret+=w[e];
			}
			return ret;
		}
	}
	path.clear();
	euler(s[0]);
	int ret=0;
	for(auto e:path)
	{
		ret+=w[e];
	}
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;c--;
		to[(i<<1)]=c;
		w[(i<<1)]=b;
		adj[a].PB((i<<1));
		deg[a]++;
		to[(i<<1)|1]=a;
		w[(i<<1)|1]=b;
		adj[c].PB((i<<1)|1);
		deg[c]++;
	}
	for(int i=0;i<4;i++)
	{
		if(!flag[i])
		{
			vs.clear();
			dfs(i);
			scc.PB(vs);
		}
	}
	int ans=0;
	for(auto s:scc)
	{
		ans=max(ans,solve(s));
	}
	printf("%d\n",ans);
	return 0;
}
