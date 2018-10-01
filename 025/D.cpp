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

const int Maxn=1e3+5;

int n;
vector<int> adj[Maxn];
bool used[Maxn];
vector<pi> del,add;

void dfs(int now,int pre=-1)
{
	used[now]=true;
	for(auto v:adj[now])
	{
		if(v!=pre)
		{
			if(used[v])
			{
				if(now<v)del.PB(pi(now,v));
			}
			else dfs(v,now);
		}
	}
}

int main()
{
	scanf("%d",&n);
	memset(used,false,sizeof used);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			add.PB(pi(1,i));
			dfs(i);
		}
	}
	int len=del.size();
	printf("%d\n",len);
	for(int i=0;i<len;i++)
	{
		printf("%d %d %d %d\n",del[i].FF,del[i].SS,add[i].FF,add[i].SS);
	}
	return 0;
}
