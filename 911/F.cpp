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

const int Maxn=200005;

int n;
vector<int> adj[Maxn];
int dist[Maxn];
int pred[Maxn];
ll ans;
int maxd,s1,s2;
vector<pi> pts;
int a,b;


void dfs(int now,int pre){
	for(auto v:adj[now]){
		if(v!=pre) {
			dist[v]=dist[now]+1;
			dfs(v,now);
		}
	}
}

void bfs(int p){
	queue<int> q;
	q.push(p);
	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(auto v:adj[f]){
			if(v!=pred[f]){
				q.push(v);
				dist[v]=dist[f]+1;
				pred[v]=f;
			}
		}
	}
}

void cut(int now,int pre,int node){
	for(auto v:adj[now]){
		if(v!=pre) cut(v,now,node);
	}
	if(dist[s2]>2*dist[node]){
		ans+=(ll)dist[s2]+dist[now]-2*dist[node];
		pts.push_back(pi(s2,now));
	}
	else{
		ans+=(ll)dist[now];
		pts.push_back(pi(s1,now));
	}
}

void deletB(int now,int past){
	for(auto v:adj[now]){
		if(v!=past&&v!=pred[now]){
			cut(v,now,now);
		}
	}
	if(pred[now]!=s1) deletB(pred[now],now);
}

void deletR(int now){
	if(now==s1) return;
	ans+=(ll)dist[now];
	pts.push_back(pi(s1,now));
	deletR(pred[now]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dist[1]=0;
	dfs(1,0);
	maxd=0;
	for(int i=1;i<=n;i++){
		if(maxd<dist[i]){
			maxd=dist[i];
			s1=i;
		}
	}
	dist[s1]=0;
	bfs(s1);
	maxd=0;
	for(int i=1;i<=n;i++){
		if(maxd<dist[i]){
			maxd=dist[i];
			s2=i;
		}
	}
	deletB(s2,0);
	deletR(s2);
	printf("%I64d\n",ans);
	for(int i=0;i<pts.size();i++){
		a=pts[i].first,b=pts[i].second;
		printf("%d %d %d\n",a,b,b);
	}
return 0;
}
