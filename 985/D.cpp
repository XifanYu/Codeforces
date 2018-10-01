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

typedef long long ll;
typedef pair<int,int> pi; 
typedef double db; 

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

ll n,h;

bool check(ll x)
{
	ll k=min(h,x);
	ll cnt=x*x-k*(k-1)/2;
	return cnt<=n;
}

ll get(ll x)
{
	ll k=min(h,x);
	ll cnt=x*x-k*(k-1)/2;
	ll len=2*x-k;
	ll res=n-cnt;
	ll ext=(res+x-1)/x;
	return len+ext;
}

int main()
{
	scanf("%lld%lld",&n,&h);
	ll lb=0,ub=2e9,mi;
	while(ub-lb>1)
	{
		mi=(ub+lb)>>1;
		if(check(mi)) lb=mi;
		else ub=mi;
	}
	printf("%lld\n",get(lb));
	return 0;
}
