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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define clean(v,a) memset(v,a,sizeof(v))
#define get(a) scanf("%d",&a)
#define get2(a,b) scanf("%d%d",&a,&b)
#define get3(a,b,c) scanf("%d%d%d",&a,&b,&c)

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

int n,m;
int a[105],b[105];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=m;i++) scanf("%d",b+i);
	int sum=0;
	for(int i=1;i<=n;i++) sum=(sum^a[i]);
	for(int i=1;i<=m;i++) sum=(sum^b[i]);
	if(sum)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
	{
		if(i!=n)
		{
			for(int j=1;j<m;j++) printf("0 ");
			printf("%d\n",a[i]);
		}
		else
		{
			int last=a[n];
			for(int j=1;j<m;j++) 
			{
				printf("%d ",b[j]);
				last=(last^b[j]);
			}
			printf("%d\n",last);
		}
	}
	return 0;
}
