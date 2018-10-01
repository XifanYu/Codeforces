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
#define get(a) scanf("%d",&a)
#define get2(a,b) scanf("%d%d",&a,&b)
#define get3(a,b,c) scanf("%d%d%d",&a,&b,&c)

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=3e5+5;

int n;
int a[Maxn],b[Maxn];
ll suma[Maxn],sumb[Maxn];
ll suf1[Maxn],suf2[Maxn];
int c;

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	rep(i,1,n) scanf("%d",b+i);
	rep(i,1,n)
	{
		suma[i]=suma[i-1]+a[i];
		sumb[i]=sumb[i-1]+b[i];
	}
	suf1[1]=0;
	c=0;
	for(int i=1;i<=n;i++)
	{
		suf1[1]+=(ll)c*a[i];
		c++;
	}
	for(int i=n;i>=1;i--)
	{
		suf1[1]+=(ll)c*b[i];
		c++;
	}
	for(int i=3;i<=n;i+=2)
	{
		suf1[i]=suf1[i-2];
		suf1[i]-=(ll)((i-3)*2)*a[i-2];
		suf1[i]-=(ll)((i-3)*2+1)*a[i-1];
		suf1[i]-=(ll)(2*n-1)*b[i-2];
		suf1[i]-=(ll)(2*n-2)*b[i-1];
		suf1[i]+=(suma[n]-suma[i-1])*2;
		suf1[i]+=(sumb[n]-sumb[i-1])*2;
	}
	suf2[2]=0;
	c=2;
	for(int i=2;i<=n;i++)
	{
		suf2[2]+=(ll)c*b[i];
		c++;
	}
	for(int i=n;i>=2;i--)
	{
		suf2[2]+=(ll)c*a[i];
		c++;
	}
	for(int i=4;i<=n;i+=2)
	{
		suf2[i]=suf2[i-2];
		suf2[i]-=(ll)((i-3)*2)*b[i-2];
		suf2[i]-=(ll)((i-3)*2+1)*b[i-1];
		suf2[i]-=(ll)(2*n-1)*a[i-2];
		suf2[i]-=(ll)(2*n-2)*a[i-1];
		suf2[i]+=(suma[n]-suma[i-1])*2;
		suf2[i]+=(sumb[n]-sumb[i-1])*2;
	}
	ll ans=0;
	ll cur=0;
	c=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			ans=max(ans,cur+suf1[i]);
			cur+=(ll)c*a[i];
			c++;
			cur+=(ll)c*b[i];
			c++;
		}
		else
		{
			ans=max(ans,cur+suf2[i]);
			cur+=(ll)c*b[i];
			c++;
			cur+=(ll)c*a[i];
			c++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
