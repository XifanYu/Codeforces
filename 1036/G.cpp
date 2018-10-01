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
vector<int> adj[Maxn];
int in[Maxn],out[Maxn];
int src[22],cnt1=0,snk[22],cnt2=0;
bool vis[Maxn];
int ss[22];

void dfs(int u)
{
	vis[u]=true;
	for(auto v:adj[u])
	{
		if(!vis[v]) dfs(v);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].PB(v);
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
	for(int i=0;i<cnt1;i++)
	{
		clean(vis,false);
		dfs(src[i]);
		for(int j=0;j<cnt2;j++)
		{
			if(vis[snk[j]])
			{
				ss[i]|=(1<<j);
			}
		}
	}
	for(int i=1;i<(1<<cnt1)-1;i++)
	{
		int cur=0;
		int num1=0,num2=0;
		for(int j=0;j<cnt1;j++)
		{
			if((i>>j)&1)
			{
				cur|=ss[j];
				num1++;
			}
		}
		for(int j=0;j<cnt2;j++)
		{
			if((cur>>j)&1)
			{
				num2++;
			}
		}
		if(num2<=num1)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
