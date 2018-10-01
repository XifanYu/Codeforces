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

class seg
{
public:
	int x,l,r,t;
	seg(int X,int L,int R,int T)
	{
		x=X;l=L;r=R;t=T;
	}	
	bool operator<(const seg & o)const
	{
		if(x<o.x) return true;
		if(x>o.x) return false;
		if(t<o.t) return true;
		return false;
	}
};

const int Maxn=(1<<18);

int n;
set<int> ss;
map<int,int> mp;
int c[Maxn<<1];
vector<seg> sg;
int a[Maxn<<2],b[Maxn<<2];

void pushdown(int p,int l,int r)
{
	a[p]+=b[p];
	if(r-l)
	{
		b[lc]+=b[p];
		b[rc]+=b[p];
	}
	b[p]=0;
}

int cnt;

void update(int t,int lb,int rb,int p=0,int l=1,int r=cnt)
{
	pushdown(p,l,r);
	if(c[l]>rb||c[r]<lb) return;
	if(lb<=c[l]&&c[r]<=rb)
	{
		if(t) b[p]--;
		else b[p]++;
		pushdown(p,l,r);
		return;
	}
	int mi=(l+r)>>1;
	update(t,lb,rb,lc,l,mi);
	update(t,lb,rb,rc,mi+1,r);
	a[p]=max(a[lc],a[rc]);
}

void print(int x,int p=0,int l=1,int r=cnt)
{
	if(r-l==0)
	{
		printf("%d %d\n",x,c[l]);
		return;
	}
	int mi=(l+r)>>1;
	pushdown(lc,l,mi);
	pushdown(rc,mi+1,r);
	if(a[lc]>=n-1) print(x,lc,l,mi);
	else print(x,rc,mi+1,r);
}

int main()
{
	scanf("%d",&n);
	ss.clear();sg.clear();
	for(int i=1;i<=n;i++)
	{
		int lx,ly,ux,uy;
		scanf("%d%d%d%d",&lx,&ly,&ux,&uy);
		ss.insert(ly);
		ss.insert(uy);
		sg.PB(seg(lx,ly,uy,0));
		sg.PB(seg(ux,ly,uy,1));
	}
	sort(all(sg));
	cnt=0;
	for(auto v:ss)
	{
		mp[v]=++cnt;
		c[cnt]=v;
	}
	for(auto v:sg)
	{
		update(v.t,v.l,v.r);
		if(a[0]>=n-1)
		{
			print(v.x);
			return 0;
		}
	}
	return 0;
}
