#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;

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
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */
 
const int Maxn=2005;
const db PI=acos(-1.0);
const db DPI=2.0*PI;

class pnt
{
public:
	int x,y;
	db ang;
	void read(int i)
	{
		scanf("%d%d",&x,&y);
	}
	pnt(int X=0,int Y=0)
	{
		x=X;y=Y;ang=atan2(y,x);
	}
	pnt(int X,int Y,db ANG)
	{
		x=X;y=Y;ang=ANG;
	}
	bool operator<(const pnt & o)const
	{
		return ang<o.ang;
	}
	bool operator<=(const pnt & o)const
	{
		return ang<=o.ang;
	}
	pnt operator-(pnt & o)
	{
		return pnt(x-o.x,y-o.y);
	}
	pnt operator-()
	{
		return pnt(-x,-y,ang+PI);
	}
};

int n;
pnt p[Maxn];
pnt l[Maxn<<1];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) p[i].read(i);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1,cnt=1;j<=n;j++)
		{
			if(i==j) continue;
			l[cnt++]=p[j]-p[i];
		}
		sort(l+1,l+n);
		for(int j=n;j<(n<<1);j++) 
		{
			l[j]=l[j-n+1];
			l[j].ang+=DPI;
		}
		for(int c1=1,c2=2,cnt1=0,cnt2=n-2;c1<n;c1++,cnt1--,cnt2++)
		{
			while(cnt2&&l[c2]<=-l[c1])
			{
				c2++;
				cnt1++;
				cnt2--;
			}
			ans+=(ll)cnt1*(cnt1-1)*cnt2*(cnt2-1)/4;
		}
	}
	printf("%lld\n",ans/2);
	return 0;
}
