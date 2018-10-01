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

int n,p,k;
int sum[2][Maxn];
int dp[Maxn][Maxn];

int main()
{
	scanf("%d%d%d",&n,&p,&k);
	int r,s;
	scanf("%d",&r);
	for(int i=1;i<=r;i++)
	{
		int x;
		scanf("%d",&x);
		sum[0][x]=1;
	}
	scanf("%d",&s);
	for(int i=1;i<=s;i++)
	{
		int x;
		scanf("%d",&x);
		sum[1][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		sum[0][i]+=sum[0][i-1];
		sum[1][i]+=sum[1][i-1];
	}
	for(int i=1;i<=p;i++)
	{
		
	}
	return 0;
}
