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

db s[Maxn<<1];
db sum[Maxn<<1];
int n,q;
db sy,a,b;

db calc(db l,db r)
{
	int lb=upper_bound(s+1,s+2*n+1,l)-s-1;
	int ub=lower_bound(s+1,s+2*n+1,r)-s;
	db ret=0.0;
	if(ub-lb==1)
	{
		if(lb&1) ret+=r-l;
		return ret;
	}
	if(lb&1)
	{
		ret+=s[lb+1]-l;
	}
	if(!(ub&1))
	{
		ret+=r-s[ub-1];
	}
	ret+=sum[ub-1]-sum[lb+1];
	return ret;
}

int main()
{
	scanf("%lf%lf%lf",&sy,&a,&b);
	sy=-sy;
	scanf("%d",&n);
	sum[0]=0.0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",s+2*i-1,s+2*i);
		sum[2*i-1]=sum[2*i-2];
		sum[2*i]=sum[2*i-1]+s[2*i]-s[2*i-1];
	}
	scanf("%d",&q);
	while(q--)
	{
		db x,y;
		scanf("%lf%lf",&x,&y);
		db na=(a*y+x*sy)/(y+sy),nb=(b*y+x*sy)/(y+sy);
		db ans=calc(na,nb)*(y+sy)/y;
		printf("%.8lf\n",ans);
	}
	return 0;
}
