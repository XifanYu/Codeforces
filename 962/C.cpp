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
#define rep(n) for(int i=1;i<=n;i++)
#define rep0(n) for(int i=0;i<n;i++)
#define rrep(n) for(int i=n;i;i--)
#define rrep0(n) for(int i=n-1;i>=0;i--)
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

int n,l=0;
vector<int> d;
bool ok[15];

bool check(int k)
{
	if(k==0) return false;
	int d=sqrt(k);
	if(d*d==k) return true;
	return false;
}

void dfs(int pos,int v,int num)
{
	if(pos<0)
	{
		if(check(v)) ok[num]=true;
		return;
	}
	if(v!=0||d[pos]!=0)dfs(pos-1,v*10+d[pos],num-1);
	dfs(pos-1,v,num);
}

int main()
{
	scanf("%d",&n);
	memset(ok,false,sizeof ok);
	d.clear();
	while(n>0)
	{
		l++;
		int x=n%10;
		n/=10;
		d.PB(x);	
	}
	dfs(l-1,0,l);
	for(int i=0;i<l;i++)
	{
		if(ok[i])
		{
			printf("%d\n",i);
			exit(0);
		}
	}
	printf("-1\n");
	return 0;
}
