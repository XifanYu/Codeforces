#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;

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

const int Maxn=2e5+5;
const int inf=0x3f3f3f3f;

class rect
{
public:
	int l,d,r,u;
	
	rect(int L=-inf,int D=-inf,int R=inf,int U=inf)
	{
		l=L;d=D;r=R;u=U;
	}
	
	void read()
	{
		scanf("%d%d%d%d",&l,&d,&r,&u);
	}
	
	bool empty()
	{
		return l>r||d>u;
	}	
};

rect join(rect a,rect b)
{
	return rect(max(a.l,b.l),max(a.d,b.d),min(a.r,b.r),min(a.u,b.u));
}

int n;
rect r[Maxn];
rect pre[Maxn],suf[Maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) r[i].read();
	for(int i=1;i<=n;i++) pre[i]=join(pre[i-1],r[i]);
	for(int i=n;i>=1;i--) suf[i]=join(suf[i+1],r[i]);
	for(int i=1;i<=n;i++)
	{
		rect tmp=join(pre[i-1],suf[i+1]);
		if(!tmp.empty())
		{
			printf("%d %d\n",tmp.l,tmp.d);
			return 0;
		}
	}
	return 0;
}
