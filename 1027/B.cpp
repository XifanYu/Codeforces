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

int n,q;

int main()
{
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if((x+y)%2)
		{
			ll ans=(ll)n*n-(ll)n*n/2;
			int row=(x-1)/2;
			ans+=(ll)row*n;
			if(x&1) ans+=(ll)y/2;
			else ans+=(ll)n/2+(ll)(y+1)/2;
			printf("%lld\n",ans);
		}
		else
		{
			ll ans=0;
			int row=(x-1)/2;
			ans+=(ll)row*n;
			if(x&1) ans+=(ll)(y+1)/2;
			else ans+=ll(n+1)/2+(ll)y/2;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
