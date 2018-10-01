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

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=1e3+5;

int n,a,b;
bool e[Maxn][Maxn];

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	if(min(a,b)>1||(a==b&&b==1&&(n==2||n==3)))
	{
		printf("NO\n");
		return 0;
	}
	if(b==1)
	{
		memset(e,false,sizeof e);
		for(int i=a;i<n;i++)
		{
			e[i][i+1]=e[i+1][i]=true;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) 
			{
				if(e[i][j]) putchar('1');
				else putchar('0');
			}
			putchar('\n');
		}
		return 0;	
	}
	if(a==1)
	{
		memset(e,true,sizeof e);
		for(int i=1;i<=n;i++) e[i][i]=false;
		for(int i=b;i<n;i++)
		{
			e[i][i+1]=e[i+1][i]=false;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) 
			{
				if(e[i][j]) putchar('1');
				else putchar('0');
			}
			putchar('\n');
		}
		return 0;
	}
	return 0;
}
