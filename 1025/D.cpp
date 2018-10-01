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

const int Maxn=705;

int n;
int a[Maxn];
bool e[Maxn][Maxn];
bool dp[Maxn][Maxn][2];
bool vis[Maxn][Maxn][2];


int gcd(int x,int y)
{
	return x?gcd(y%x,x):y;
}

bool dfs(int l,int r,int dir)
{
	if(vis[l][r][dir]) return dp[l][r][dir];
	vis[l][r][dir]=true;
	int x=dir?r+1:l-1;
	bool ret=false;
	for(int i=l;i<=r;i++)
	{
		if(e[x][i])
		{
			if((i==l||dfs(l,i-1,1))&&(i==r||dfs(i+1,r,0)))
			{
				ret=true;
				break;
			}
		}
	}
	return dp[l][r][dir]=ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(gcd(a[i],a[j])>1)
			{
				e[i][j]=e[j][i]=true;
			}
		}
	}
	bool ans=dfs(1,n,0);
	if(ans) printf("Yes\n");
	else printf("No\n");
	return 0;
}
