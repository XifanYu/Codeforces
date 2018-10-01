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

/*
 * high precision: cout<<fixed<<setprecision(10)<<;
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=5e5+5;

int n,m,q;
int pa[Maxn];

int find(int x)
{
	if(x==pa[x]) return x;
	return pa[x]=find(pa[x]);
}

bool uni(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy) return false;
	pa[fx]=fy;
	return true;
}

class edge
{
	public:
		int u,v,w;
		int to(int x)
		{
			if(x==u) return v;
			return u;
		}
		bool operator<(const edge &o)const
		{
			return w<o.w;
		}
		void init()
		{
			scanf("%d%d%d",&u,&v,&w);
		}
		void update()
		{
			uni(u,v);
		} 
};


edge e[Maxn];
bool f[Maxn];



class subquery
{
	public:
		int w,id;
		vector<pi> v;
		bool operator<(const subquery &o)const
		{
			return w<o.w;
		}
		void check()
		{
			vector<int> pre;
			vector<pi> ps;
			int it=0;
			for(auto p:v)
			{
				int x=find(p.FF),y=find(p.SS);
				pre.PB(x);
				pre.PB(y);
				ps.PB(pi(x,y));
			}
			for(auto p:ps)
			{
				if(uni(p.FF,p.SS));
				else f[id]=false;
			}
			for(auto p:pre)
			{
				pa[p]=p;
			}
		}
};

int sz=-1;
vector<subquery> sq;

class query
{
	public:
		int k,id;
		vector<edge> d;
		subquery sub(int x,int y)
		{
			subquery t;
			t.w=x;
			t.id=y;
			t.v.clear();
			return t;
		}
		void init()
		{
			scanf("%d",&k);
			d.resize(k);
			int x;
			rep0(i,k)
			{
				scanf("%d",&x);
				d[i]=e[x];
			}
			sort(d.begin(),d.end());
			int it=0,w=-1;
			while(it<k)
			{
				while(it<k&&d[it].w==w)
				{
					sq[sz].v.PB(pi(d[it].u,d[it].v));
					it++;
				}
				if(it<k)
				{
					w=d[it].w;
					sq.PB(sub(w,id));
					sq[++sz].v.PB(pi(d[it].u,d[it].v));
					it++;
				}
			}
		}
};


int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)
	{
		pa[i]=i;
	}
	rep(i,m)
	{
		e[i].init();
	}
	scanf("%d",&q);
	query que;
	rep(i,q)
	{
		que.id=i;
		que.init();
	}
	sort(sq.begin(),sq.end());
	sort(e+1,e+m+1);
	memset(f,1,sizeof f);
	int it=1;
	for(int i=0;i<=sz;i++)
	{
		while(e[it].w<sq[i].w)
		{
			e[it++].update();
		}
		sq[i].check();
	}
	rep(i,q)
	{
		if(f[i])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
