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

const int Maxn=1e5+5;

int n,k,l;
int a[Maxn];
ll ans=0;

int main()
{
	scanf("%d%d%d",&n,&k,&l);
	int m=n*k;
	for(int i=1;i<=m;i++) scanf("%d",a+i);
	sort(a+1,a+m+1);
	ans+=a[1];
	n--;
	for(int i=m;i>1&&n;i--)
	{
		if(a[i]-a[1]<=l&&i<=n*k+1)
		{
			ans+=a[i];
			n--;
		}
	}
	if(n) printf("0\n");
	else printf("%lld\n",ans);
	return 0;
}
