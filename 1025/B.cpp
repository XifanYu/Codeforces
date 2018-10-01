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
typedef pair<ll,ll> pl; 
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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define clean(v,a) memset(v,a,sizeof(v))
#define PQ priority_queue

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=150005;

int n;
int a[Maxn],b[Maxn];

int gcd(int x,int y)
{
	return x?gcd(y%x,x):y;
}

set<int> ss;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",a+i,b+i);
	ss.clear();
	for(int i=2;(ll)i*i<=a[1];i++)
	{
		if(a[1]%i==0)
		{
			while(a[1]%i==0) a[1]/=i;
			ss.insert(i);
		}
	}
	if(a[1]>1) ss.insert(a[1]);
	for(int i=2;(ll)i*i<=b[1];i++)
	{
		if(b[1]%i==0)
		{
			while(b[1]%i==0) b[1]/=i;
			ss.insert(i);
		}
	}
	if(b[1]>1) ss.insert(b[1]);
	for(int i=2;i<=n;i++)
	{
		for(auto it=ss.begin();it!=ss.end();)
		{
			if((a[i]%(*it)==0)||(b[i]%(*it)==0)) 
			{
				it++;
				continue;
			}
			auto tp=it++;
			ss.erase(tp);
		}
	}
	if(!ss.empty())
	{
		printf("%d\n",*ss.begin());
	}
	else printf("-1\n");
	return 0;
}
