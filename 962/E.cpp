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

int n;

vector<int> a,b,c;
ll ans=0;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int d;
		char x;
		scanf("%d %c",&d,&x);
		if(x=='B')
		{
			a.PB(d);
		}
		else if(x=='R')
		{
			b.PB(d);
		}
		else
		{
			a.PB(d);
			b.PB(d);
			c.PB(d);
		}
	}
	if(a.size())ans+=a[a.size()-1]-a[0];
	if(b.size())ans+=b[b.size()-1]-b[0];
	int l=0,r=1,id1=0,id2=0;
	while(r<c.size())
	{
		while(id1<a.size()&&a[id1]<=c[l]) id1++;
		while(id2<b.size()&&b[id2]<=c[l]) id2++;
		ll mx1=0,mx2=0;
		while(id1<a.size()&&a[id1]<=c[r])
		{
			mx1=max(mx1,(ll)a[id1]-a[id1-1]);
			id1++;
		}
		while(id2<b.size()&&b[id2]<=c[r])
		{
			mx2=max(mx2,(ll)b[id2]-b[id2-1]);
			id2++;
		}
		if(mx1+mx2>c[r]-c[l])
		{
			ans-=mx1+mx2+c[l]-c[r];
		}
		l++;
		r++;
	}
	printf("%lld\n",ans);
	return 0;
}
