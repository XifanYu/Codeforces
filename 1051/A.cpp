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

int t,n;
char s[105];
int cnt[3];

int is(char c)
{
	if('a'<=c&&c<='z') return 0;
	if('A'<=c&&c<='Z') return 1;
	return 2;
}

void print(int x,int y)
{
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(is(s[i])==x&&!flag)
		{
			if(y==0) putchar('a');
			else if(y==1) putchar('A');
			else putchar('0');
			flag=true;
		}
		else
		{
			putchar(s[i]);
		}
	}
	puts("");
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		n=strlen(s);
		clean(cnt,0);
		for(int i=0;i<n;i++)
		{
			cnt[is(s[i])]++;
		}
		if(cnt[0]&&cnt[1]&&cnt[2])
		{
			printf("%s\n",s);
		}
		else if(cnt[0]&&cnt[1])
		{
			if(cnt[0]>1)
			{
				print(0,2);
			}
			else
			{
				print(1,2);
			}
		}
		else if(cnt[1]&&cnt[2])
		{
			if(cnt[1]>1)
			{
				print(1,0);
			}
			else
			{
				print(2,0);
			}
		}
		else if(cnt[2]&&cnt[0])
		{
			if(cnt[2]>1)
			{
				print(2,1);
			}
			else
			{
				print(0,1);
			}
		}
		else if(cnt[0])
		{
			putchar('A');
			putchar('0');
			for(int i=2;i<n;i++) putchar(s[i]);
			puts("");
		}
		else if(cnt[1])
		{
			putchar('a');
			putchar('0');
			for(int i=2;i<n;i++) putchar(s[i]);
			puts("");
		}
		else if(cnt[2])
		{
			putchar('a');
			putchar('A');
			for(int i=2;i<n;i++) putchar(s[i]);
			puts("");
		}
	}
	return 0;
}
