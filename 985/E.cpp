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

const int Maxn=5e5+5;

int n,k,d;
int a[Maxn];
bool t[1<<20];
bool dp[Maxn];

void pushup(int p)
{
	t[p]=t[lc]||t[rc];
	if(p) pushup((p-1)/2);
	return;
}

void update(int pos,bool val,int p=0,int l=0,int r=(1<<19)-1)
{
	if(l==r)
	{
		t[p]=val;
		pushup((p-1)/2);
		return;
	}
	int mi=(l+r)>>1;
	if(pos<=mi) update(pos,val,lc,l,mi);
	else update(pos,val,rc,mi+1,r);
}

bool query(int a,int b,int p=0,int l=0,int r=(1<<19)-1)
{
	if(a<=l&&r<=b) return t[p];
	int mi=(l+r)>>1;
	bool rez=0;
	if(mi>=a) rez=rez||query(a,b,lc,l,mi);
	if(mi<b) rez=rez||query(a,b,rc,mi+1,r);
	return rez;
}

int main()
{
	memset(t,0,sizeof t);
	memset(dp,0,sizeof dp);
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	update(0,true);
	for(int i=1;i<=n;i++)
	{
		int lb=LB(a+1,a+n+1,a[i]-d)-a;
		int a=lb-1,b=i-k;
		if(a<=b) 
		{
			dp[i]=query(a,b);
			update(i,dp[i]);
		}
	}
	if(dp[n]) printf("YES\n");
	else printf("NO\n");
	return 0;
}
