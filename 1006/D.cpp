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
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()
#define clean(v,a) memset(v,a,sizeof(v))

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
char a[Maxn],b[Maxn];
int ans=0;

int main()
{
	scanf("%d",&n);
	scanf("%s%s",a+1,b+1);
	for(int l=1,r=n;l<=r;l++,r--)
	{
		if(l!=r)
		{
			if(b[l]==b[r])
			{
				if(a[l]!=a[r]) ans++;
			}
			else
			{
				if((a[l]==b[l]||a[l]==b[r])&&(a[r]==b[l]||a[r]==b[r]))
				{
					if(a[l]==a[r]) ans++;
				}
				else if((a[l]==b[l]||a[l]==b[r])||(a[r]==b[l]||a[r]==b[r]))
				{
					ans++;
				}
				else
				{
					ans+=2;
				}
			}
		}
		else
		{
			if(a[l]!=b[l]) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
