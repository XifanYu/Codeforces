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

int n,k;
vector<int> adj[Maxn];
int ans=0;

int dfs(int u,int f)
{
	vector<int> dep;
	dep.clear();
	for(auto v:adj[u])
	{
		if(v==f) continue;
		dep.PB(dfs(v,u)+1);
	}
	if(dep.size()==0) dep.PB(0);
	sort(all(dep));
	int i=dep.size()-1;
	for(;i>0;i--)
	{
		if(dep[i]+dep[i-1]>k) ans++;
		else break;
	}
	return dep[i];
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(adj[i].size()>1)
		{
			dfs(i,i);
			ans++;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
