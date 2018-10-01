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
typedef pair<ll,int> pli;

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=1e5+5;
const int D=1500;
const int M=70;

class line
{
	public:
		ll k,b;
		int id;
		bool operator<(const line &o)const
		{
			return (k<o.k||(k==o.k&&b>o.b));
		}
		bool operator==(const line &o)const
		{
			return (k==o.k&&b==o.b);
		}
		line operator-(const line &o)const
		{
			return line{k-o.k,b-o.b};
		}
		ll operator*(const line &o)const
		{
			return k*o.b-b*o.k;
		}
		ll val(int x)
		{
			return k*x+b;
		}
		void read()
		{
			scanf("%lld%lld",&b,&k);
		}
};

int n,q;
line l[Maxn];
vector<line> v[M];
vector<line> hull[M];

bool check(line l1,line l2,line l3)
{
	line x=l3-l1,y=l2-l1;
	return (x*y<=0);
}

void insert(int id,line o)
{
	if(hull[id].size()==1)
	{
		if(hull[id][0].k==o.k) return;
	}
	int m=hull[id].size()-1,l=m-1;
	while(m>0)
	{
		if(check(hull[id][l],hull[id][m],o))
		{
			hull[id].pop_back();
			m--;
			l--;
		}
		else break;
	}
	hull[id].PB(o);
}

pli calc(int id,int x)
{
	int ub=hull[id].size(),lb=0,mi;
	while(ub-lb>1)
	{
		mi=(ub+lb)>>1;
		if(mi&&(hull[id][mi-1].val(x)>hull[id][mi].val(x))) ub=mi;
		else lb=mi;
	}
	return pli(hull[id][lb].val(x),hull[id][lb].id);
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		l[i].read();
		l[i].id=i;
	}
	for(int i=1;i<=n;i++)
	{
		v[i/D].PB(l[i]);
	}
	for(int i=0;i<M;i++)
	{
		sort(v[i].begin(),v[i].end());
		for(auto vv:v[i])
		{
			insert(i,vv);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int lp,rp,t;
		scanf("%d%d%d",&lp,&rp,&t);
		int L=lp/D,R=rp/D;
		ll ans=0,id;
		if(L==R)
		{
			for(int k=lp;k<=rp;k++)
			{
				ll tmp=l[k].val(t);
				if(tmp>ans)
				{
					ans=tmp;
					id=k;
				}
			}
		}
		else
		{
			for(int k=L+1;k<R;k++)
			{
				pli tmp=calc(k,t);
				if(tmp.FF>ans)
				{
					ans=tmp.FF;
					id=tmp.SS;
				}
			}
			int b1=(L+1)*D,b2=R*D;
			for(int k=lp;k<b1;k++)
			{
				ll tmp=l[k].val(t);
				if(tmp>ans)
				{
					ans=tmp;
					id=k;
				}
			}
			for(int k=b2;k<=rp;k++)
			{
				ll tmp=l[k].val(t);
				if(tmp>ans)
				{
					ans=tmp;
					id=k;
				}
			}
		}
		printf("%lld\n",id);
	}
	return 0;
}
