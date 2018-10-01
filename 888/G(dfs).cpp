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

#define MP make_pair
#define FF first
#define SS second
#define LB lower_bound
#define PB push_back
#define lc p*2+1
#define rc p*2+2
#define rep(n) for(int i=1;i<=n;i++)
#define rep0(n) for(int i=0;i<n;i++)
#define rrep(n) for(int i=n;i;i--)
#define rrep0(n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()

typedef long long ll;
typedef pair<int,int> pi; 

/*
 * high precision: cout<<fixed<<setprecision(10)<<;
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int INF=1<<30;
const int Maxn=2e5+5;
const int M=30;

int n;
int a[Maxn];
int nex[Maxn*M][2],sz[Maxn*M],dep[Maxn*M],now,cnt=2;
vector<int> sub[Maxn*M];
ll ans=0;

void calc(int x,int y)
{
	int add=INF;
	for(auto v:sub[x])
	{
		int now=y;
		for(int i=dep[y]-1;i>=0;i--)
		{
			int d=(a[v]>>i)&1;
			if(sz[nex[now][d]])
			{
				now=nex[now][d];
			}
			else
			{
				now=nex[now][1-d];
			}
		}
		add=min(add,(a[v]^a[sub[now][0]]));
	}
	ans+=add;
}

void dfs(int now)
{
	int l=nex[now][0],r=nex[now][1];
	if(sz[l]&&sz[r])
	{
		if(sz[l]>sz[r])
		{
			calc(r,l);
		}
		else
		{
			calc(l,r);
		}
	}
	if(sz[l]) dfs(l);
	if(sz[r]) dfs(r);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++)
	{
		now=1;
		for(int j=M-1;j>=0;j--)
		{
			int d=(a[i]>>j)&1;
			if(!nex[now][d])
			{
				dep[cnt]=j;
				nex[now][d]=cnt++;
			}
			now=nex[now][d];
			sz[now]++;
			sub[now].PB(i);
		}
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
