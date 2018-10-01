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

const int Maxn=2005;
const int inf=Maxn*20;

int n;
int a[Maxn],b[Maxn];
int dp[Maxn][10][10][10][10];//now,floor,dest1,dest2,dest3

int dfs(int now,int f,int i,int j,int k)
{
	if(dp[now][f][i][j][k]!=-1) return dp[now][f][i][j][k];
	if(now>n)
	{
		if(!i&&!j&&!k) return dp[now][f][i][j][k]=0;
		int rez=inf;
		if(i) rez=min(rez,dfs(now,i,0,j,k)+abs(i-f));
		if(j) rez=min(rez,dfs(now,j,i,0,k)+abs(j-f));
		if(k) rez=min(rez,dfs(now,k,i,j,0)+abs(k-f));
		return dp[now][f][i][j][k]=rez;
	}
	int rez=inf,na=a[now],nb=b[now];
	if(i) rez=min(rez,dfs(now,i,0,j,k)+abs(i-f));
	if(j) rez=min(rez,dfs(now,j,i,0,k)+abs(j-f));
	if(k) rez=min(rez,dfs(now,k,i,j,0)+abs(k-f));
	if(!i) rez=min(rez,dfs(now+1,na,nb,j,k)+abs(na-f));
	else if(!j) rez=min(rez,dfs(now+1,na,i,nb,k)+abs(na-f));
	else if(!k) rez=min(rez,dfs(now+1,na,i,j,nb)+abs(na-f));
	else
	{
		rez=min(rez,dfs(now+1,nb,i,j,k)+abs(na-f)+abs(nb-na));
		rez=min(rez,dfs(now+1,i,nb,j,k)+abs(na-f)+abs(i-na));
		rez=min(rez,dfs(now+1,j,i,nb,k)+abs(na-f)+abs(j-na));
		rez=min(rez,dfs(now+1,k,i,j,nb)+abs(na-f)+abs(k-na));
	}
	return dp[now][f][i][j][k]=rez;
}

int solve()
{
	memset(dp,-1,sizeof dp);
	return dfs(1,1,0,0,0)+2*n;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",a+i,b+i);
	int ans=solve();
	printf("%d\n",ans);
	return 0;
}
