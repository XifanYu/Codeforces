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
typedef pair<ll,ll> pl; 
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
int c[Maxn];
int a[Maxn];
bool root[Maxn];
int used[Maxn];

int cycle(int cur,int des,int cost)
{
	if(cur==des) return cost;
	return cycle(a[cur],des,min(cost,c[a[cur]]));
}

int dfs(int now)
{
	used[now]=1;
	int ret=0;
	if(used[a[now]]==0) ret=dfs(a[now]);
	else if(used[a[now]]==1) ret=cycle(a[now],now,c[a[now]]);
	used[now]=2;
	return ret;
}

void solve()
{
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		if(root[i]) 
		{
			ret+=dfs(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i]==0)
		{
			ret+=dfs(i);
		}	
	}
	
	printf("%d\n",ret);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",c+i);
	clean(used,0);
	clean(root,true);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		root[a[i]]=false;
	}
	solve();
	return 0;
}
