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
const int Maxk=(1<<20)+5;
const int md=1e9+7;

class que
{
	public:
		int l,x,id;
		void init()
		{
			scanf("%d%d",&l,&x);
		}
		bool operator<(const que &o)const
		{
			return l<o.l;
		}
};

int n,Q,a[Maxn],ans[Maxn];
que q[Maxn];
bool flag[Maxk];
vector<int> ss;
int cnt=1;

void mod(int pos)
{
	if(flag[a[pos]])
	{
		cnt=(cnt<<1)%md;
		return;
	}
	int sz=ss.size();
	rep0(i,sz)
	{
		int d=ss[i]^a[pos];
		flag[d]=true;
		ss.PB(d);
	}
}

int main()
{
	scanf("%d%d",&n,&Q);
	rep(i,n)
	{
		scanf("%d",a+i);
	}
	rep(i,Q)
	{
		q[i].id=i;
		q[i].init();
	}
	sort(q+1,q+Q+1);
	int cur=0;
	flag[0]=true;
	ss.PB(0);
	rep(i,Q)
	{
		while(cur<q[i].l)
		{
			mod(++cur);
		}
		if(flag[q[i].x])
		{
			ans[q[i].id]=cnt;
		}
		else
		{
			ans[q[i].id]=0;
		}
	}
	rep(i,Q)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
