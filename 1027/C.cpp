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

const int Maxn=1e6+5;

int t,n;
int a[Maxn];
int cnt[Maxn],cur;
int val[Maxn];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			cnt[i]=0;
		}
		sort(a+1,a+n+1);
		cur=1;
		cnt[cur]=1;
		val[cur]=a[1];
		for(int i=2;i<=n;i++)
		{
			if(a[i]==val[cur]) cnt[cur]++;
			else
			{
				if(cnt[cur]==1)
				{
					val[cur]=a[i];
				}
				else
				{
					cur++;
					cnt[cur]=1;
					val[cur]=a[i];
				}
			}
		}
		if(cnt[cur]==1) cur--;
		bool flag=false;
		for(int i=1;i<=cur;i++) 
		{
			if(cnt[i]>=4)
			{
				printf("%d %d %d %d\n",val[i],val[i],val[i],val[i]);
				flag=true;
				break;
			}
		}
		if(flag) continue;
		int x=0,y=1;
		for(int i=2;i<=cur;i++)
		{
			if(x*val[i]<y*val[i-1])
			{
				x=val[i-1];
				y=val[i];
			}
		}
		printf("%d %d %d %d\n",x,x,y,y);
	}
	return 0;
}
