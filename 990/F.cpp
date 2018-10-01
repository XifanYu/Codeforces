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
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=2e5+5;

int n,m;
int s[Maxn];
vector<pi> adj[Maxn];
int e[Maxn];
bool vis[Maxn];

int dfs(int now)
{
	vis[now]=true;
	int ans=s[now];
	for(auto v:adj[now])
	{
		int nex=v.FF,id=v.SS;
		if(!vis[nex])
		{
			int f=dfs(nex);
			ans+=f;
			if(id>0) e[id]+=f;
			else e[-id]-=f;
		}
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		tot+=s[i];
	}
	if(tot)
	{
		printf("Impossible\n");
		return 0;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].PB(pi(y,i));
		adj[y].PB(pi(x,-i));
	}
	printf("Possible\n");
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		printf("%d\n",e[i]);
	}
	return 0;
}
