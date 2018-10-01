#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;

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

vector<ll> v;

const ll Maxn=1e18+1;

ll mul(ll a,ll b) 
{
    return (a<=Maxn/b)?a*b:Maxn;
}

ll qpow(ll x,ll k)
{
    ll ret=1;
	while(k)
	{
	   if(k&1)	
	   {
	   	 ret=mul(ret,x);
	   }
	   x=mul(x,x);
	   k=(k>>1);
	}
	return ret;	
}

bool isSquare(ll x)
{
	ll c=sqrt(x);
	return c*c==x;
}

void init()
{
	for(int k=3;k<=59;k++)
	{
		ll x;
		for(int i=2;(x=qpow(i,k))<Maxn;i++)
		{
			if(!isSquare(x))
			{
				v.PB(x);
			}
		}
	}
	sort(all(v));
	v.resize(unique(all(v))-v.begin());
}

int main()
{
	init();
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ll n;
		scanf("%lld",&n);
		ll x=sqrt(n),y=UB(all(v),n)-v.begin();
		printf("%lld\n",n-x-y);
	}
	return 0;
}
