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

const int Maxn=1e5+5;

int b[30];
int d[Maxn];
int n,m;
bool used[Maxn];
vector<pi> adj[Maxn];

void add(int x)
{
	for(int i=29;i>=0;i--)
	{
		if((x>>i)&1)
		{
			if(b[i])
			{
				x=(x^b[i]);
			}
			else
			{
				b[i]=x;
				break;
			}
		}
	}
}

void dfs(int now)
{
	used[now]=true;
	for(auto v:adj[now])
	{
		int nex=v.FF,w=v.SS;
		if(used[nex])
		{
			add(d[now]^d[nex]^w);
		}
		else
		{
			d[nex]=d[now]^w;
			dfs(nex);
		}
	}
}

void solve()
{
	for(int i=29;i>=0;i--)
	{
		if((d[n]>>i)&1)
		{
			if(b[i])
			{
				d[n]=(d[n]^b[i]);
			}
		}
	}
	printf("%d\n",d[n]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		adj[x].PB(pi(y,w));
		adj[y].PB(pi(x,w));
	}
	dfs(1);
	solve();
	return 0;
}
