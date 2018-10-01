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

const int Maxn=1e3+5;

int n,m,q;
char s[Maxn],t[Maxn];
int sum[Maxn];

void process()
{
	sum[0]=0;
	for(int i=1;i<=n-m+1;i++)
	{
		bool flag=true;
		sum[i]=sum[i-1];
		for(int j=1;j<=m;j++)
		{
			if(s[i+j-1]!=t[j])
			{
				flag=false;
				break;
			}
		}
		if(flag) sum[i]++;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s",s+1);
	scanf("%s",t+1);
	process();
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(r-l+1>=m)
		{
			printf("%d\n",sum[r-m+1]-sum[l-1]);
		}
		else printf("0\n");
	}
	return 0;
}
