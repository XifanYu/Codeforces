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

const int Maxn=100005;

int n,q;

int pa[20][Maxn];
bool type[20][Maxn][2];
vector<int> adj[Maxn],root;
int ra[Maxn];
int ro[Maxn]; 

void dfs(int now){
	for(int i=1;i<20;i++){
		pa[i][now]=pa[i-1][pa[i-1][now]];
		for(int j=0;j<2;j++) type[i][now][j]=type[i-1][pa[i-1][now]][j]|type[i-1][now][j];
	}
	for(auto next:adj[now]){
		ra[next]=ra[now]+1;
		ro[next]=ro[now];
		dfs(next);
	}
}

bool query1(int a,int b){
	if(a==b) return false;
	if(ro[a]!=ro[b]) return false;
	while(ra[b]>ra[a]){
		int i=0;
		while(i<20&&ra[pa[i][b]]>=ra[a]) i++;
		i--;
		if(type[i][b][1]) return false;
		b=pa[i][b];
	}
	if(a==b) return true;
return false;
}

bool query2(int a,int b){
	if(a==b) return false;
	if(ro[a]!=ro[b]) return false;
	if(query1(b,a)) return false;
	while(ra[b]>ra[a]){
		int i=0;
		while(i<20&&ra[pa[i][b]]>=ra[a]) i++;
		i--;
		if(type[i][b][0]) return false;
		b=pa[i][b];
	}
	while(ra[a]>ra[b]){
		int i=0;
		while(i<20&&ra[pa[i][a]]>=ra[b]) i++;
		i--;
		if(type[i][a][1]) return false;
		a=pa[i][a];
	}
	if(a==b) return true;
	while(a!=b){
		int i=0;
		while(i<20&&pa[i][a]!=pa[i][b]) i++;
		if(i==20) return false;
		i--;
		if(i==-1) {
			if(type[0][a][1]) return false;
			if(type[0][b][0]) return false;
			return true;
		}
		if(type[i][a][1]) return false;
		if(type[i][b][0]) return false;
		a=pa[i][a];
		b=pa[i][b];
	}
}

int main(){
	memset(pa,-1,sizeof pa);
	memset(type,0,sizeof type);
	memset(ra,0,sizeof ra);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int p,t;
		scanf("%d%d",&p,&t);
		if(p==-1) {
			pa[0][i]=i;
			root.push_back(i);
			ro[i]=i;
		}
		else{
			adj[p].push_back(i);
			pa[0][i]=p;
			type[0][i][t]=true;
		}
	}
	for(auto r:root) dfs(r);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int t,u,v;
		scanf("%d%d%d",&t,&u,&v);
		if(t==1){
			bool ok=query1(u,v);
			if(ok) printf("YES\n");
			else printf("NO\n");
		}
		else{
			bool ok=query2(u,v);
			if(ok) printf("YES\n");
			else printf("NO\n");
		}
	}
return 0;
}
