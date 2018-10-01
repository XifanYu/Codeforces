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

const int Maxn=1e6+5;

int n;
char a[Maxn],b[Maxn];
int dp[Maxn][4][4];

int dfs(int cur,int x,int y)
{
	if(dp[cur][x][y]!=-1) return dp[cur][x][y];
	if(cur==n-1)
	{
		if(x==y) return dp[cur][x][y]=0;
		else if(x==0&&y==3) return dp[cur][x][y]=2;
		else if(x==3&&y==0) return dp[cur][x][y]=2;
		else return dp[cur][x][y]=1;
	}
	int ret=0x3f3f3f3f;
	ret=min(ret,dfs(cur+1,(x%2)*2+a[cur+1],(y%2)*2+b[cur+1])+((x/2)!=(y/2)));
	ret=min(ret,dfs(cur+1,(x/2)*2+a[cur+1],(y%2)*2+b[cur+1])+((x%2)!=(y/2))+1);
	return dp[cur][x][y]=ret;
}

int main()
{
	scanf("%d",&n);
	scanf("%s%s",a,b);
	if(n==1)
	{
		if(a[0]!=b[0]) printf("1\n");
		else printf("0\n");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		a[i]-='0';
		b[i]-='0';
	}
	clean(dp,-1);
	int ans=dfs(1,a[0]*2+a[1],b[0]*2+b[1]);
	printf("%d\n",ans);
	return 0;
}
