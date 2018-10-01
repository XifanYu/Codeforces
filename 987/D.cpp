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

int n,m,k,s;
int a[Maxn];
int d[Maxn];
vector<int> adj[Maxn];
vector<int> city[105];
vector<int> cost[Maxn];

void bfs(int i)
{
	memset(d,0x3f,sizeof d);
	queue<int> q;
	for(auto v:city[i])
	{
		d[v]=0;
		q.push(v);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto v:adj[x])
		{
			if(d[v]>d[x]+1)
			{
				d[v]=d[x]+1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++) cost[i].PB(d[i]);
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		city[a[i]].PB(i);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	for(int i=1;i<=k;i++) bfs(i);
	for(int i=1;i<=n;i++)
	{
		sort(forw(cost[i]));
		int ans=0;
		for(int j=0;j<s;j++) ans+=cost[i][j];
		printf("%d ",ans);
	}
	return 0;
}
