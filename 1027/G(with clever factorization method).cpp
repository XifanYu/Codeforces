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

const db eps=1e-9;

vector<ll> d; //store the divisors of m
vector<pl> f; //store the factorization of n, which will help us with factorization of the divisors of m later

vector<pl> get_fac(ll x) //use the factorization of m to calculate the factorization of some divisor x of m
{
	vector<pl> ret;ret.clear();
	for(int i=0;i<f.size();i++)
	{
		int cnt=0;
		while(x%f[i].FF==0)
		{
			x/=f[i].FF;
			cnt++; 
		}
		if(cnt) ret.PB(pl(f[i].FF,cnt));
	}
	return ret;
}

map<ll,vector<pl>> mp;

vector<pl> mal_fac(ll x) //manually calculate the factorization of some number, with memorization used
{
	if(mp.count(x)) return mp[x];
	vector<pl> ret;ret.clear();
	ll y=x;
	for(ll i=2;i*i<=x;i++)
	{
		int cnt=0;
		while(x%i==0)
		{
			x/=i;
			cnt++;
		}
		if(cnt) ret.PB(pl(i,cnt));
	}
	if(x>1) ret.PB(pl(x,1));
	return mp[y]=ret;
}

vector<pl> combine(vector<pl> & f1,vector<pl> & f2) //combine two factorizations
{
	int i1=0,i2=0;
	vector<pl> ret;ret.clear();
	while(i1<f1.size()&&i2<f2.size())
	{
		if(f1[i1].SS==0) i1++;
		else if(f2[i2].SS==0) i2++;
		else if(f1[i1].FF<f2[i2].FF)
		{
			ret.PB(f1[i1]);
			i1++;
		}
		else if(f1[i1].FF>f2[i2].FF)
		{
			ret.PB(f2[i2]);
			i2++;
		}
		else
		{
			ret.PB(pl(f1[i1].FF,f1[i1].SS+f2[i2].SS));
			i1++;i2++;
		}
	}
	while(i1<f1.size())
	{
		if(f1[i1].SS==0) i1++;
		else
		{
			ret.PB(f1[i1]);
			i1++;
		}
	}
	while(i2<f2.size())
	{
		if(f2[i2].SS==0) i2++;
		else
		{
			ret.PB(f2[i2]);
			i2++;
		}
	}
	return ret;
}

pair<ll,vector<pl>> phi(ll n) //calculate euler function of n and return the factorization of phi(n) at the same time
{
    vector<pl> ret=get_fac(n);
    vector<vector<pl>> q;q.clear();
    ll p=n;
    for(auto & v:ret)
    {
    	v.SS--;
    	q.PB(mal_fac(v.FF-1));
    	p-=p/v.FF;
	}
	for(auto & v:q)
	{
		ret=combine(ret,v);
	}
	return MP(p,ret);
}

ll mult(ll a,ll b,ll md) //multiply two long long integers
{
	if(b==0) return 0;
	ll ret=mult((a<<1)%md,b>>1,md);
	if(b&1) ret=(ret+a)%md;
	return ret;
}

ll qpow(ll x,ll k,ll md)
{
	if(k==0) return 1;
	ll ret=qpow(mult(x,x,md),k>>1,md);
	if(k&1) ret=mult(ret,x,md);
	return ret;
}

ll m,x;

int main()
{
	scanf("%lld%lld",&m,&x);
	d.clear();mp.clear();
	
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
	
	//calculate the factorization of m
	ll tmp=m;
	for(ll i=2;i*i<=tmp;i++)
	{
		int cnt=0;
		while(tmp%i==0)
		{
			tmp/=i;
			cnt++;
		}
		if(cnt) f.PB(pl(i,cnt));
	}
	if(tmp>1) f.PB(pl(tmp,1));
	
	//for each v|m, ans+=phi(v)/ord(v);
	ll ans=0;
	for(auto v:d)
	{
		auto now=phi(v);
		ll pv=now.FF;
		vector<pl> pf=now.SS;
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
