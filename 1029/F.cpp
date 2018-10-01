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
#include <complex>
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

ll a[3];
vector<ll> d[3];

int main()
{
	scanf("%lld%lld",a+0,a+1);
	a[2]=a[0]+a[1];
	for(int i=0;i<3;i++)
	{
		for(ll j=1;j*j<=a[i];j++)
		{
			if(a[i]%j==0) d[i].PB(j);
		}
	}
	ll ans=(ll)0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<2;i++)
	{
		for(int p1=0,p2=0;p2<d[2].size();p2++)
		{
			while(p1<d[i].size()&&d[i][p1]<=d[2][p2]) p1++;
			p1--;
			if(a[i]/d[i][p1]<=a[2]/d[2][p2])
			{
				ans=min(ans,(ll)2*(d[2][p2]+a[2]/d[2][p2]));
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
