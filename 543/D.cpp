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

const int md=1e9+7;
const int Maxn=2e5+5;

int n;
ll dp[Maxn][2];
ll dp2[Maxn];
bool flag[Maxn];
vector<int> adj[Maxn];

ll fast_pow(ll x,ll y)
{
	ll rez=1;
	if(y==0) return rez;
	rez=fast_pow(x,y/2);
	rez=(rez*rez)%md;
	if(y&1) rez=(rez*x)%md;
	return rez;
}

ll inverse(ll x)
{
	return fast_pow(x,md-2);
}

void dfs1(int now,int pre=-1)
{
	dp[now][0]=1;
	dp2[now]=1;
	for(auto v:adj[now])
	{
		if(v!=pre) 
		{
			dfs1(v,now);
			if((dp[v][0]+1)%md==0&&!flag[now])
			{
				flag[now]=true;
			}
			else dp2[now]=(dp2[now]*(dp[v][0]+1))%md;
			dp[now][0]=(dp[now][0]*(dp[v][0]+1))%md;
		}
	}
}

void dfs2(int now,int pre=-1)
{
	for(auto v:adj[now])
	{
		if(v!=pre)
		{
			if((dp[v][0]+1)%md==0)
			{
				dp[v][1]=(dp[now][1]*dp2[now]+1)%md;
			}
			else
			{
				dp[v][1]=(dp[now][1]*dp[now][0])%md;
				dp[v][1]=(dp[v][1]*inverse(dp[v][0]+1)+1)%md;
			}
			dfs2(v,now);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		adj[i].PB(x);
		adj[x].PB(i);
	}
	memset(dp,0,sizeof dp);
	memset(flag,0,sizeof flag);
	dfs1(1);
	dp[1][1]=1;
	dfs2(1);
	for(int i=1;i<=n;i++)
	{
		ll x=(dp[i][0]*dp[i][1])%md;
		printf("%lld ",x);
	}
	printf("\n");
	return 0;
}
