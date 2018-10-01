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

typedef pair<pi,int> pii;

const int Maxn=3e3+5;

int n,m,k;
vector<int> adj[Maxn];
int dis[Maxn][Maxn];
pi pre[Maxn][Maxn];
map<pii,bool> mp;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	for(int i=1;i<=k;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		mp[pii(pi(a,b),c)]=true;
	}
	memset(dis,-1,sizeof dis);
	queue<pi> q;
	q.push(pi(0,1));
	dis[0][1]=0;
	while(!q.empty())
	{
		pi now=q.front();
		int curr=now.SS,prev=now.FF;
		q.pop();
		for(auto v:adj[curr])
		{
			if(dis[curr][v]==-1&&!mp[pii(now,v)])
			{
				dis[curr][v]=dis[prev][curr]+1;
				pre[curr][v]=now;
				q.push(pi(curr,v));
			}
		}
	}
	int mind=Maxn*Maxn,pos;
	for(int i=1;i<=n;i++)
	{
		if(dis[i][n]!=-1&&dis[i][n]<mind)
		{
			mind=dis[i][n];
			pos=i;
		}
	}
	if(mind==Maxn*Maxn)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",mind);
	stack<int> stk;
	pi now=pi(pos,n);
	while(now.SS!=1)
	{
		stk.push(now.SS);
		now=pre[now.FF][now.SS];
	}
	stk.push(1);
	while(!stk.empty())
	{
		int pos=stk.top();
		stk.pop();
		printf("%d ",pos);
	}
	return 0;
}
