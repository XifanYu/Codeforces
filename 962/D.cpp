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

const int Maxn=2e5+5;

int n;
ll a[Maxn];
set<ll> ele;
map<ll,set<int>> pos;
int cnt=0;
vector<ll> ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",a+i);
		ele.insert(a[i]);
		pos[a[i]].insert(i);
	}
	for(auto v:ele)
	{
		if(pos[v].size()>1)
		{
			ll nex=2*v;
			ele.insert(nex);
			set<int>::iterator it=pos[v].begin(),tp;
			while(it!=pos[v].end())
			{
				tp=it++;
				if(it==pos[v].end()) break;
				pos[nex].insert(*it);
				a[*tp]=0;
				a[*it]=nex;
				it++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		{
			cnt++;
			ans.PB(a[i]); 
		} 
	}
	printf("%d\n",cnt);
	for(auto v:ans) printf("%lld ",v);printf("\n");
	return 0;
}
