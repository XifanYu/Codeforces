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

int n,k;
int a[Maxn];
ll pw[11];
unordered_map<int,int> cnt[11];

void init()
{
	pw[0]=1;
	for(int i=1;i<=10;i++)
	{
		pw[i]=pw[i-1]*10%k;
	}
	for(int i=0;i<=10;i++)
	{
		cnt[i].clear();
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		for(int j=1;j<=10;j++)
		{
			cnt[j][pw[j]*a[i]%k]++;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int j=1,now=10;
		while(now<=a[i])
		{
			now*=10;
			j++;
		}
		cnt[j][pw[j]*a[i]%k]--;
		ans+=cnt[j][(k-a[i]%k)%k];
		cnt[j][pw[j]*a[i]%k]++;
	}
	printf("%lld\n",ans);
	return 0;
}
