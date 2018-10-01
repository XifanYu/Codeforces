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

const int Maxn=505;
const int md=998244353;

int n,k;
int dp[Maxn][Maxn];//dp[i][j], number of string of length j with maximum segment of length less than or equal to i
int sum[Maxn][Maxn];//sum[i][j]=dp[i][1]+...+dp[i][j]

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=1;
		sum[i][1]=1;
		for(int j=2;j<=n;j++)
		{
			dp[i][j]=sum[i][j-1];
			if(j-i>0) dp[i][j]=(dp[i][j]-sum[i][j-i-1]+md)%md;
			else dp[i][j]=(dp[i][j]+1)%md;
			sum[i][j]=(sum[i][j-1]+dp[i][j])%md;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i*j>=k) break;
			ans=(ans+(ll)(dp[i][n]-dp[i-1][n]+md)*(dp[j][n]-dp[j-1][n]+md))%md;
		}
	}
	ans=(ans*2)%md;
	printf("%lld\n",ans);
	return 0;
}
