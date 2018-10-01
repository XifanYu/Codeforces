#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;

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

int n;
vector<int> adj[Maxn];
int dp[Maxn][3];
int ans=0;

void dfs(int now=1,int pre=1,int cnt=0)
{
	for(auto v:adj[now])
	{
		if(v!=pre) dfs(v,now,cnt+1);
	}
	dp[now][0]=dp[now][2]=0;dp[now][1]=1;
	for(auto v:adj[now])
	{
		if(v!=pre)
		{
			dp[now][0]+=min(dp[v][0],dp[v][1]);
			dp[now][1]+=min(dp[v][1],dp[v][2]);
			dp[now][2]+=min(dp[v][0],dp[v][1]);
		}
	}
	int tmp=dp[now][0];
	dp[now][0]=0x3f3f3f3f;
	for(auto v:adj[now])
	{
		if(v!=pre)
		{
			if(dp[now][0]>tmp-min(dp[v][0],dp[v][1])+dp[v][1])
			{
				dp[now][0]=tmp-min(dp[v][0],dp[v][1])+dp[v][1];
			}
		}
	}
	if(cnt==2)
	{
		int tmp1=0,tmp2=dp[now][1];
		for(auto v:adj[now])
		{
			if(v!=pre) tmp1+=min(dp[v][0],dp[v][1]);
		}
		ans+=min(tmp1,tmp2);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	dfs();
	printf("%d\n",ans);
	return 0;
}
