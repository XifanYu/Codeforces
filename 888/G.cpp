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
#define lc p*2+1
#define rc p*2+2
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

const int INF=1<<30;
const int Maxn=2e5+5;
const int M=30;

int n;
int a[Maxn];
int nex[Maxn*M][2],sz[Maxn*M],id[Maxn*M],now,cnt=2;
int pa[Maxn];
vector<int> root[M];
vector<int> sub[Maxn];
ll ans=0;

int find(int x){
	return (pa[x]==x)?x:pa[x]=find(pa[x]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++)
	{
		pa[i]=i;
		sub[i].PB(i);
		root[0].PB(i);
		now=1;
		sz[now]++;
		for(int j=M-1;j>=0;j--)
		{
			int d=(a[i]>>j)&1;
			if(!nex[now][d])
			{
				nex[now][d]=cnt++;
			}
			now=nex[now][d];
			sz[now]++;
		}
		id[now]=i;
	}
	int it=0;
	while(true){
		for(auto i:root[it])
		{
			if(find(i)!=i) continue;
			int cur=INF,node;
			for(auto v:sub[i])
			{
				now=1;
				sz[now]--;
				for(int j=M-1;j>=0;j--)
				{
					now=nex[now][(a[v]>>j)&1];
					sz[now]--;
				}
			}
			if(sz[1]==0)
			{
				printf("%lld\n",ans);
				exit(0);
			}
			for(auto v:sub[i])
			{
				now=1;
				for(int j=M-1;j>=0;j--)
				{
					int d=(a[v]>>j)&1;
					if(sz[nex[now][d]])
					{
						now=nex[now][d];
					}
					else
					{
						now=nex[now][1-d];
					}
				}
				int cd=id[now];
				if((a[cd]^a[v])<cur)
				{
					cur=(a[cd]^a[v]);
					node=cd;
				}
			}
			for(auto v:sub[i])
			{
				now=1;
				sz[now]++;
				for(int j=M-1;j>=0;j--)
				{
					now=nex[now][(a[v]>>j)&1];
					sz[now]++;
				}
			}
			ans+=cur;
			node=find(node);
			if(sub[node].size()<sub[i].size())
			{
				for(auto v:sub[node])
				{
					sub[i].PB(v);
				}
				pa[node]=i;
			}
			else
			{
				for(auto v:sub[i])
				{
					sub[node].PB(v);
				}
				pa[i]=node;
			}
		}
		it++;
		for(auto i:root[it-1])
		{
			if(find(i)==i) root[it].PB(i);
		}
	}
return 0;
}
