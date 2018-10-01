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

const int md=1e9+7;
const int Maxn=5005;

int n,k;
ll dp[Maxn][Maxn];//dp[i][j]: the ways of choosing a combination of size i with repetition among j distinct people (must choose every people at least once)

int main()
{
	scanf("%d%d",&n,&k);
	dp[0][0]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1]*(n-j+1))%md;
		}
	}
	ll ans=0;
	for(int i=1;i<=min(n,k);i++)
	{
		ans=(ans+dp[k][i]*qpow(2,n-i))%md;
	}
	printf("%lld\n",ans);
	return 0;
}
