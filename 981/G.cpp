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

struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
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

const int md=998244353;
const int Maxn=(1<<18);
const int sub1=md-1;

class node
{
	public:
		ll s,a,b;
		node()
		{
			s=b=0;
			a=1;
		}
		inline void calc(int l,int r)
		{
			s=(s*a+b*(r-l+1))%md;
			a=1;
			b=0;
		}
};

int n,q;
node t[Maxn<<1];
set<pi> seg[Maxn];

inline void pushup(int p)
{
	t[p].s=(t[lc].s+t[rc].s)%md;
}

inline void pushdown(int p,int l,int r)
{
	if(l!=r)
	{
		int ta=t[p].a,tb=t[p].b;
		t[lc].a=(t[lc].a*ta)%md;
		t[lc].b=(t[lc].b*ta+tb)%md;
		t[rc].a=(t[rc].a*ta)%md;
		t[rc].b=(t[rc].b*ta+tb)%md;
	}
	t[p].calc(l,r);
}

inline void update(int a,int b,int f,int p=0,int l=1,int r=Maxn)
{
	pushdown(p,l,r);
	if(a>r||l>b) return;
	if(a<=l&&r<=b)
	{
		if(f==0)
		{
			t[p].b=(t[p].b+1)%md;
		}
		else if(f==1)
		{
			t[p].b=(t[p].b+sub1)%md;
		}
		else
		{
			t[p].a=(t[p].a<<1)%md;
			t[p].b=(t[p].b<<1)%md;
		}
		pushdown(p,l,r);
		return;
	}
	int mi=(l+r)>>1;
	update(a,b,f,lc,l,mi);
	update(a,b,f,rc,mi+1,r);
	if(l!=r) pushup(p);
}

inline int query(int a,int b,int p=0,int l=1,int r=Maxn)
{
	pushdown(p,l,r);
	if(a>r||l>b) return 0;
	if(a<=l&&r<=b)
	{
		return t[p].s;
	}
	int mi=(l+r)>>1,sum=0;
	sum=(query(a,b,lc,l,mi)+query(a,b,rc,mi+1,r))%md;
	return sum;
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	{
		int t,l,r,x;
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			update(l,r,0);
			set<pi>::iterator it=seg[x].LB(pi(l,r)),tp;
			if(it!=seg[x].begin()&&prev(it)->SS>=l) it--;
			int L=l,R=r;
			while(it!=seg[x].end()&&it->FF<=r)
			{
				L=min(L,it->FF);
				R=max(R,it->SS);
				int tl=max(l,it->FF),tr=min(r,it->SS);
				update(tl,tr,1);
				update(tl,tr,2);
				tp=it++;
				seg[x].erase(tp);
			}
			seg[x].insert(pi(L,R));
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r));
		}
	}
	return 0;
}
