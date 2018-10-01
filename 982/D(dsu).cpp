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
#define UB upper_bound
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
typedef double db; 

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=1e5+5;

int n;
int a[Maxn];
int sz[Maxn];
int pa[Maxn];
pi b[Maxn];

class root
{
public:
	int x;
	bool operator<(const root&o)const
	{
		return (sz[x]<sz[o.x])||(sz[x]==sz[o.x]&&x<o.x);
	}
	bool operator==(const root&o)const
	{
		return x==o.x;
	}
};

set<root> ss;

int find(int x)
{
	return pa[x]==x?x:pa[x]=find(pa[x]);
}

int main()
{
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i);
	rep(i,n) b[i]=pi(a[i],i);
	sort(b+1,b+n+1);
	int cnt=0,last=0,ans;
	rep(i,n)
	{
		int pos=b[i].SS,val=b[i].FF;
		sz[pos]=1;
		pa[pos]=pos;
		if(find(pos+1))
		{
			pa[pos+1]=pos;
			sz[pos]+=sz[pos+1];
			ss.erase(ss.LB(root{pos+1}));
			cnt--;
		}
		if(find(pos-1))
		{
			ss.erase(ss.LB(root{pa[pos-1]}));
			pa[pos]=pa[pos-1];
			sz[pa[pos-1]]+=sz[pos];
			ss.insert(root{pa[pos-1]});
		}
		else
		{
			ss.insert(root{pos});
			cnt++;
		}
		if(sz[ss.begin()->x]==sz[ss.rbegin()->x]&&cnt>last)
		{
			last=cnt;
			ans=val+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
