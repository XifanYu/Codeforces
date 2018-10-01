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
using namespace std;

const int Maxn=1e5+5;

int n,m;

vector<int> pre[Maxn];
int deg[Maxn];
int lab[Maxn],id;

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		pre[v].push_back(u);
		deg[u]++;
	}
	priority_queue<int,vector<int>,less<int> > pq;
	for(int i=1;i<=n;i++){
		if(deg[i]==0) pq.push(i);
	}
	id=n;
	while(id){
		int k=pq.top();
		pq.pop();
		lab[k]=id--;
		for(auto v:pre[k]){
			deg[v]--;
			if(deg[v]==0) pq.push(v);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",lab[i]);
	}
return 0;
}
