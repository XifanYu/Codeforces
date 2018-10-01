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

const int Maxn=(1<<18);

int n;
ll t[Maxn<<1],b[Maxn<<1];
int cnt=1;

void pushdown(int p,int l,int r)
{
	t[p]+=b[p]*(r-l+1);
	if(l!=r)
	{
		b[lc]+=b[p];
		b[rc]+=b[p];
	}
	b[p]=0;
}

void update(int lf,int rg,ll v,int p=0,int l=1,int r=Maxn)
{
	pushdown(p,l,r);
	if(lf>r||rg<l) return;
	if(lf<=l&&r<=rg)
	{
		b[p]+=v;
		pushdown(p,l,r);
		return;
	}
	int mi=(l+r)>>1;
	update(lf,rg,v,lc,l,mi);
	update(lf,rg,v,rc,mi+1,r);
	t[p]=t[lc]+t[rc];
}

ll query(int lf,int rg,int p=0,int l=1,int r=Maxn)
{
	pushdown(p,l,r);
	if(lf>r||rg<l) return 0;
	if(lf<=l&&r<=rg)
	{
		return t[p];
	}
	int mi=(l+r)>>1;
	return query(lf,rg,lc,l,mi)+query(lf,rg,rc,mi+1,r);
	 
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int a,x;
			scanf("%d%d",&a,&x);
			update(1,a,x);
		}
		else if(t==2)
		{
			int k;
			scanf("%d",&k);
			++cnt;
			update(cnt,cnt,k);
		}
		else
		{
			ll v=query(cnt,cnt);
			update(cnt,cnt,-v);
			--cnt;
		}
		printf("%.12lf\n",(db)query(1,cnt)/cnt);
	}
	return 0;
}
