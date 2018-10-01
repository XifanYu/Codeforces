#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;

ll qpow(ll x,ll k,ll mod)
{
    ll ret=1;
	while(k)
	{
	   if(k&1)	
	   {
	   	 ret=ret*x;
	   	 ret=ret%mod;
	   }
	   x=x*x;
	   x=x%mod;
	   k=(k>>1);
	}
	return ret;	
}
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

const int Maxn=2e5+5;

int n,a[Maxn];
vector<pi> ss[3];
bool vis[Maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",a+i);
		if(a[i]==0) ss[0].PB(pi(0,i));
		if(a[i]>0) ss[1].PB(pi(a[i],i));
		if(a[i]<0) ss[2].PB(pi(a[i],i));
	}
	if(n==1) return 0;
	sort(all(ss[1]));
	sort(all(ss[2]));
	int l0=ss[0].size(),l1=ss[1].size(),l2=ss[2].size();
	int cnt=0;
	for(auto x:ss[0]) 
	{
		cnt++;
		vis[x.SS]=true;
	}
	if(l2%2)
	{
		cnt++;
		vis[ss[2][l2-1].SS]=true;
	}
	if(cnt==n)
	{
		if(a[1]==0)
		{
			for(int i=2;i<n;i++) printf("1 %d %d\n",i,i+1);
			printf("2 %d\n",n);
		}
		else
		{
			for(int i=1;i<n-1;i++) printf("1 %d %d\n",i,i+1);
			printf("2 %d\n",n-1);
		}
	}
	else
	{
		queue<int> q;
		for(int i=1;i<=n;i++) if(vis[i]) q.push(i);
		int now;
		now=0;
		while(!q.empty())
		{
			int nex=q.front();
			q.pop();
			if(now) printf("1 %d %d\n",now,nex);
			now=nex;
		}
		if(now) printf("2 %d\n",now);
		for(int i=1;i<=n;i++) if(!vis[i]) q.push(i);
		now=0;
		while(!q.empty())
		{
			int nex=q.front();
			q.pop();
			if(now) printf("1 %d %d\n",now,nex);
			now=nex;
		}
	}
	return 0;
}
