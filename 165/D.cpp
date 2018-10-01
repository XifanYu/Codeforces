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
#define FS first
#define SC second
#define LB lower_bound
#define PB push_back
#define lc p*2+1
#define rc p*2+2

typedef long long ll;
typedef pair<int,int> pi; 

const int Maxn=1e5+5;

class edge{
	public:
		int u,v;
		int to(int x){
			if(x==u) return v;
			return u;
		}
};

int n,m;
int t,a,b;
int deg[Maxn];
edge edg[Maxn];
int ed[Maxn];
pi bran[Maxn];
int cnt=0,pos;
vector<int> adj[Maxn];
vector<int> bit[Maxn];
int sz[Maxn];

void dfs(int now,int pre){
	bit[cnt].PB(0);
	sz[cnt]++;
	bran[now]=MP(cnt,pos++);
	for(auto v:adj[now]){
		int x=edg[v].to(now);
		if(x!=pre) {
			ed[v]=x;
			dfs(x,now);
		}
	}
}

void update(pi p,int f){
	while(p.SC<=sz[p.FS]){
		bit[p.FS][p.SC]+=f;
		p.SC+=(p.SC)&(-p.SC);
	}
}

int calc(int id,int x){
	int rez=0;
	while(x>0){
		rez+=bit[id][x];
		x-=x&(-x);
	}
	return rez;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&edg[i].u,&edg[i].v);
		adj[edg[i].u].PB(i);
		adj[edg[i].v].PB(i);
		deg[edg[i].u]++;
		deg[edg[i].v]++;
	}
	int maxd=0,root=0;
	for(int i=1;i<=n;i++){
		if(deg[i]>maxd){
			maxd=deg[i];
			root=i;
		}
		bit[i].PB(0);
	}
	for(auto v:adj[root]){
		pos=1;
		cnt++;
		int x=edg[v].to(root);
		ed[v]=x;
		dfs(x,root);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&a);
			update(bran[ed[a]],-1);
		}
		else if(t==2){
			scanf("%d",&a);
			update(bran[ed[a]],1);
		}
		else{
			scanf("%d%d",&a,&b);
			int id1=bran[a].FS,id2=bran[b].FS;
			int x1=bran[a].SC,x2=bran[b].SC;
			int w1=calc(id1,x1),w2=calc(id2,x2);
			if(id1==id2){
				if(w1==w2){
					printf("%d\n",(x1<x2)?x2-x1:x1-x2);
				}
				else{
					printf("-1\n");
				}
			}
			else{
				if(w1==0&&w2==0){
					printf("%d\n",x1+x2);
				}
				else{
					printf("-1\n");
				}
			}
		}
	}
return 0;
}
