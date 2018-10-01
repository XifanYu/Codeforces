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
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()
#define clean(v,a) memset(v,a,sizeof(v))

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=1e5+5;

int n,m;
vector<int> edge[Maxn];

int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}

int main()
{
	scanf("%d%d",&n,&m);
	if(n>m+1)
	{
		printf("Impossible\n");
		return 0;
	}
	m-=(n-1);
	for(int i=1;i<n;i++) edge[i].PB(i+1);
	int now=1,nex;
	while(m&&now<n-1)
	{
		nex=now+2;
		while(m&&nex<=n)
		{
			if(gcd(now,nex)==1)
			{
				m--;
				edge[now].PB(nex);
			}
			nex++;
		}
		now++;
	}
	if(m)
	{
		printf("Impossible\n");
		return 0;
	}
	else
	{
		printf("Possible\n");
		for(int i=1;i<=n;i++)
		{
			for(auto v:edge[i]) printf("%d %d\n",i,v);
		}
	}
	return 0;
}
