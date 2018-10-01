#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <memory.h>
#include <functional>
#include <string.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi; 
typedef double db;

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

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=1e6+5;

int n;
char g[Maxn];
int p[Maxn],cnt=0;
int s[Maxn];
int dp[Maxn],dir[Maxn];

int get(int l,int r)
{
	if(l>r) return 0;
	if(l<1) return s[r]-s[0];
	if(r>n) return s[n]-s[l-1];
	return s[r]-s[l-1];
}

bool check(int x)
{
	dp[0]=0;
	dir[0]=1;
	for(int i=1;i<=cnt;i++)
	{
		if(dir[i-1]==1)
		{
			if(get(dp[i-1]+1,p[i])==0)
			{
				dp[i]=p[i]+x;
				dir[i]=1;
			}
			else
			{
				if(get(p[i]-x,p[i])-get(dp[i-1]+1,p[i])<0)
				{
					return false;
				}
				else
				{
					dp[i]=p[i];
					dir[i]=0;
				}
			}
		}
		else
		{
			if(get(dp[i-1]+1,p[i])==0)
			{
				dp[i]=p[i]+x;
				dir[i]=1;
			}
			else
			{
				if(get(p[i]-x,p[i])-get(dp[i-1]+1,p[i])<0)
				{
					return false;
				}
				else
				{
					if(get(p[i]-x,p[i])-get(dp[i-2]+1,p[i])>=0&&p[i-1]+x>p[i])
					{
						dp[i]=p[i-1]+x;
						dir[i]=0;
					}
					else
					{
						dp[i]=p[i];
						dir[i]=0;
					}
				}
			}
		}
	}
	if(get(1,dp[cnt])<s[n]) return false;
	return true;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",g+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1];
		if(g[i]=='P')
		{
			p[++cnt]=i;
		}
		else if(g[i]=='*')
		{
			s[i]++;
		}
	}
	if(cnt==1)
	{
		if(get(1,p[1])>get(p[1],n))
		{
			int t=0;
			for(int i=p[1];;i--)
			{
				if(get(i,p[1])==get(1,p[1])) break;
				t++;
			}
			printf("%d %d\n",get(1,p[1]),t);
		}
		else
		{
			int t=0;
			for(int i=p[1];;i++)
			{
				if(get(p[1],i)==get(p[1],n)) break;
				t++;
			}
			printf("%d %d\n",get(p[1],n),t);
		}
		return 0;
	}
	int ub=n-1,lb=0,mi;
	while(ub-lb>1)
	{
		mi=(ub+lb)>>1;
		if(check(mi)) ub=mi;
		else lb=mi;
	}
	printf("%d %d\n",s[n],ub);
	return 0;
}
