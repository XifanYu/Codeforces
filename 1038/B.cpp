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

int n;

int main()
{
	scanf("%d",&n);
	if(n<3)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	if(n&1)
	{
		printf("1 %d\n",(n+1)/2);
		printf("%d",n-1);
		for(int i=1;i<=n;i++)
		{
			if(i==(n+1)/2) continue;
			printf(" %d",i);
		}
		puts("");
	}
	else
	{
		printf("1 %d\n",n/2);
		printf("%d",n-1);
		for(int i=1;i<=n;i++)
		{
			if(i==n/2) continue;
			printf(" %d",i);
		}
		puts("");
	}
	return 0;
}
