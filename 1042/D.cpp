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

typedef pair<ll,int> pli;

const int Maxn=2e5+5;

int n;
ll a[Maxn],t;
ll ans=0;
vector<pli> ss;
int bit[Maxn];
int pos[Maxn];

int get(int i)
{
	int rez=0;
	while(i)
	{
		rez+=bit[i];
		i-=i&-i;
	}
	return rez;
}

void add(int i)
{
	while(i<=n)
	{
		bit[i]++;
		i+=i&-i;
	}
}


int main()
{
	scanf("%d%lld",&n,&t);
	ll sum=0;
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		ss.PB(pli(sum,i));
	}
	sort(all(ss));
	for(int i=0;i<n;i++)
	{
		pos[ss[i].SS]=i+1;
		//cout<<ss[i].FF<<" "<<ss[i].SS<<"\n";
	}
	
	for(int i=1;i<=n;i++)
	{
		int x=LB(all(ss),pli(t,-1))-ss.begin();
		//cout<<x<<" "<<get(x)<<"\n";
		ans+=x-get(x);
		add(pos[i]);
		t+=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
