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
 
const int Maxn=1e6+5; 

vector<int> ind[Maxn];
vector<int> adj[Maxn];
int sz[Maxn];
int maxt[Maxn];
int maxid[Maxn];
int ans[Maxn];
int n;

void combine(int x,int y)
{
	for(int i=sz[y];i>=1;i--)
	{
		ind[x][sz[x]-i]+=ind[y][sz[y]-i];
		if(ind[x][sz[x]-i]>=maxt[x])
		{
			maxt[x]=ind[x][sz[x]-i];
			maxid[x]=i-1;
		}
	}
}

int dfs(int now,int pre=-1)
{
	if(adj[now].size()==1&&pre!=-1)
	{
		ind[now].PB(1);
		sz[now]++;
		maxt[now]=1;
		maxid[now]=0;
		ans[now]=0;
		return now;
	}
	vector<int> tmp;
	for(auto v:adj[now])
	{
		if(v!=pre)
		{
			int id=dfs(v,now);
			tmp.PB(id);
		}
	}
	int choose=tmp[0];
	for(int i=1;i<tmp.size();i++)
	{
		if(sz[tmp[i]]>sz[choose])
		{
			combine(tmp[i],choose);
			choose=tmp[i];
		}
		else
		{
			combine(choose,tmp[i]);
		}
	}
	ind[choose].PB(1);
	sz[choose]++;
	if(maxt[choose]==1)
	{
		maxid[choose]=-1;
	}
	maxid[choose]++;
	ans[now]=maxid[choose];
	return choose;
}

int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].PB(y);
		adj[y].PB(x);
	}
	dfs(1);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
