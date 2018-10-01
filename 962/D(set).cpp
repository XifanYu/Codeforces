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
typedef pair<ll,int> pli;

/*
 * high precision: cout<<fixed<<setprecision(10)<<;
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=15e4+5;

int n,del=0;
ll a[Maxn],x;
set<pli> s; 

int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%lld",&x);
		s.insert(pli(x,i));
	}
	set<pli>::iterator it=s.begin(),tp;
	while(it!=s.end())
	{
		tp=it++;
		if(it==s.end()||it->FF!=tp->FF)
		{
			a[tp->SS]=tp->FF;
			s.erase(tp);
		}
		else
		{
			del++;
			s.erase(tp);
			tp=it++;
			s.insert(pli(((tp->FF)<<1),tp->SS));
			s.erase(tp);
		}
		it=s.begin();
	}
	printf("%d\n",n-del);
	rep(i,n)
	{
		if(a[i])
		{
			printf("%lld ",a[i]);
		}
	}
	printf("\n");
	return 0;
}
