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

const int Maxn=1005;
const int INF=0x3f3f3f3f;

int n;
int c[Maxn];
int val[Maxn];
vector<int> ss[3];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",c+i);
		char tmp[5];
		scanf("%s",tmp);
		int l=strlen(tmp);
		for(int j=0;j<l;j++)
		{
			val[i]|=(1<<(tmp[j]-'A'));
		}
		if(val[i]==1) ss[0].PB(i);
		if(val[i]==2) ss[1].PB(i);
		if(val[i]==4) ss[2].PB(i);
	}
	int ans=INF;
	for(auto x:ss[0])
	{
		for(auto y:ss[1])
		{
			for(auto z:ss[2])
			{
				ans=min(ans,c[x]+c[y]+c[z]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((val[i]|val[j])==7)
			{
				ans=min(ans,c[i]+c[j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(val[i]==7) ans=min(ans,c[i]);
	}
	if(ans==INF) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
