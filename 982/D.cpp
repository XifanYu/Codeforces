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

const int Maxn=(1<<17);
const int INF=1e9+5;

int n;
int a[Maxn];
pi b[Maxn]; //(val,pos) after sorting
int id=0;
vector<int> pos[Maxn]; //postions of the same value stored together
int val[Maxn]; //value of the positions stored, i.e. pos[i] has value val[i]
set<pi> seg; //segment
multiset<int> len; //length


int main()
{
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i);
	rep(i,n)
	{
		b[i]=pi(a[i],i);
	}
	sort(b+1,b+n+1);
	val[id]=0;
	rep(i,n)
	{
		if(b[i].FF==val[id])
		{
			pos[id].PB(b[i].SS);
		}
		else
		{
			pos[++id].PB(b[i].SS);
			val[id]=b[i].FF;
		}
	}
	seg.insert(pi(n,1));
	len.insert(n-1);
	int k=val[id]+1,last=0,cnt=1;
	rrep(i,id)
	{
		for(auto v:pos[i])
		{
			set<pi>::iterator it1=seg.LB(pi(v,0));
			pi cur=*it1;
			seg.erase(it1);
			multiset<int>::iterator it2=len.LB(cur.FF-cur.SS);
			len.erase(it2);
			cnt--;
			if(cur.FF>v) 
			{
				seg.insert(pi(cur.FF,v+1));
				len.insert(cur.FF-v-1);
				cnt++;
			}
			if(cur.SS<v) 
			{
				seg.insert(pi(v-1,cur.SS));
				len.insert(v-1-cur.SS);
				cnt++;
			}
		}
		if(len.size()&&*len.begin()==*len.rbegin())
		{
			if(last<=cnt)
			{
				k=val[i-1]+1;
				last=cnt;
			}
		}
	}
	printf("%d\n",k);
	return 0;
}
