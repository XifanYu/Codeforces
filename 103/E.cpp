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

const int INF=1e9+5;
const int Maxn=305;
const int S=0;
const int T=301;

int n,m;
vector<int> ss[Maxn];
int value[Maxn];
int match[Maxn<<1];
bool used[Maxn<<1];
vector<int> adj1[Maxn<<1];
vector<int> adj2[Maxn];
int dist[Maxn];
int capa[Maxn][Maxn];
int ans=0;

bool dfs1(int now){
	used[now]=true;
	for(auto v:adj1[now]){
		int w=match[v];
		if(w==0||!used[w]&&dfs1(w)){
			match[now]=v;
			match[v]=now;
			return true;
		}
	}
	return false;
} 

void perfect(){
	memset(match,0,sizeof match);
	for(int i=1;i<=n;i++){
		if(match[i]==0){
			memset(used,0,sizeof used);
			dfs1(i);
		}
	}
}

bool bfs(){
	memset(dist,-1,sizeof dist);
	queue<int> q;
	int x;
	q.push(S);
	dist[S]=0;
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(auto v:adj2[x]){
			if(dist[v]==-1&&capa[x][v]>0){
				q.push(v);
				dist[v]=dist[x]+1;
			}
		}
	}
	return dist[T]>0; 
}

int dfs(int now,int f){
	if(now==T) return f;
	int w=0;
	for(auto v:adj2[now]){
		if(dist[v]==dist[now]+1&&capa[now][v]>0){
			w=dfs(v,min(f,capa[now][v]));
			if(w!=0){
				capa[now][v]-=w;
				capa[v][now]+=w;
				return w;
			}
		}
	}
	return 0;
}

void build(){
	memset(capa,0,sizeof capa);
	for(int i=1;i<=n;i++){
		if(value[i]<0){
			adj2[S].push_back(i);
			adj2[i].push_back(S);
			capa[S][i]+=-value[i];
		}
		else{
			adj2[i].push_back(T);
			adj2[T].push_back(i);
			capa[i][T]+=value[i];
		}
		for(auto v:adj1[i]){
			adj2[i].push_back(match[v]);
			adj2[match[v]].push_back(i);
			capa[i][match[v]]+=INF;
		}
	}
}

void calc(){
	int flow=0;
	while(bfs()){
		flow+=dfs(S, INF);
	}
	ans-=flow;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		ss[i].resize(m);
		for(int j=0;j<m;j++){
			scanf("%d",ss[i].begin()+j);
			adj1[i].push_back(ss[i][j]+Maxn);
			adj1[ss[i][j]+Maxn].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)scanf("%d",value+i);
	for(int i=1;i<=n;i++){
		if(value[i]<0)ans-=value[i];
	}
	perfect();
	build();
	calc();
	printf("%d\n",-ans);
return 0;
}
