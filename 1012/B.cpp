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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
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

class pnt
{
public:
	int x,y,id;
	bool operator<(const pnt & o)const
	{
		return x<o.x||(x==o.x&&y<o.y);
	}	
	void read()
	{
		scanf("%d%d",&x,&y);
	}
};

const int Maxn=2e5+5; 

int n,m,q;
ll cnt=0;
pnt p[Maxn];
bool used[Maxn];
bool visx[Maxn];
bool visy[Maxn];
vector<int> adjx[Maxn];
vector<int> adjy[Maxn];
int w,h;
int totw=0,toth=0;

void dfs(int id)
{
	used[id]=true;
	if(!visx[p[id].x])
	{
		visx[p[id].x]=true;
		w++;
		for(auto v:adjx[p[id].x])
		{
			if(!used[v])
			{
				dfs(v);
			}
		}
	}
	if(!visy[p[id].y])
	{
		visy[p[id].y]=true;
		h++;
		for(auto v:adjy[p[id].y])
		{
			if(!used[v])
			{
				dfs(v);
			}
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		p[i].read();
		adjx[p[i].x].PB(i);
		adjy[p[i].y].PB(i);
	}
	for(int i=1;i<=q;i++)
	{
		if(!used[i])
		{
			w=h=0;
			dfs(i);
			if(totw) cnt++;
			totw+=w;
			toth+=h;
		}
	}
	if(totw==0)
	{
		cnt+=n+m-1;
	}
	else
	{
		cnt+=(n-totw)+(m-toth);
	}
	printf("%lld\n",cnt);
	return 0;
}
