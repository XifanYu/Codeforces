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

const int Maxn=(1<<17);
const int md=95542721;

class node
{
	public:
		int k;
		int v[48];
		void calc(int x)
		{
			v[0]=x;
			for(int i=1;i<48;i++)
			{
				v[i]=((ll)(((ll)v[i-1]*v[i-1])%md)*v[i-1])%md;
			}
		}
};

int n,q;
int a[Maxn<<1];
node t[Maxn<<1];

void pushup(int p)
{
	for(int i=0;i<48;i++)
	{
		t[p].v[i]=(t[lc].v[i]+t[rc].v[i])%md;
	}
}

void build(int p=0,int l=1,int r=Maxn)
{
	if(l!=r)
	{
		int mi=(l+r)>>1;
		build(lc,l,mi);
		build(rc,mi+1,r);
		pushup(p);
	}
	else
	{
		t[p].calc(a[l]);
	}
}

void pushdown(int p,int l,int r)
{
	int k=t[p].k%48;
	if(k!=0)
	{
		int tmp[48];
		for(int i=0;i<48;i++)
		{
			tmp[i]=t[p].v[i];
		}
		for(int i=0;i<48;i++)
		{
			t[p].v[i]=tmp[(i+k)%48];
		}
		if(l!=r)
		{
			t[lc].k+=k;
			t[rc].k+=k;
		}
		t[p].k=0;
	}
}

void update(int lf,int rg,int p=0,int l=1,int r=Maxn)
{
	pushdown(p,l,r);
	if(lf>r||rg<l) return;
	if(lf<=l&&r<=rg)
	{
		t[p].k++;
		pushdown(p,l,r);
		return;
	}
	int mi=(l+r)>>1;
	update(lf,rg,lc,l,mi);
	update(lf,rg,rc,mi+1,r);
	pushup(p);
}

int query(int lf,int rg,int p=0,int l=1,int r=Maxn)
{
	pushdown(p,l,r);
	if(lf>r||rg<l) return 0;
	if(lf<=l&&r<=rg)
	{
		return t[p].v[0];
	}
	int mi=(l+r)>>1;
	return (query(lf,rg,lc,l,mi)+query(lf,rg,rc,mi+1,r))%md;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	build();
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if(t==1)
		{
			printf("%d\n",query(l,r));
		}
		else
		{
			update(l,r);
		}
	}
	return 0;
}
