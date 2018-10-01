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
typedef long double db; 

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=2e5+5;
const db PI=3.1415926535897932384;
const db C=PI*2;

class pnt
{
public:
	db ang;
	int id;
	void read()
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ang=atan2(y,x);
	}
	bool operator<(const pnt&o)const
	{
		return ang<o.ang;
	}
};

int n;
pnt p[Maxn];


int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		p[i].id=i;
		p[i].read();
	}
	for(int i=n+1;i<=2*n;i++)
	{
		p[i].id=i-n;
		p[i].ang=p[i-n].ang+C;
	}
	sort(p+1,p+2*n+1);
	db last=2*C;
	int c1,c2;
	for(int i=1;i<2*n;i++)
	{
		db now=p[i+1].ang-p[i].ang;
		if(now<last)
		{
			last=now;
			c1=p[i].id;
			c2=p[i+1].id;
		}
	}
	printf("%d %d\n",c1,c2);
	return 0;
}
