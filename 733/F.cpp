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

#define lc p*2+1
#define rc p*2+2

typedef long long ll;
typedef pair<int,int> pi;

const int Maxn=200005; 
const int INF=1e9+5;

class edge{
	public:
		int w,c,id;
		int x,y;
};

bool cmp(edge e1,edge e2){
	return e1.w<e2.w;
}

edge e[Maxn];
int h[Maxn];
vector<pi> adj[Maxn];
bool used[Maxn];
int maxf[Maxn][20];
int f[Maxn][20];
int dep[Maxn];

int n,m,s;
ll rans,ans;
int minc=INF,mine,e_del=-1;

int find(int x){return h[x]==x?x:h[x]=find(h[x]);}

void dfs(int now,int pre,int fr){
	dep[now]=dep[pre]+1;
	if(now!=1){
		f[now][0]=pre;
		maxf[now][0]=fr;
		int i=0;
		while(f[f[now][i]][i]!=0){
			f[now][i+1]=f[f[now][i]][i];
			if(e[maxf[now][i]].w>e[maxf[f[now][i]][i]].w) maxf[now][i+1]=maxf[now][i];
			else maxf[now][i+1]=maxf[f[now][i]][i];
			i++;
		}
	}
	for(auto v:adj[now]){
		int nex=v.first,ed=v.second;
		if(nex==pre) continue;
		dfs(nex,now,ed);
	}
}

void krusk(){
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) h[i]=i;
	for(int i=1;i<=m;i++){
		if(find(e[i].x)==find(e[i].y)) continue;
		h[find(e[i].x)]=find(e[i].y);
		used[i]=true;
		rans+=e[i].w;
		if(minc>e[i].c){
			minc=e[i].c;
			mine=i;
		}
		adj[e[i].x].push_back(pi(e[i].y,i));
		adj[e[i].y].push_back(pi(e[i].x,i));
	}
	ans=rans-s/minc;
}

void init(){
	memset(f,0,sizeof f);
	e[0].w=0;
	dep[0]=0;
	dfs(1,0,0);
}

int query(int a,int b){
	if(dep[a]<dep[b]) return query(b,a);
	if(dep[a]==dep[b]){
		if(a==b) return 0;
		if(f[a][0]==f[b][0]){
			if(e[maxf[a][0]].w>e[maxf[b][0]].w) return maxf[a][0];
			else return maxf[b][0];
		}
		int i=0;
		while(f[a][i]!=0&&f[a][i]!=f[b][i]){
			i++;
		}
		i--;
		int d=query(f[a][i],f[b][i]);
		int w1=e[maxf[a][i]].w,w2=e[maxf[b][i]].w,w3=e[d].w;
		if(w1>=max(w2,w3)) return maxf[a][i];
		if(w2>w3) return maxf[b][i];
		return d;
	}
	int i=0;
	while(f[a][i]!=0&&dep[f[a][i]]>=dep[b]){
		i++;
	}
	i--;
	int d=query(f[a][i],b);
	if(e[d].w>e[maxf[a][i]].w) return d;
	else return maxf[a][i];
}

void calc(int i){
	if(e[i].c>=minc) return;
	int x=e[i].x,y=e[i].y;
	int d=query(x,y);
	ll nans=rans-e[d].w+e[i].w-s/e[i].c;
	if(ans>nans){
		e_del=d;
		mine=i;
		ans=nans;
	}
	
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&(e[i].w));
		e[i].id=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&(e[i].c));
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&(e[i].x),&(e[i].y));
	}
	scanf("%d",&s);
	krusk();
	init();
	for(int i=1;i<=m;i++){
		if(used[i]) continue;
		calc(i);
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=m;i++){
		if(i==mine){
			printf("%d %I64d\n",e[i].id,(ll)e[i].w-s/e[i].c);
		}
		else if(!used[i]||i==e_del) continue;
		else{
			printf("%d %d\n",e[i].id,e[i].w);
		}
	}
return 0;
}
