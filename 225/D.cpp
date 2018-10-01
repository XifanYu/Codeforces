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

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=20;

int n,m,l=0;
char s[Maxn][Maxn];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
pi tar;
int mask;

class state
{
public:
	pi head;
	int path;
	bool move(int step)
	{
		int nx=head.FF-dx[step],ny=head.SS-dy[step];
		if(s[nx][ny]=='#') return false;
		int tmp=path,x=head.FF,y=head.SS,go;
		for(int i=1;i<l;i++)
		{
			go=tmp&3;
			x+=dx[go];
			y+=dy[go];
			if(x==nx&&y==ny) return false;
			tmp>>=2;
		}
		return true;
	}
	state get(int step)
	{
		state nex;
		int nx=head.FF-dx[step],ny=head.SS-dy[step];
		nex.head=pi(nx,ny);
		nex.path=((path<<2)+step)&mask;
		return nex;
	}
	bool operator<(const state & o)const
	{
		return (head<o.head)||(head==o.head&&path<o.path);
	}
};

state init(int x,int y)
{
	state ret;
	ret.head=pi(x,y);
	int path=0;
	while(true)
	{
		bool flag=true;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(s[nx][ny]==s[x][y]+1)
			{
				flag=false;
				x=nx;
				y=ny;
				path|=i<<(l<<1);
				break;
			}
		}
		if(flag) break;
		l++;
	}
	mask=(1<<(l<<1))-1;
	ret.path=path;
	return ret;
}

map<state,int> mp;

int main()
{
	scanf("%d%d",&n,&m);
	clean(s,'#');
	for(int i=1;i<=n;i++) 
	{
		scanf("%s",s[i]+1);
		s[i][m+1]='#';
	}
	state S;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='1')
			{
				S=init(i,j);
			}
			if(s[i][j]=='@')
			{
				tar=pi(i,j);
			}
		}
	}
	queue<state> q;
	mp[S]=0;
	q.push(S);
	while(!q.empty())
	{
		state now=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			if(now.move(i))
			{
				state nex=now.get(i);
				if(mp.find(nex)==mp.end())
				{
					mp[nex]=mp[now]+1;
					if(nex.head==tar)
					{
						printf("%d\n",mp[nex]);
						return 0;
					}
					q.push(nex);
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}
