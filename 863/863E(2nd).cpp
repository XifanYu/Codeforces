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

const int Maxn=2e5+5;

class seg
{
	public:
		int l,r,id;
		void read(int i)
		{
			scanf("%d%d",&l,&r);
			id=i;
		}
		bool operator<(const seg&o)const
		{
			return (l<o.l)||(l==o.l&&r>o.r);
		}
};

int n;
seg s[Maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		s[i].read(i);
	}
	sort(s+1,s+n+1);
	for(int i=2;i<=n;i++)
	{
		if(s[i-1].r>=s[i].r)
		{
			printf("%d\n",s[i].id);
			return 0;
		}
	}
	for(int i=2;i<n;i++)
	{
		if(s[i-1].r+1>=s[i+1].l&&s[i+1].r>=s[i].r)
		{
			printf("%d\n",s[i].id);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
