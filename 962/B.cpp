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

const int Maxn=2e5+5;

int n,a,b;
char s[Maxn];
vector<int> seg[2];
bool flag;
int id0=0,id1=0;
int ans;

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",s+1);
	int id=1,cnt=0;
	while(id<=n)
	{
		while(id<=n&&s[id]=='.') 
		{
			id++;
			cnt++;
		}
		seg[cnt%2].PB(cnt);
		cnt=0;
		id++;
	}
	sort(seg[0].begin(),seg[0].end());
	sort(seg[1].begin(),seg[1].end());
	while(id0<seg[0].size()||id1<seg[1].size())
	{
		if(id0<seg[0].size())
		{
			int d=seg[0][id0];
			int da=min(a,d/2),db=min(b,d/2);
			a-=da;
			b-=db;
			ans+=da+db;
			id0++;
		}
		else
		{
			if(a<b)
			{
				int d=seg[1][id1];
				int da=min(a,d/2),db=min(b,(d+1)/2);
				a-=da;
				b-=db;
				ans+=da+db;
				id1++;	
			}
			else
			{
				int d=seg[1][id1];
				int da=min(a,(d+1)/2),db=min(b,d/2);
				a-=da;
				b-=db;
				ans+=da+db;
				id1++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
