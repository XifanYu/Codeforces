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

typedef long long ll;
typedef pair<int,int> pi; 

const int Maxn=505;

int n,m,u,v; 
vector<int> adj[Maxn];
bool pass[Maxn][Maxn];
int mark[Maxn],back[Maxn];
vector<int> loop;
bool cycle=false;

void setcycle(int v,int u){
	while(v!=u){
		loop.push_back(v);
		v=back[v];
	}
	loop.push_back(u);
	cycle=true;
}

void dfs(int u){
	if(cycle) return;
	mark[u]=1;
	for(auto v:adj[u]){
		if(pass[u][v]) continue;
		if(mark[v]==0){
			back[v]=u;
			dfs(v);
		}
		else if(mark[v]==1){
			if(loop.size()==0)setcycle(u,v);
			else cycle=true;
		}
	}
	mark[u]=2;
}

void findcycle(){
	for(int i=1;i<=n;i++){
		if(mark[i]==0) dfs(i);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
	}
	memset(mark,0,sizeof mark);
	memset(pass,0,sizeof pass);
	findcycle();
	if(cycle==false){
		printf("YES\n");
		return 0;
	}
	int sz=loop.size();
	for(int i=0;i<sz;i++){
		pass[loop[(i+1)%sz]][loop[i]]=1;
		cycle=false;
		memset(mark,0,sizeof mark);
		findcycle();
		if(cycle==false) {
			printf("YES\n");
			return 0;
		}
		pass[loop[(i+1)%sz]][loop[i]]=0;
	}
	printf("NO\n");
return 0;
}
