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
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
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

const int Maxn=1e5+5;

int n,k,m;
ll ans=0;
int a[Maxn];
int pa[Maxn];
map<string,int> mp;
string s;

int find(int x)
{
	if(pa[x]==x) return x;
	return pa[x]=find(pa[x]);
}

void merge(int u,int v)
{
	u=find(u);
	v=find(v);
	if(a[u]<a[v]) pa[v]=u;
	else pa[u]=v;
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin>>n>>k>>m;
	rep(i,n)
	{
		cin>>s;
		mp[s]=i;
		pa[i]=i;
	}
	rep(i,n)
	{
		cin>>a[i];
	}
	rep(i,k)
	{
		int x,last,now;
		cin>>x;
		x--;
		cin>>last;
		rep(j,x)
		{
			cin>>now;
			merge(last,now);
		}
	}
	rep(i,m)
	{
		cin>>s;
		ans+=a[find(mp[s])];
	}
	cout<<ans<<"\n";
	return 0;
}
