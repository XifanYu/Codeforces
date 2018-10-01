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

const int Maxn=1005;
const int md=998244353;

int n,k;
int dp[Maxn][Maxn<<1][4];
int add[4][4];

int dfs(int now,int cnt,int st)
{
	if(cnt<=0) return 0;
	if(~dp[now][cnt][st]) return dp[now][cnt][st];
	if(now==1)
	{
		if(st==0||st==3)
		{
			if(cnt==1) return dp[now][cnt][st]=1;
			return dp[now][cnt][st]=0;
		}
		else
		{
			if(cnt==2) return dp[now][cnt][st]=1;
			return dp[now][cnt][st]=0;
		}
	}
	int ret=0;
	for(int i=0;i<4;i++)
	{
		(ret+=dfs(now-1,cnt-add[i][st],i))%=md;
	}
	return dp[now][cnt][st]=ret;
}

int main()
{
	scanf("%d%d",&n,&k);
	int ans=0;
	add[0][0]=0;add[0][1]=1;add[0][2]=1;add[0][3]=1;
	add[1][0]=0;add[1][1]=0;add[1][2]=2;add[1][3]=0;
	add[2][0]=0;add[2][1]=2;add[2][2]=0;add[2][3]=0;
	add[3][0]=1;add[3][1]=1;add[3][2]=1;add[3][3]=0;
	clean(dp,-1);
	for(int i=0;i<4;i++)
	{
		(ans+=dfs(n,k,i))%=md;
	}
	printf("%d\n",ans);
	return 0;
}
