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

int n;
vector<int> adj[Maxn];
bool used[Maxn];
int a[Maxn];

void fail()
{
	printf("No\n");
	exit(0);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].PB(y);
		adj[y].PB(x);
	}
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	if(a[1]!=1)
	{
		fail();
	}
	used[a[1]]=true;
	for(int i=1,j=1;i<=n;i++)
	{
		int x=adj[a[i]].size();
		if(i!=1) x--;
		for(int k=1;k<=x;k++)
		{
			used[a[j+k]]=true;
		}
		j+=x;
		for(auto v:adj[a[i]])
		{
			if(!used[v]) fail();
		}
	}
	printf("Yes\n");
	return 0;
}
