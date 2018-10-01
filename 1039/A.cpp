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

const int Maxn=2e5+5;

int n;
ll t;
ll a[Maxn],b[Maxn];
bool flag[Maxn];
int x[Maxn];

int main()
{
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	bool check=false;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",x+i);
		if(x[i]<i) check=true;
		flag[x[i]]=true;
	}
	for(int l=1,r=1;l<=n;l++)
	{
		if(r>=x[l]) continue;
		if(r<l) r=l;
		while(r<x[l])
		{
			if(flag[r]) check=true;
			r++;
		}
	}
	if(check)
	{
		puts("No");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		if(!flag[i])
		{
			b[i]=a[i+1]+t;
		}
		else
		{
			b[i]=a[i+1]+t-1;
		}
	}
	b[n]=b[n-1]+1;
	for(int i=1;i<n;i++)
	{
		if(b[i]>=b[i+1])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i=1;i<=n;i++) printf("%lld ",b[i]);
	puts("");
	return 0;
}
