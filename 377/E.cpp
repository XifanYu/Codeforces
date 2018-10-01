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

const int Maxn=2e5+5;

class line
{
	public:
		ll k,b;
		bool operator<(const line &o)const
		{
			return (k<o.k||(k==o.k&&b>o.b)); //upper hull-max value
		}
		bool operator==(const line &o)const
		{
			return (k==o.k&&b==o.b);
		}
		line operator-(const line &o)const
		{
			return line{k-o.k,b-o.b};
		}
		db operator*(const line &o)const
		{
			return 1.0*k*o.b-1.0*b*o.k;
		}
		db tim(ll x)
		{
			return 1.0*(x-b)/k;
		}
		ll val(ll t)
		{
			return k*t+b;
		}
};

int n;
ll s;
pi b[Maxn];
vector<line> hull;

bool check(line l1,line l2,line l3)
{
	line x=l3-l1,y=l2-l1;
	return (x*y<=0);
}

void insert(line o)
{
	if(hull.size()==1)
	{
		if(hull[0].k==o.k) return;
	}
	int m=hull.size()-1,l=m-1;
	while(m>0)
	{
		if(check(hull[l],hull[m],o))
		{
			hull.pop_back();
			m--;
			l--;
		}
		else break;
	}
	hull.PB(o);
}

db find(ll c)
{
	int ub=hull.size(),lb=0,mi;
	while(ub-lb>1)
	{
		mi=(ub+lb)>>1;
		if(mi&&hull[mi].tim(c)>hull[mi-1].tim(c)) ub=mi;
		else lb=mi;
	}
	return hull[lb].tim(c);
}

ll calc(int t)
{
	int ub=hull.size(),lb=0,mi;
	while(ub-lb>1)
	{
		mi=(ub+lb)>>1;
		if(mi&&hull[mi].val(t)<hull[mi-1].val(t)) ub=mi;
		else lb=mi;
	}
	return hull[lb].val(t);
}

int main()
{
	scanf("%d%lld",&n,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&b[i].FF,&b[i].SS);
	}
	sort(b+1,b+n+1);
	int id;
	for(id=n;b[id].SS!=0;id--);
	insert(line{(ll)b[id].FF,(ll)b[id].SS});
	for(int i=id+1;i<=n;i++)
	{
		db tim=find(b[i].SS);
		ll t=(tim>(ll)tim)?(ll)tim+1:(ll)tim;
		ll val=calc(t);
		insert(line{(ll)b[i].FF,(ll)val-b[i].SS-t*b[i].FF});
	}
	db tim=find(s);
	ll t=(tim>(ll)tim)?(ll)tim+1:(ll)tim;
	printf("%lld\n",t);
	return 0;
}
