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
#include <functional>
#include <string.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi; 
typedef double db;

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
#define get(a) scanf("%d",&a)
#define get2(a,b) scanf("%d%d",&a,&b)
#define get3(a,b,c) scanf("%d%d%d",&a,&b,&c)

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

typedef pair<ll,int> pl;

const int Maxn=3e5+5;

int n,m,id;
ll d[2][Maxn];
int sz[Maxn];
bool flag[Maxn];
vector<pi> adj[Maxn];

void dfs(int now,int pre=0)
{
	sz[now]=1;
	for(auto v:adj[now])
	{
		if(v.FF!=pre)
		{
			dfs(v.FF,now);
			sz[now]+=sz[v.FF];
		}
	}
}

void dfs(ll dis,int id,int now,int pre=0)
{
	d[id][now]=dis;
	for(auto v:adj[now])
	{
		if(v.FF!=pre)
		{
			dfs(dis+v.SS,id,v.FF,now);
		}
	}
}

int route(int now,int pre=0,int cnt=1)
{
	if(now==n)
	{
		flag[now]=true;
		return cnt;
	}
	for(auto v:adj[now])
	{
		if(v.FF!=pre)
		{
			int ret=route(v.FF,now,cnt+1);
			if(ret!=-1)
			{
				flag[now]=true;
				return ret;
			}
		}
	}
	return -1;
}

ll solve()
{
	route(1);
	dfs(1);
	dfs(0,0,1);
	dfs(0,1,n);
	bool chk=false;
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			if(sz[i]>=2)
			{
				chk=true;
				break;
			}
		}
		else
		{
			int siz=adj[i].size();
			if(i==1||i==n)
			{
				if(siz>=3)
				{
					chk=true;
					break;
				}
			}
			else
			{
				if(siz>=4)
				{
					chk=true;
					break;
				}
			}
		}
	}
	if(chk) return d[0][n];
	int now=n;
	ll x1=-1,x2=-1;
	ll ret=0;
	while(true)
	{
		for(auto v:adj[now])
		{
			if(flag[v.FF]) continue;
			if(x1!=-1) ret=max(ret,d[0][v.FF]+x1);
			if(x2!=-1) ret=max(ret,d[0][v.FF]+x2);
		}
		if(x1!=-1) ret=max(ret,d[0][now]+x1);
		for(auto v:adj[now])
		{
			if(flag[v.FF]) continue;
			if(d[1][v.FF]>x1) x1=d[1][v.FF];
		}
		if(x2!=-1&&x2>x1) x1=x2;
		x2=d[1][now];
		if(d[0][now])
		{
			for(auto v:adj[now])
			{
				if(flag[v.FF]&&d[0][v.FF]<d[0][now])
				{
					now=v.FF;
					break;
				}
			}
		}
		else break;
	}
	return ret;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		adj[u].PB(pi(v,w));
		adj[v].PB(pi(u,w));
	}
	ll tmp=solve();
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if(tmp+x<d[0][n]) printf("%lld\n",tmp+x);
		else printf("%lld\n",d[0][n]);
	}
	return 0;
}
