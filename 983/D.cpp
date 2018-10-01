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
typedef pair<ll,ll> pl; 
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
#define PQ priority_queue

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=1<<17;
const int inf=0x3f3f3f3f;

class seg
{
public:
	int cur;	//current x position
	int t;		//t==0 for insert, t==1 for erase
	int color;	//segment's color
	int l,r;	//cur lower y position, higher y position
	seg(int CUR=-1,int T=-1,int COLOR=-1,int L=-1,int R=-1)
	{
		cur=CUR;t=T;color=COLOR;l=L;r=R;
	}
	bool operator<(const seg & o)const
	{
		if(cur<o.cur) return true;
		if(cur>o.cur) return false;
		if(t<o.t) return true; 			//at the same position, insert before erase
		if(t>o.t) return false;
		if(t==0) return color>o.color;	//when inserting, insert from largest color to smallest color
		if(t==1) return color<o.color;	//when erasing, erase from smallest color to largest color
	}	
};

class node
{
public:
	int max_unmarked; 	//the maximum color of the visible segments that haven't been added to our answer
	int min_color;    	//the minimum color of the segments that can be seen at current node(from this node 
						//all the way down to the bottom of our segtree), which  is to say, all the colors 
						//from 0 to min_color - 1 will not be seen (blocked from sight) at current node
	set<int> colors;    //the colors of the segments that are currently inside the range of this node
	node()
	{
		max_unmarked=-1;
		min_color=-1;
		colors.clear();
	}
	void insert(int x) {colors.insert(x);}
	void erase(int x) {colors.erase(x);}
};

int n;
vector<int> y;
bool mark[Maxn];
seg sg[Maxn<<1];
node tr[Maxn<<2];
int MN;

void input()
{
	scanf("%d",&n);
	y.PB(-inf);y.PB(inf);
	sg[0]=seg(-inf,1,0,-inf,inf);
	sg[1]=seg(inf,0,0,-inf,inf);
	for(int i=1;i<=n;i++)
	{
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		y.PB(y1);y.PB(y2);
		sg[(i<<1)]=seg(x1,0,i,y1,y2);
		sg[(i<<1)|1]=seg(x2,1,i,y1,y2);
	}
	sort(all(y));
	y.resize(unique(all(y))-y.begin());
	MN=y.size();
	sort(sg,sg+(n<<1)+2);
}

void recalc(int p,int l,int r) //recalculate max_unmarked for a specific node
{
	tr[p].min_color=-1;
	tr[p].max_unmarked=-1;
	if(r-l>1)
	{
		int mi=(l+r)>>1;
		if(tr[lc].max_unmarked!=-1&&mark[tr[lc].max_unmarked]) recalc(lc,l,mi); //left son needs recalc
		if(tr[rc].max_unmarked!=-1&&mark[tr[rc].max_unmarked]) recalc(rc,mi,r); //right son needs recalc
		tr[p].min_color=min(tr[lc].min_color,tr[rc].min_color);
		tr[p].max_unmarked=max(tr[lc].max_unmarked,tr[rc].max_unmarked);
	}
	if(!tr[p].colors.empty())
	{
		int top=*(tr[p].colors.rbegin());
		tr[p].min_color=max(tr[p].min_color,top); //if top will cover the minimum visible color in the subtree, update min_color
		if(tr[p].max_unmarked<top) //if top will cover up the max_unmarked in p's subtree
		{
			if(!mark[top]&&top==tr[p].min_color) //top hasn't been marked and it can be seen at the current node
			{
				tr[p].max_unmarked=top;
			}
			else  tr[p].max_unmarked=-1;
		}
	}
}

void update(int c,int t,int a,int b,int p,int l,int r)
{
	if(a>=y[r]||b<=y[l]) return;
	if(a<=y[l]&&b>=y[r])
	{
		if(t==0) tr[p].insert(c);
		else tr[p].erase(c);
		recalc(p,l,r);
		return;
	}
	int mi=(l+r)>>1;
	update(c,t,a,b,lc,l,mi);
	update(c,t,a,b,rc,mi,r);
	recalc(p,l,r);
}

void update(int c,int t,int a,int b)
{
	update(c,t,a,b,0,0,MN-1);
	while(tr[0].max_unmarked!=-1) //while there is some visible color, mark and recalc
	{
		mark[tr[0].max_unmarked]=true;
		recalc(0,0,MN-1);
	}
}

void solve()
{
	for(int i=0;i<(n<<1)+2;i++)
	{
		update(sg[i].color,sg[i].t,sg[i].l,sg[i].r);
	}
	int ans=0;
	for(int i=0;i<=n;i++) if(mark[i]) ans++;
	printf("%d\n",ans);
}

int main()
{
	input();
	solve();
	return 0;
}
