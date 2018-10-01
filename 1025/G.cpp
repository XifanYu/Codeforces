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

const int Maxn=505;
const int md=1e9+7;

int n;
int a[Maxn];
int pw[Maxn];
int cnt[Maxn];

int main()
{
	scanf("%d",&n);
	pw[0]=1;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",a+i);
		if(a[i]>0) cnt[a[i]]++;
		pw[i]=(pw[i-1]<<1);
		if(pw[i]>=md) pw[i]-=md;
	}
	int ans=pw[n-1]-1;
	for(int i=1;i<=n;i++)
	{
		ans-=(pw[cnt[i]]-1);
		if(ans<0) ans+=md;
	}
	printf("%d\n",ans);
	return 0;
}
