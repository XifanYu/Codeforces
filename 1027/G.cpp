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
typedef pair<ll,int> pli;
typedef double db;

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


vector<ll> d; //store the divisors of m

ll mult(ll a,ll b,ll md) //replace normal multiflication when a*b might cause overflow
{
	a=a%md;
	ll ret=0;
	while(b)
	{
		if(b&1) 
		{
			ret+=a;
			if(ret>=md) ret-=md;
		}
		a+=a;
		if(a>=md) a-=md;
		b=(b>>1);
	}
	return ret;
}

ll gcd(ll a,ll b)
{
	return a?gcd(b%a,a):b;
}

ll qpow(ll x,ll k,ll md)
{
    ll ret=1;
	while(k)
	{
	   if(k&1)	
	   {
	   	 ret=mult(ret,x,md);
	   }
	   x=mult(x,x,md);
	   k=(k>>1);
	}
	return ret;	
}

bool witness(ll a,ll n)
{
    ll m=n-1;
    int j=0;
    while(!(m&1))
    {
        j++;
        m=(m>>1);
    }
    ll x=qpow(a,m,n);
    if(x==1||x==n-1) return false; // n may be prime
    while(--j)
    {
        x=mult(x,x,n);
        if(x==n-1) return false;
    }
    return true; //n must be composite
}

bool miller_rabin(ll n,int T=10)
{
    if(n<2) return false;
    if(n==2) return true;
    if(!(n&1)) return false;
    while(T--)
    {
        ll a=rand()%(n-1)+1; //[1,n-1]
        if(witness(a,n)) return false;
    }
    return true;
}

ll c;

ll func(ll x,ll n)
{
	return (mult(x,x,n)+c)%n;
}

ll pollard_rho(ll n)
{
    ll a=rand()%(n-1)+1; //[1,n-1]
    ll b=a;
    ll d=1;
    while(d==1)
    {
        a=func(a,n);
        b=func(func(b,n),n);
        d=gcd(abs(a-b),n);
    }
    if(d==n) return -1;
    return d;
}

void combine_fac(set<pli> & x,set<pli> & y)
{
	set<pli>::iterator it1=x.begin(),it2=y.begin(),tp;
	while(it1!=x.end()&&it2!=y.end())
	{
		if(it1->FF<it2->FF) it1++;
		else if(it1->FF>it2->FF)
		{
			tp=it2++;
			x.insert(*tp);
		}
		else
		{
			pli add=pli(it1->FF,it1->SS+it2->SS);
			tp=it1++;
			x.erase(tp);
			x.insert(add);
			it2++;
		}
	}
	while(it2!=y.end())
	{
		tp=it2++;
		x.insert(*tp);
	}
}

set<pli> factorize(ll n)
{
	set<pli> divs;
	divs.clear();
	int cnt=0;
	while(!(n&1))
	{
		cnt++;
		n=(n>>1);
	}
	if(cnt) divs.insert(pli(2,cnt));
	while(n>1)
	{
		if(miller_rabin(n))
		{
			set<pli> tmp;tmp.clear();
			tmp.insert(pli(n,1));
			combine_fac(divs,tmp);
			return divs;
		}
		ll d=-1;
		c=100;
		while(d<0)
		{
			d=pollard_rho(n);
			c--;
		}
		while(n%d==0)
		{
			set<pli> tmp=factorize(d);
			combine_fac(divs,tmp);
			n/=d;
		}
	}
	return divs;
}

pair<ll,set<pli>> phi(ll n) //calculate euler function of n and return the factorization of phi(n) at the same time
{
    set<pli> tmp=factorize(n),ret;ret.clear();
    vector<set<pli>> q;q.clear();
    ll p=n;
    for(auto & v:tmp)
    {
    	q.PB(factorize(v.FF-1));
    	p-=p/v.FF;
    	if(v.SS>1) ret.insert(pli(v.FF,v.SS-1));
	}
	for(auto & v:q)
	{
		combine_fac(ret,v);
	}
	return MP(p,ret);
}


ll m,x;

int main()
{
	srand(time(NULL));   
	scanf("%lld%lld",&m,&x);
	d.clear();
	
	//search for all divisors
	for(ll i=1;i*i<=m;i++)
	{
		if(m%i==0)
		{
			d.PB(i);
		}
	}
	for(int i=d.size()-1;i>=0;i--)
	{
		if(m/d[i]!=d[i]) d.PB(m/d[i]);
	}
	
	//for each v|m, ans+=phi(v)/ord(v);
	ll ans=0;
	for(auto v:d)
	{
		auto now=phi(v);
		ll pv=now.FF;
		set<pli> pf=now.SS;
		ll ord=pv;
		for(auto u:pf)
		{
			for(int i=1;i<=u.SS;i++) ord/=u.FF;
			ll cp=qpow(x,ord,v);
			while(cp!=1)
			{
				ord*=u.FF;
				cp=qpow(cp,u.FF,v);
			}
		}
		ans+=pv/ord;
	}
	printf("%lld\n",ans);
	return 0;
}
