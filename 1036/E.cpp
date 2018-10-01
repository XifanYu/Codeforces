#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<int> cd;

ll qpow(ll x,ll k,ll mod)
{
    ll ret=1;
	while(k)
	{
	   if(k&1)	
	   {
	   	 ret=ret*x;
	   	 ret=ret%mod;
	   }
	   x=x*x;
	   x=x%mod;
	   k=(k>>1);
	}
	return ret;	
}
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
 * high precision: printf("%.12lf",(int)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

ll gcd(ll a,ll b)
{
	return a?gcd(b%a,a):b;
}

class pnt 
{
public:
    ll x, y;
    pnt() {}
    pnt(ll x, ll y): x(x), y(y) {}
    pnt operator+=(const pnt &t) 
	{
        x += t.x;
        y += t.y;
        return *this;
    }
    pnt operator-=(const pnt &t) 
	{
        x -= t.x;
        y -= t.y;
        return *this;
    }
    pnt operator*=(ll t) 
	{
        x *= t;
        y *= t;
        return *this;
    }
    pnt operator/=(ll t)
    {
    	x /= t;
    	y /= t;
    	return *this;
	}
    pnt operator+(const pnt &t) const 
	{
        return pnt(*this) += t;
    }
    pnt operator-(const pnt &t) const 
	{
        return pnt(*this) -= t;
    }
    pnt operator*(ll t) const 
	{
        return pnt(*this) *= t;
    }
    pnt operator/(ll t) const
    {
    	return pnt(*this) /= t;
	}
    bool operator<(const pnt & o)const
    {
    	return x<o.x||(x==o.x&&y<o.y);
	}
	void read()
	{
		scanf("%lld%lld",&x,&y);
	}
};

ll cross(pnt a,pnt b) 
{
    return a.x*b.y-a.y*b.x;
}


pnt operator*(ll a, pnt b) {
    return b * a;
}

ll dot(pnt a,pnt b) 
{
    return a.x*b.x+a.y*b.y;
}

class seg
{
public:
	pnt p1,p2;
	void read()
	{
		p1.read();p2.read();
	}
	ll count()
	{
		ll x=abs(p1.x-p2.x),y=abs(p1.y-p2.y);
		ll g=gcd(x,y);
		return g+1;
	}
};

const int Maxn=1005;

int n;
seg s[Maxn];
ll ans=0;
set<pnt> ss[Maxn];
set<pnt> add;

bool check(seg a,seg b)
{
	pnt x=a.p1-a.p2,y=b.p1-b.p2;
	return abs(cross(x,y))==0;
}

pnt intersect(pnt a1, pnt d1, pnt a2, pnt d2) //a1 as a starting point, d1 as the direction of the line
{
	return a1+cross(a2-a1,d2)*d1/cross(d1,d2);
}

bool contain(pnt a,pnt b,pnt p)
{
	if(p.x>a.x&&p.x>b.x) return false;
	if(p.x<a.x&&p.x<b.x) return false;
	if(p.y>a.y&&p.y>b.y) return false;
	if(p.y<a.y&&p.y<b.y) return false;
	return abs(cross(a-p,b-p))==0&&dot(a-p,b-p)<=0;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		s[i].read();
		ans+=s[i].count();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(check(s[i],s[j])) continue;
			seg & a=s[i];
			seg & b=s[j];
			pnt x=intersect(a.p1,a.p2-a.p1,b.p1,b.p2-b.p1);
			if(contain(a.p1,a.p2,x)&&contain(b.p1,b.p2,x))
			{
				ss[i].insert(x);
				ss[j].insert(x);
				add.insert(x);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans-=ss[i].size();
	}
	ans+=add.size();
	printf("%lld\n",ans);
	return 0;
}
