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
int a[105];
int cnt[105];
bool belong[105];

void fail()
{
	puts("NO");
	exit(0);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",a+i);
		cnt[a[i]]++;
	}
	int ones=0;
	for(int i=1;i<=100;i++)
	{
		if(cnt[i]==1) ones++;
	}
	if(ones%2==0)
	{
		for(int i=1,j=1;i<=ones/2&&j<=n;j++)
		{
			if(cnt[a[j]]==1)
			{
				belong[j]=true;
				i++;
			}
		}
	}
	else
	{
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			if(cnt[a[i]]>2)
			{
				belong[i]=true;
				flag=true;
				break;
			}
		}
		if(!flag) fail();
		for(int i=1,j=1;i<=ones/2&&j<=n;j++)
		{
			if(cnt[a[j]]==1)
			{
				belong[j]=true;
				i++;
			}
		} 
	}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		if(belong[i]) putchar('A');
		else putchar('B');
	}
	puts("");
	return 0;
}
