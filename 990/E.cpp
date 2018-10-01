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
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=1e6+5;

int n,m,k;
int pre[Maxn];
int s;
int a[Maxn];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++) pre[i]=i;
	if(m)
	{
		scanf("%d",&s);
		if(s==0)
		{
			printf("-1\n");
			return 0;
		}
		pre[s]=pre[s-1];
	}
	for(int i=2;i<=m;i++)
	{
		scanf("%d",&s);
		pre[s]=pre[s-1];
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",a+i);
	}
	ll ans=1e18;
	for(int i=1;i<=k;i++)
	{
		int pos=0,old=-1;
		ll val=0;
		while(pos<n)
		{
			pos=pre[pos];
			if(pos==old)
			{
				val=1e18;
				break;
			}
			old=pos;
			pos+=i;
			val+=a[i];
		}
		ans=min(ans,val);
	}
	if(ans==1e18) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;	
}
