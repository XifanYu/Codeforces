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

ll n;
ll k;
ll l,r;
char s[10];

int main()
{
	srand(time(NULL));
	scanf("%lld%lld",&n,&k);
	l=1,r=n;
	int cnt=0;
	while(true)
	{
		cnt++;
		if(r-l>40)
		{
			ll nl=l,nr=(l+r)/2;
			printf("%lld %lld\n",nl,nr);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')
			{
				if(nl==nr) return 0;
				l=max((ll)1,nl-k);
				r=min(n,nr+k);
			}
			else if(s[0]=='B')
			{
				return 0;
			}
			else
			{
				l=max((ll)1,nr-k+1);
				r=min(n,r+k);
			}
		}
		else
		{
			ll x=rand()%(r-l+1);
			printf("%lld %lld\n",l+x,l+x);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')
			{
				return 0;
			}
			else if(s[0]=='B')
			{
				return 0;
			}
			else
			{
				l=max((ll)1,l-k);
				r=min(n,r+k);
			}
		}
	}
	return 0;
}
