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

class step
{
public:
	int x1,y1,x2,y2;
	step(int X1=0,int Y1=0,int X2=0,int Y2=0)
	{
		x1=X1;y1=Y1;x2=X2;y2=Y2;
	}
};

class stone
{
public:
	int x,y,id;
	stone(int X=0,int Y=0,int ID=0)
	{
		x=X;y=Y;id=ID;
	}
	bool operator<(const stone & o)
	{
		return x<o.x;
	}
};

const int Maxn=55;

int n,m;
vector<stone> s,t;
bool g[Maxn][Maxn];

bool move(stone & now,stone dest,vector<step> & go)
{
	if(now.x==dest.x&&now.y==dest.y) return false;
	if(now.x==dest.x)
	{
		if(now.y<dest.y)
		{
			for(int i=now.y+1;i<=dest.y;i++)
			{
				if(g[now.x][i]) return false;
			}
			for(int i=now.y+1;i<=dest.y;i++)
			{
				go.PB(step(now.x,i-1,now.x,i));
			}
			g[now.x][now.y]=false;
			now=dest;
			g[now.x][now.y]=true;
			return true;
		}
		else
		{
			for(int i=now.y-1;i>=dest.y;i--)
			{
				if(g[now.x][i]) return false;
			}
			for(int i=now.y-1;i>=dest.y;i--)
			{
				go.PB(step(now.x,i+1,now.x,i));
			}
			g[now.x][now.y]=false;
			now=dest;
			g[now.x][now.y]=true;
			return true;
		}
	}
	if(now.y==dest.y)
	{
		if(now.x<dest.x)
		{
			for(int i=now.x+1;i<=dest.x;i++)
			{
				if(g[i][now.y]) return false;
			}
			for(int i=now.x+1;i<=dest.x;i++)
			{
				go.PB(step(i-1,now.y,i,now.y));
			}
			g[now.x][now.y]=false;
			now=dest;
			g[now.x][now.y]=true;
			return true;
		}
		else
		{
			for(int i=now.x-1;i>=dest.x;i--)
			{
				if(g[i][now.y]) return false;
			}
			for(int i=now.x-1;i>=dest.x;i--)
			{
				go.PB(step(i+1,now.y,i,now.y));
			}
			g[now.x][now.y]=false;
			now=dest;
			g[now.x][now.y]=true;
			return true;
		}
	}
}

vector<step> solve(vector<stone> & v)
{
	vector<step> ret;ret.clear();
	clean(g,false);
	for(int i=0;i<m;i++)
	{
		g[v[i].x][v[i].y]=true;
	}
	sort(all(v));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(move(v[j],stone(j+1,v[j].y,v[j].id),ret)) break;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(move(v[j],stone(j+1,v[j].id,v[j].id),ret)) break;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(move(v[j],stone(v[j].id,v[j].id,v[j].id),ret)) break; 
		}
	}
	return ret;
}


int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		s.PB(stone(x,y,i));
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		t.PB(stone(x,y,i));
	}
	vector<step> ans1=solve(s);
	vector<step> ans2=solve(t);
	reverse(all(ans2));
	int k=ans1.size()+ans2.size();
	printf("%d\n",k);
	for(auto v:ans1)
	{
		printf("%d %d %d %d\n",v.x1,v.y1,v.x2,v.y2);
	}
	for(auto v:ans2)
	{
		printf("%d %d %d %d\n",v.x2,v.y2,v.x1,v.y1);
	}
	return 0;
}
