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

const int Maxn=120;

int n,m;
char s[Maxn][Maxn];
int cnt[Maxn][Maxn];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt[i][j]=cnt[i][j-1]+(s[i][j]=='B'?1:0);
		}
	}
	for(int d=m-((m&1)?1:2);d>=0;d-=2)
	{
		for(int l=1,r=l+d;r<=m;l++,r++)
		{
			for(int k=1,cur=0;k<=n;k++)
			{
				if(cnt[k][r]-cnt[k][l-1]==d+1) cur++;
				else cur=0;
				if(cur>d)
				{
					printf("%d %d",k-cur/2,(l+r)/2);
					return 0;
				}
			}
		}
	}
	return 0;
}
