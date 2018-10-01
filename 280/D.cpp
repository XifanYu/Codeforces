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
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
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

const int Maxn=1<<17;
const int K=20;
const int INF=1<<29;

int n,m,t;
int pos,val;
int l,r,k;
int a[Maxn];
int MN=1;

class seg
{
	public:
		int mx[4][21]; //0 for no restriction, 1 for left inclusive, 2 for right inclusive, 3 for left-right inclusive
		void init()
		{
			memset(mx,0x87,sizeof mx);
			mx[0][0]=0;
		}
		void set(int x)
		{
			int v=max(0,x); 
			rep(i,20)
			{
				mx[0][i]=v;
				mx[1][i]=mx[2][i]=mx[3][i]=x;
			}
			
		}
};

class segTree
{
	public:
		seg t[Maxn<<1];
		void init()
		{
			while(MN<n) MN<<=1;
			rep0(i,(MN<<1))
			{
				t[i].init();
			}
		}
		seg merge(seg t1,seg t2,int k)
		{
			seg t;
			t.init();
			for(int i=1;i<=k;i++)
			{
				for(int l=0,r=i;l<=i;l++,r--)
				{
					t.mx[0][i]=max(t.mx[0][i],t1.mx[0][l]+t2.mx[0][r]);
					t.mx[1][i]=max(t.mx[1][i],t1.mx[1][l]+t2.mx[0][r]);
					t.mx[2][i]=max(t.mx[2][i],t1.mx[0][l]+t2.mx[2][r]);
					t.mx[3][i]=max(t.mx[3][i],t1.mx[1][l]+t2.mx[2][r]);
				}
				for(int l=1,r=i;l<=i;l++,r--)
				{
					t.mx[0][i]=max(t.mx[0][i],t1.mx[2][l]+t2.mx[1][r]);
					t.mx[1][i]=max(t.mx[1][i],t1.mx[3][l]+t2.mx[1][r]);
					t.mx[2][i]=max(t.mx[2][i],t1.mx[2][l]+t2.mx[3][r]);
					t.mx[3][i]=max(t.mx[3][i],t1.mx[3][l]+t2.mx[3][r]);
				}
			}
			return t;
		} 
		void pushup(int p)
		{
			t[p]=merge(t[lc],t[rc],K);
			if(p) pushup((p-1)>>1);
		}
		void update(int i,int v,int p=0,int l=1,int r=MN)
		{
			if(l==r)
			{
				t[p].set(v);
				pushup((p-1)>>1);
				return;
			}
			int m=(l+r)>>1;
			if(i<=m) 
			{
				update(i,v,lc,l,m);
			}
			else
			{
				update(i,v,rc,m+1,r);
			}
		}
		seg query(int a,int b,int k,int p=0,int l=1,int r=MN)
		{
			if(a<=l&&r<=b)
			{
				return t[p];
			}
			int m=(l+r)>>1;
			seg now;
			if(a<=m)
			{
				now=query(a,b,k,lc,l,m);
				if(b>m)
				{
					now=merge(now,query(a,b,k,rc,m+1,r),k);
				}
			}
			else
			{
				now=query(a,b,k,rc,m+1,r);
			}
			return now;
		}
};

segTree st;



int main()
{
	scanf("%d",&n);
	st.init();
	rep(i,n) 
	{
		scanf("%d",a+i);
		st.update(i,a[i]);
	}
	scanf("%d",&m);
	rep(i,m)
	{
		scanf("%d",&t);
		if(t)
		{
			scanf("%d%d%d",&l,&r,&k);
			seg ans=st.query(l,r,k);
			printf("%d\n",ans.mx[0][k]);
		}
		else
		{
			scanf("%d%d",&pos,&val);
			st.update(pos,val);
		}
	}
	
	return 0;
}
