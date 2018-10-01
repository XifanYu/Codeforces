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

char tmp[10];
int n;
int cnt[2][4][3];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%s",tmp);
			int num=0;
			while(tmp[num]=='X') num++;
			if(tmp[num]=='M') cnt[i][num][0]++;
			else if(tmp[num]=='S') cnt[i][num][1]++;
			else cnt[i][num][2]++;
		}
	}
	int ans=0;
	for(int i=0;i<=3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(cnt[0][i][j]>cnt[1][i][j]) ans+=cnt[0][i][j]-cnt[1][i][j];
		}
	}
	printf("%d\n",ans);
	return 0;
}
