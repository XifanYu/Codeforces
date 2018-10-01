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
#define UB upper_bound
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
typedef double db; 

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=5005;

int dp1[Maxn][Maxn];//exact value from l to r
int dp2[Maxn][Maxn];//maximum subsegment from l to r
int n,q;
int a[Maxn];

int main()
{
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i);
	rep(i,n) dp1[i][i]=dp2[i][i]=a[i];
	for(int len=1;len<n;len++)
	{
		int j=n-len;
		for(int i=1;i<=j;i++)
		{
			dp1[i][i+len]=(dp1[i][i+len-1]^dp1[i+1][i+len]);
		}
	}
	for(int len=1;len<n;len++)
	{
		int j=n-len;
		for(int i=1;i<=j;i++)
		{
			dp2[i][i+len]=max(dp2[i][i+len-1],dp2[i+1][i+len]);
			dp2[i][i+len]=max(dp2[i][i+len],dp1[i][i+len]);
		}
	}
	scanf("%d",&q);
	rep(i,q)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",dp2[l][r]);
	}
	return 0;
}
