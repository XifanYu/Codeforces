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
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()
#define clean(v,a) memset(v,a,sizeof(v))

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=2e5+5;

int n,q;
vector<int> adj[Maxn];
int sz[Maxn];
int start[Maxn];
int stk[Maxn];
int T=0;

void dfs(int now)
{
	sz[now]=1;
	start[now]=T;
	stk[T]=now;
	T++;
	for(auto v:adj[now])
	{
		dfs(v);
		sz[now]+=sz[v];
	}
}

int query(int u,int k)
{
	if(k>sz[u]) return -1;
	return stk[start[u]+k-1];
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		adj[p].PB(i);
	}
	for(int i=1;i<=n;i++) sort(forw(adj[i]));
	dfs(1);
	for(int i=1;i<=q;i++)
	{
		int u,k;
		scanf("%d%d",&u,&k);
		int ans=query(u,k);
		printf("%d\n",ans);
	}
	return 0;
}
