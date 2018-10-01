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
#define get(a) scanf("%d",&a)
#define get2(a,b) scanf("%d%d",&a,&b)
#define get3(a,b,c) scanf("%d%d%d",&a,&b,&c)

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=3e3+5;
const int INF=0x3f3f3f3f;

int n,m;
vector<int> adj[Maxn];
int dist[Maxn][Maxn];
int far[Maxn][3];
int rfar[Maxn][3];

void bfs(int i)
{
	clean(dist[i],0x3f);
	dist[i][i]=0;
	queue<int> q;
	q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto v:adj[x])
		{
			if(dist[i][v]>dist[i][x]+1)
			{
				dist[i][v]=dist[i][x]+1;
				q.push(v);
			}
		}
	}
}

void solve()
{
	clean(far,-1);
	clean(rfar,-1);
	for(int k=0;k<3;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j||dist[i][j]==INF) continue;
				bool flag=false;
				for(int m=0;m<k;m++)
				{
					if(far[i][m]==j)
					{
						flag=true;
						break;
					}
				}
				if(flag) continue;
				if(far[i][k]==-1||dist[i][j]>dist[i][far[i][k]])
				{
					far[i][k]=j;
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(i==j||dist[j][i]==INF) continue;
				bool flag=false;
				for(int m=0;m<k;m++)
				{
					if(rfar[i][m]==j)
					{
						flag=true;
						break;
					}
				}
				if(flag) continue;
				if(rfar[i][k]==-1||dist[j][i]>dist[rfar[i][k]][i])
				{
					rfar[i][k]=j;
				}
			}
		}
	}
	int seq[4],ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j||dist[i][j]==INF) continue;
			for(int a=0;a<3;a++)
			{
				if(rfar[i][a]==-1) continue;
				for(int b=0;b<3;b++)
				{
					if(far[j][b]==-1) continue;
					if(rfar[i][a]!=j&&far[j][b]!=i&&rfar[i][a]!=far[j][b])
					{
						if(ans<dist[rfar[i][a]][i]+dist[i][j]+dist[j][far[j][b]])
						{
							ans=dist[rfar[i][a]][i]+dist[i][j]+dist[j][far[j][b]];
							seq[0]=rfar[i][a];
							seq[1]=i;
							seq[2]=j;
							seq[3]=far[j][b];
						}
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++) printf("%d ",seq[i]);
}

int main()
{
	get2(n,m);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		adj[u].PB(v);
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
	}
	solve();
	return 0;
}
