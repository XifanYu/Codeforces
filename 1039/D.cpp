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

const int Maxn=1e5+5;

int n;
int ans[Maxn];
int head[Maxn];
int nxt[Maxn<<1];
int to[Maxn<<1];
int rem[Maxn];
int par[Maxn];
int seq[Maxn],id=0;

void dfs(int u,int f)
{
	par[u]=f;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
	}
	seq[++id]=u;
}

int solve(int k)
{
	if(~ans[k]) return ans[k];
	int cur_ans=0;
	for(int i=1;i<=n;i++)
	{
		int max1=0,max2=0,u=seq[i];
		for(int j=head[u];j;j=nxt[j])
		{
			int v=to[j];
			if(v==par[u]) continue;
			if(rem[v]>max1)
			{
				max2=max1;
				max1=rem[v];
			}
			else if(rem[v]>max2)
			{
				max2=rem[v];
			}
		}
		if(max1+max2+1>=k)
		{
			cur_ans++;
			rem[u]=0;
		}
		else
		{
			rem[u]=max1+1;
		}
	}
	return ans[k]=cur_ans;
}

void add(int i,int x,int y)
{
	nxt[i<<1]=head[x];
	head[x]=(i<<1);
	to[i<<1]=y;
	nxt[(i<<1)|1]=head[y];
	head[y]=(i<<1)|1;
	to[(i<<1)|1]=x;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(i,a,b);
	}
	clean(ans,-1);
	dfs(1,0);
	int SQ=sqrt(n)/2;
	for(int i=1;i<=SQ;i++) solve(i);
	for(int i=SQ+1;i<=n;)
	{
		int val=solve(i);
		int lb=i,ub=val?((n/val)+1):(n+1),mi;
		while(ub-lb>1)
		{
			mi=(ub+lb)>>1;
			int nval=solve(mi);
			if(nval==val) lb=mi;
			else ub=mi;
		}
		for(int j=i;j<=lb;j++) ans[j]=val;
		i=lb+1;
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
