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

const int Maxn=3e5+5;

int n,k,d;
int p[Maxn];
bool vis[Maxn];
bool del[Maxn];
vector<pi> adj[Maxn];
int ans;

int main()
{
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=k;i++) scanf("%d",p+i);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].PB(pi(v,i));
		adj[v].PB(pi(u,i));
	}
	queue<pi> q;
	for(int i=1;i<=k;i++)
	{
		if(!vis[p[i]])
		{
			q.push(pi(p[i],-1));
			vis[p[i]]=true;
		}
	}
	while(!q.empty())
	{
		pi now=q.front();
		int cur=now.FF,pre=now.SS;
		q.pop();
		for(auto v:adj[cur])
		{
			int nex=v.FF;
			if(nex!=pre)
			{
				if(!vis[nex])
				{
					q.push(pi(nex,cur));
					vis[nex]=true;	
				}
				else
				{
					int id=v.SS;
					del[id]=true;
					ans++;
				}
			}
		}
	}
	ans=(ans>>1);
	printf("%d\n",ans);
	for(int i=1;i<n;i++)
	{
		if(del[i]) printf("%d ",i);
	}
	return 0;
}
