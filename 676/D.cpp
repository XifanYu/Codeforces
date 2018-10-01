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
typedef pair<pi,int> pii; 
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

const int Maxn=1e3+5;
const int INF=0x3f3f3f3f;

int dist[Maxn][Maxn][4]; //x, y, state
bool go[Maxn][Maxn][4]; //x, y, dir(0-up, 1-right, 2-down, 3-left)
bool con[Maxn][Maxn][4][4]; //x, y, state, dir
char s[Maxn][Maxn];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int n,m;

void build()
{
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) s[i][0]=s[i][m+1]='*';
	for(int i=1;i<=m;i++) s[0][i]=s[n+1][i]='*';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='*') continue;
			if(s[i][j]=='+')
			{
				go[i][j][0]=go[i][j][1]=go[i][j][2]=go[i][j][3]=true;
			}
			else if(s[i][j]=='-')
			{
				go[i][j][1]=go[i][j][3]=true;
			}
			else if(s[i][j]=='|')
			{
				go[i][j][0]=go[i][j][2]=true;
			}
			else if(s[i][j]=='^')
			{
				go[i][j][0]=true;
			}
			else if(s[i][j]=='>')
			{
				go[i][j][1]=true;
			}
			else if(s[i][j]=='v')
			{
				go[i][j][2]=true;
			}
			else if(s[i][j]=='<')
			{
				go[i][j][3]=true;
			}
			else if(s[i][j]=='U')
			{
				go[i][j][1]=go[i][j][2]=go[i][j][3]=true;
			}
			else if(s[i][j]=='R')
			{
				go[i][j][0]=go[i][j][2]=go[i][j][3]=true;
			}
			else if(s[i][j]=='D')
			{
				go[i][j][0]=go[i][j][1]=go[i][j][3]=true;
			}
			else if(s[i][j]=='L')
			{
				go[i][j][0]=go[i][j][1]=go[i][j][2]=true;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int state=0;state<4;state++)
			{
				for(int dir=0;dir<4;dir++)
				{
					int ni=i+dx[dir],nj=j+dy[dir];
					if(go[i][j][(4+dir-state)%4]&&go[ni][nj][(6+dir-state)%4])
					{
						con[i][j][state][dir]=true;
					}
				}
			}
		}
	}
}

int solve()
{
	int sx,sy,ex,ey;
	get2(sx,sy);get2(ex,ey);
	clean(dist,0x3f);
	dist[sx][sy][0]=0;
	queue<pii> q;
	q.push(pii(pi(sx,sy),0));
	while(!q.empty())
	{
		pii now=q.front();
		q.pop();
		int x=now.FF.FF,y=now.FF.SS,state=now.SS,dis=dist[x][y][state];
		if(dist[x][y][(state+1)%4]>dis+1)
		{
			dist[x][y][(state+1)%4]=dis+1;
			q.push(pii(pi(x,y),(state+1)%4));
		}
		for(int i=0;i<4;i++)
		{
			if(con[x][y][state][i])
			{
				int nx=x+dx[i],ny=y+dy[i];
				if(dist[nx][ny][state]>dis+1)
				{
					dist[nx][ny][state]=dis+1;
					q.push(pii(pi(nx,ny),state));
				}
			}
		}
	}
	int ret=INF;
	for(int i=0;i<4;i++) ret=min(ret,dist[ex][ey][i]);
	if(ret==INF) return -1;
	return ret;
}

int main()
{
	get2(n,m);
	build();
	int ans=solve();
	printf("%d\n",ans);
	return 0;
}
