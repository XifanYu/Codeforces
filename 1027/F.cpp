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

const int Maxn=1e6+5;
const int inf=0x3f3f3f3f;

class edge
{
public:
	int to,nxt;
	edge(int a=0,int b=0)
	{
		to=a;nxt=b;
	}
};

int n;
vector<int> d;
map<int,int> mp;
pi p[Maxn];
edge e[Maxn<<1];
int head[Maxn<<1];
bool vis[Maxn<<1];
bool used[Maxn<<1];
int m;
int stk[Maxn<<1],cur;
int cnt;

void fail()
{
	printf("-1\n");
	exit(0);
}

void dfs(int now)
{
	used[now]=true;
	stk[cur++]=now;
	for(int i=head[now];i;i=e[i].nxt)
	{
		if(vis[i]) continue;
		int go=e[i].to;
		cnt++;
		vis[i]=vis[i^1]=true;
		if(!used[go]) 
		{
			dfs(go);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		d.PB(a);d.PB(b);
		p[i]=pi(a,b);
	}
	sort(all(d));
	d.resize(unique(all(d))-d.begin());
	m=d.size();
	for(int i=0;i<m;i++) mp[d[i]]=i;
	for(int i=1;i<=n;i++)
	{
		int a=mp[p[i].FF],b=mp[p[i].SS];
		e[(i<<1)]=edge(b,head[a]);
		head[a]=(i<<1);
		e[(i<<1)|1]=edge(a,head[b]);
		head[b]=((i<<1)|1);
	}
	clean(used,false);
	clean(vis,false);
	int ans=0;
	for(int i=0;i<m;i++)
	{
		if(!used[i])
		{
			cnt=0;
			cur=0;
			dfs(i);
			if(cnt>cur) fail();
			if(cnt==cur)
			{
				for(int i=0;i<cur;i++)
				{
					ans=max(ans,d[stk[i]]);
				}
			}
			else
			{
				int maxt=0,maxid;
				for(int i=0;i<cur;i++)
				{
					if(d[stk[i]]>maxt)
					{
						maxt=d[stk[i]];
						maxid=i;
					}
				}
				for(int i=0;i<cur;i++)
				{
					if(i==maxid) continue;
					ans=max(ans,d[stk[i]]);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
