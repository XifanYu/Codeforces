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

const int Maxn=3e5+5;
const int Maxm=15e6+5;

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
} 

bool isprime[Maxm];
int prime[Maxm],t;
void prime_sieve()
{
	clean(isprime,true);
	t=0;
	for(int i=2;i<Maxm;i++)
	{
		if(isprime[i]) prime[++t]=i;
		for(int j=1;j<=t;j++)
		{
			if(prime[j]*i>=Maxm) break;
			isprime[prime[j]*i]=false;
			if(i%prime[j]==0) break;
		}
	}
}

void pre()
{
	prime_sieve();
}

int n,a[Maxn];
int cnt[Maxm];

int main()
{
	pre();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	int g=0;
	for(int i=1;i<=n;i++)
	{
		g=gcd(g,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		a[i]/=g;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=t&&prime[j]*prime[j]<=a[i];j++)
		{
			if(a[i]%prime[j]==0)
			{
				while(a[i]%prime[j]==0) a[i]/=prime[j];
				cnt[prime[j]]++;
			}
		}
		if(a[i]>1)
		{
			cnt[a[i]]++;
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=t;i++)
	{
		ans=min(ans,n-cnt[prime[i]]);
	}
	if(ans==n) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
