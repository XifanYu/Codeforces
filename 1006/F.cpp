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

int n,m;
ll k;
ll a[25][25],ans=0;
map<ll,ll> mp1[25][25],mp2[25][25];

int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) scanf("%lld",a[i]+j);
	}
	if(n==1&&m==1)
	{
		if(a[1][1]==k) printf("1\n");
		else printf("0\n");
		return 0;
	}
	int h=(n+m+1)/2;
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<25;j++)
		{
			mp1[i][j].clear();
			mp2[i][j].clear();
		}
	}
	mp1[1][1][a[1][1]]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m&&i+j<h;j++)
		{
			for(auto v:mp1[i][j])
			{
				if(i<n)
				{
					if(mp1[i+1][j].find(v.FF^a[i+1][j])!=mp1[i+1][j].end()) mp1[i+1][j][v.FF^a[i+1][j]]+=v.SS;
					else mp1[i+1][j][v.FF^a[i+1][j]]=v.SS;
				}
				if(j<m)
				{
					if(mp1[i][j+1].find(v.FF^a[i][j+1])!=mp1[i][j+1].end()) mp1[i][j+1][v.FF^a[i][j+1]]+=v.SS;
					else mp1[i][j+1][v.FF^a[i][j+1]]=v.SS;
				}
			}
		}
	}
	mp2[n][m][a[n][m]]=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1&&i+j>h;j--)
		{
			for(auto v:mp2[i][j])
			{
				if(i>1)
				{
					if(mp2[i-1][j].find(v.FF^a[i-1][j])!=mp2[i-1][j].end()) mp2[i-1][j][v.FF^a[i-1][j]]+=v.SS;
					else mp2[i-1][j][v.FF^a[i-1][j]]=v.SS;
				}
				if(j>1)
				{
					if(mp2[i][j-1].find(v.FF^a[i][j-1])!=mp2[i][j-1].end()) mp2[i][j-1][v.FF^a[i][j-1]]+=v.SS;
					else mp2[i][j-1][v.FF^a[i][j-1]]=v.SS;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i+j==h)
			{
				for(auto v:mp1[i][j])
				{
					if(mp2[i][j].find(v.FF^k^a[i][j])!=mp2[i][j].end())ans+=v.SS*mp2[i][j][v.FF^k^a[i][j]];
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
