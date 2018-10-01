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

const int Maxn=2e5+5;

typedef pair<pi,int> ppi;

int n,m,k;
int r[Maxn];
int deg[Maxn];
vector<int> adj[Maxn];
vector<int> radj[Maxn];
int a[Maxn],b[Maxn];
int seq[Maxn],cnt=0;
bool have[Maxn];

void fail()
{
	puts("-1");
	exit(0);
}

int main()
{
	clean(a,-1);
	clean(b,-1);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",r+i);
		if(r[i]) 
		{
			have[r[i]]=true;
			a[i]=b[i]=r[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		radj[y].PB(x);
		adj[x].PB(y);
		deg[x]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0) q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		seq[cnt++]=x;
		for(auto v:radj[x])
		{
			deg[v]--;
			if(deg[v]==0) q.push(v);
		}
	}
	if(cnt!=n) fail();
	for(int i=0;i<n;i++)
	{
		if(a[seq[i]]==-1) a[seq[i]]=1;
		for(auto v:radj[seq[i]])
		{
			if(r[v]) continue;
			if(a[v]==-1||a[v]<a[seq[i]]+1) a[v]=a[seq[i]]+1;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		if(b[seq[i]]==-1) b[seq[i]]=k;
		for(auto v:adj[seq[i]])
		{
			if(r[v]) continue;
			if(b[v]==-1||b[v]>b[seq[i]]-1) b[v]=b[seq[i]]-1;
		}
	}
	set<ppi> s1,s2;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i]) fail();
		if(r[i]) continue;
		s1.insert(ppi(pi(a[i],b[i]),i));
	}
	for(int i=1;i<=k;i++)
	{
		while(!s1.empty()&&(*s1.begin()).FF.FF==i)
		{
			s2.insert(ppi(pi((*s1.begin()).FF.SS,(*s1.begin()).FF.FF),(*s1.begin()).SS));
			s1.erase(s1.begin());
		}
		bool flag=false;
		while(!s2.empty()&&(*s2.begin()).FF.FF==i)
		{
			flag=true;
			r[(*s2.begin()).SS]=i;
			have[i]=true;
			s2.erase(s2.begin());
		}
		if(!s2.empty()&&!have[i])
		{
			r[(*s2.begin()).SS]=i;
			have[i]=true;
			s2.erase(s2.begin());
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(!have[i]) fail();
	}
	for(int i=1;i<=n;i++)
	{
		if(!r[i]) fail();
	}
	for(int i=1;i<=n;i++)
	{
		for(auto v:adj[i])
		{
			if(r[v]>=r[i]) fail();
		}
		for(auto v:radj[i])
		{
			if(r[v]<=r[i]) fail();
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",r[i]);
	}
	puts("");
	return 0;
}
