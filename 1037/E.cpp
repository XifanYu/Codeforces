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

const int Maxn=2e5+5;

int n,m,k;
vector<pi> adj[Maxn];
int ans[Maxn];
int deg[Maxn];
pi e[Maxn];
bool trip[Maxn];
bool del[Maxn];


int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&e[i].FF,&e[i].SS);
		deg[e[i].FF]++;
		deg[e[i].SS]++;
		adj[e[i].FF].PB(pi(i,e[i].SS));
		adj[e[i].SS].PB(pi(i,e[i].FF));
	}
	clean(trip,true);
	queue<int> q;
	int cur=n;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]<k&&trip[i])
		{
			q.push(i);
			trip[i]=false;
			cur--;
		}
	}
	for(int i=m;i>=1;i--)
	{
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(auto v:adj[x])
			{
				if(trip[v.SS]&&!del[v.FF])
				{
					deg[v.SS]--;
					del[v.FF]=true;
					if(deg[v.SS]<k)
					{
						q.push(v.SS);
						trip[v.SS]=false;
						cur--;
					}
				}
			}
		}
		ans[i]=cur;
		if(trip[e[i].FF]&&trip[e[i].SS])
		{
			del[i]=true;
			deg[e[i].FF]--;
			deg[e[i].SS]--;
			if(deg[e[i].FF]<k)
			{
				q.push(e[i].FF);
				trip[e[i].FF]=false;
				cur--;
			}
			if(deg[e[i].SS]<k)
			{
				q.push(e[i].SS);
				trip[e[i].SS]=false;
				cur--;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
